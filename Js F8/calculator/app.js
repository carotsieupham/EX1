let runningTotal=0;
let numberOnScreen="0";
let previousOperator;
const screen=document.querySelector('.screen')
function buttonClick(value){

    if(isNaN(value)){
        handleSymbol(value)
    }
    else{
        handleNumber(value)
    }
    screen.innerText=numberOnScreen;
}
function handleSymbol(symbol){
    switch (symbol) {
        case "C":
            numberOnScreen="0"
            runningTotal=0
            break;
        case"=":
            if(previousOperator === null){
                return
            }
            flushOperator(parseInt(numberOnScreen))
            previousOperator=null
            numberOnScreen= runningTotal;
            runningTotal=0;
            break;
        case "←":
            if(numberOnScreen.length ===1){
                numberOnScreen="0" 
            }
            else{
                numberOnScreen=numberOnScreen.substring(0,numberOnScreen.length-1)
            }
            break;
        case "+":
        case "−":
        case "×":
        case "÷":
            handleMath(symbol)
            break;
    }
}
function handleMath(symbol){
    if(numberOnScreen==="0"){
        return
    }
    const intNumber = parseInt(numberOnScreen)
    if(runningTotal===0){
        runningTotal= intNumber
    }
    else{
        flushOperator(intNumber)
    }
    previousOperator=symbol
    numberOnScreen="0"
}
function flushOperator(value){
    if(previousOperator==="+"){
        runningTotal+=value
    }
    else if(previousOperator==="-"){
        runningTotal-=value
    }
    else if(previousOperator==="÷"){
        runningTotal/=value
    }
    else if(previousOperator==="×"){
        runningTotal*=value
    }
}
function handleNumber(numberString){
    if(numberOnScreen==="0"){
        numberOnScreen=numberString
    }
    else{
        numberOnScreen+=numberString
    }
}
function init(){
    document.querySelector('.cal-buttons').addEventListener('click',function(event){
        buttonClick(event.target.innerText)
    })
}
init()