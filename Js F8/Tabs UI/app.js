const $= document.querySelector.bind(document)  
const $$= document.querySelectorAll.bind(document)
const tabs =$$('.tab-item')
const panes =$$('.tab-pane')
const line = $('.tabs .line ')
const tabActive = $('.tab-item.active')
line.style.left= tabActive.offsetLeft + 'px'
line.style.width= tabActive.offsetWidth+'px'
tabs.forEach((tab,i) => {
    const pane =panes[i]
    tab.onclick = function(){
        $('.tab-item.active').classList.remove('active')  
        $('.tab-pane.active').classList.remove('active')
        line.style.left= this.offsetLeft + 'px'
        line.style.width= this.offsetWidth+'px'
        this.classList.add('active')
        pane.classList.add('active')
    }
});