function Validator(formSelector){
    var _this= this
    function getParent(element,selector){
        while(element.parentElement){
            if(element.parentElement.matches(selector)){
                return element.parentElement
            }
            element=element.parentElement
        }
    }
    var formRules={}
    /**
     * Quy ước tạo rules
     * -Nếu có lỗi return error message
     * -Nếu không có lỗi thì reutrn undefined
    */ 
    var validatorRules={
        required:function(value){
            return value ? undefined :'Vui lòng nhập trường này'
        },
        email:function(value){
            var regex= /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
            return regex.test(value) ? undefined :'Vui lòng nhập trường này'
        },
        min:function(min){
            return function(value){
                return value.length >= min ? undefined:`Vui lòng nhập ít nhất ${min} ký tự`
            }
        },
        max:function(max){
            return function(value){
                return value.length <= max ? undefined:`Vui lòng nhập tối đa ${max} ký tự`
            }
        }
    }
    // Lấy ra form element trong DOM theo formSelector
    var formEle = document.querySelector(formSelector)
    // Chỉ sử lý khi có element trong DOM
    if(formEle){
    var inputs=formEle.querySelectorAll('[name][rules]')
    Array.from(inputs).forEach(function(input){
        var rules =input.getAttribute('rules').split('|')
        for(var rule of rules){
            var isRuleHasValue = rule.includes(':')
            var ruleInfo
            if(isRuleHasValue){
                ruleInfo= rule.split(':')
                rule=ruleInfo[0] // min
                //ruleInfo[1] (6)
            }
            var ruleFunc =validatorRules[rule]
            if(isRuleHasValue){
                ruleFunc=ruleFunc(ruleInfo[1])
            }
            if(Array.isArray(formRules[input.name])){
                formRules[input.name].push(ruleFunc)
            }
            else{
                formRules[input.name]=[ruleFunc]
            }
        }
        // Lắng nghe sự kiện dể validate(blur,change,input)
        input.onblur = handleValidate
        input.oninput = handleClearError
    })
    //Hàm thực hiện validate
    function handleValidate(event){
        var rules= formRules[event.target.name]
        var errorMessage
        for(var rule of rules){
            errorMessage=rule(event.target.value)
            if(errorMessage) break;
        }
        // Nếu có lỗi thì hiển thị message lỗi ra UI
        if(errorMessage){
            var formGroup= getParent(event.target,'.form-group')
            if(!formGroup) return
               var errorElement=formGroup.querySelector('.form-message')
               if(errorElement){
                 errorElement.innerText=errorMessage
                 getParent(event.target,'.form-group').classList.add('invalid')
            }  
    }
    return !errorMessage
    }
    // Hàm clear message lỗi
    function handleClearError(event){
        var formGroup= getParent(event.target,'.form-group') 
        if(formGroup.classList.contains('invalid')){
            getParent(event.target,'.form-group').classList.remove('invalid')
            var errorElement=formGroup.querySelector('.form-message')
            if(errorElement){
                errorElement.innerText=''
           }  
        }
    }

}

// Xử lý hành vi submit form
    formEle.onsubmit= function(event){
        event.preventDefault()
        // this keyword
        var inputs=formEle.querySelectorAll('[name][rules]')
        var isValid = true
        Array.from(inputs).forEach(function(input){
            if(!handleValidate({target:input})){
                isValid=false
            }
        })
        // Khi không có lỗi submitform
        if(isValid){
           if(typeof _this.onSubmit ==='function'){
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
            _this.onSubmit(formValues)
           }else{
            _this.submit()
           }
        }
    }
}