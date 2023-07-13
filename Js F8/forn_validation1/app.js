// đối tương Validator
function Validator(options){
    // Lấy element của form cần validate
    var formEle =document.querySelector(options.form)
    function getParent(element,selector){
        while(element.parentElement){
            if(element.parentElement.matches(selector)){
                return element.parentElement
            }
            element=element.parentElement
        }
    }
    var selectorRules = {}
    // Hàm thực hiện validate
    function validate(inputEle,rule){
        var errorElement =getParent(inputEle,options.formGroup).querySelector(options.errorSelector)
        // Lấy ra các rules của selector
        var rules =selectorRules[rule.selector]
        // Lặp qua tưng rule và ktr
        // Nếu có lỗi thì dừng việc kiểm tra
        var errorMessage ;
        for(var i = 0;i< rules.length;i++){
           switch(inputEle.type){
            case 'checkbox':
            case 'radio':
                errorMessage = rules[i](formEle.querySelector(rule.selector+':checked'))
                break;
            default:
                errorMessage = rules[i](inputEle.value)
           }
            if(errorMessage) break;
        }
                    if(errorMessage){
                        errorElement.innerText = errorMessage
                       getParent(inputEle,options.formGroup).classList.add('invalid')
                    }
                    else{
                        errorElement.innerText =''
                       getParent(inputEle,options.formGroup).classList.remove('invalid')
                    }
        return !errorMessage  //Khi có lỗi trả về false và ngc lại
    }
    
    if(formEle){
        formEle.onsubmit = function(e){
            e.preventDefault() //Loại bỏ hành động mặc định của nút submit
            var isFormValid = true
            // Lặp qua từng rules và validate
            options.rules.forEach(function(rule){
                var inputEle= formEle.querySelector(rule.selector)
                var isValid=validate(inputEle,rule)
                if(!isValid){ //ktr khi có lỗi 
                    isFormValid=false//Sẽ trả lại trạng thái của form là false
                }

            })
            
            if (isFormValid) {
                // Trường hợp submit với jvs
              if(typeof options.onSubmit ==='function')  {
                var enableInputs= formEle.querySelectorAll('[name]')
                var formValues= Array.from(enableInputs).reduce(function(values,input){
                    switch(input.type){
                        case'radio':
                        if(input.matches(':checked')){
                            values[input.name]= input.value
                        }
                        break;
                        case'checkbox':
                        if(!input.matches(':checked')) {
                            return values}
                        if(!Array.isArray(values[input.name])){
                            values[input.name]=[]
                        }
                        values[input.name].push(input.value)
                        break;
                        case'file':
                        values[input.name]=input.files
                        break;
                        default:
                            values[input.name]= input.value
                    }
                    return  values
                },{})
                options.onSubmit(formValues)
              }
              //Trường hợp submit với hành vi mặc định
              else{
                formEle.submit()
              }
            } 
        }
        // Lặp qua mỗi rule và xử lý (lắng nghe sự kiện blur,input)
        options.rules.forEach(function(rule){
            // Lưu lại các rules cho mỗi input
            if (Array.isArray(selectorRules[rule.selector])) {
                selectorRules[rule.selector].push(rule.test);
            }
            else{
                selectorRules[rule.selector]= [rule.test]
            }
            var inputEles= formEle.querySelectorAll(rule.selector)
            Array.from(inputEles).forEach(function(inputEle){
                if(inputEle){
                    //Xử lý trường hợp blur khỏi input
                   inputEle.onblur = function(){
                       // value:inputEle.value
                       // test func: rule.test
                       validate(inputEle,rule)
                   }
                   // Xử lý khi người dùng nhập vao input
                   inputEle.oninput= function(){
                       var errorElement =getParent(inputEle,options.formGroup).querySelector(options.errorSelector)
                       errorElement.innerText =''
                      getParent(inputEle,options.formGroup).classList.remove('invalid')
                   }
               }
            })
           
            

        })
        
    }
    
}



//Định nghĩa rules 
// Nguyên tắc của rule:
// 1. Khi có lỗi=> Trả ra message lỗi
// 2. Khi hợp lệ không trả ra gì cả
Validator.isRequired= function(selector,message){
    return {
        selector : selector,
        test:function(value){
            if(value){
                return undefined
            }
            else{return message|| 'Vui lòng nhập lại'}
        }, 
    }
}
Validator.isEmail= function(selector,message){
return {
        selector : selector,
        test:function(value){
            var regex= /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
            if(regex.test(value)){
                return undefined
            }
            else{return message||'Trường này phải là email'}
        }, 
    }
}
Validator.minLength= function (selector,min,message){
    return {
        selector : selector,
        test:function(value){
            if(value.length >=min){
                return undefined
            }
            else{return message||`Vui lòng nhâp tối thiểu ${min} kí tự`}
        }, 
    }
}   
Validator.isConfirmed =function(selector,getConfirmValue,message){
    return {
        selector : selector,
        test:function(value){
           return value=== getConfirmValue()? undefined:message||'Giá trị nhập vào không chính xác'
        }, 
    }
}