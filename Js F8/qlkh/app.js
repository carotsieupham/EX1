
var listCourses= document.querySelector('#list-courses')
var courseApi=' http://localhost:3000/courses'
var i= 0
function getCourses(cb){
    fetch(courseApi)
        .then(function(reponse){
            return reponse.json()
        })
        .then(cb)
}
function renderCourse(courses){
    
    var htmls = courses.map(function(course){
        return`<li class="course-item-${course.id}">
        <h4>${++i}.${course.name}</h4>
        <p>${course.decription}</p>
        <div>
        <button onclick="deleteCourse(${course.id})">Xóa</button>      
        <button onclick="updateCourse(${course.id})">Chỉnh sửa</button>
        </div>
        </li>`
    })
    listCourses.innerHTML=htmls.join('')
}

function createCourse(data,cb){
    options={
        method:'POST',
        headers: {
            "Content-Type": "application/json",
            // 'Content-Type': 'application/x-www-form-urlencoded',
          },
        body:JSON.stringify(data)
    }
    fetch(courseApi,options)
    .then(function(reponse){
        reponse.json()
    })
    .then(cb)
        
}
function deleteCourse(id){
    options={
        method:'DELETE',
        headers: {
            "Content-Type": "application/json",
            // 'Content-Type': 'application/x-www-form-urlencoded',
          },
    }
    fetch(courseApi+'/'+id,options)
    .then(function(reponse){
        reponse.json()
    })
    .then(function(){
        var courseItem=document.querySelector('.course-item-'+id)
        if(courseItem){
            courseItem.remove()
        }
    })
}

function handle(){
    var creatBtn= document.querySelector('#create')
    creatBtn.onclick = function(){
        var name = document.querySelector('input[name="name"]').value
        var decription = document.querySelector('input[name="decription"]').value
        var formData={
            name : name,
            decription: decription
        }
        createCourse(formData,function(){
            getCourses(renderCourse)
        })
    }
    
}
function start(){
    getCourses(function(courses){
        renderCourse(courses)
        handle()
        
    });
}
start()