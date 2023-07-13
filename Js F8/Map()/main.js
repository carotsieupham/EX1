/*
    forEach() trả về từng phần tử của mảng
    every() kiểm tra tất cả các phần tử cùng đạt được 1 đk thì true nếu có 1 pt k đạt đk thì tả về false
    some()  kiểm tra tất cả nếu có 1 phần tử đạt đk thì true
    find() trả về 1 phần tử đạt đk
    filter()trả về tất cả phần tử đạt đk
    map()
    reduce()*/
let courses =[
    {   id:1,
        name:'JVS',
        coin:10
    },  
    {   id:2,
        name:'PHP',
        coin:0
    },
    {   id:3,
        name:'C++',
        coin:12
    },
    {   id:4,
        name:'HTML,CSS',
        coin:14
    },
    {   id:5,
        name:'Ruby',
        coin:18
    },
    {   id:6,
        name:'JV',
        coin:20
    },
];
//Map()
function coursemap(c,i,orginArray){
    return '<h2>'+c.name +'</h2>'
}
var newCourse = courses.map(coursemap)
console.log(newCourse)
console.log(newCourse.join(''))
//reduce()
var totalCoin = courses.reduce(function (total,c) {
    return total+c.coin},0)
//Flat-Làm phẳng mảng từ Depth array 
var depthArray = [1,2,[3,4],5,6,[7,8,9]]
var flatArray = depthArray.reduce(function(flatOutput,depthItem){
    return flatArray.concat(depthItem) //concat() nối mảng
},[])
//Lấy ra các khóa học đưa vào 1 mảng mới
var topics =[{
    topic:"Front-end",
    course:[
        {
            id: 1,
            title:"HTML,CSS"
        },
        {
            id:2,
            title:"JVS"
        }
    ]
},
{
    topic:"Back-end",
    course:[
        {
            id: 1,
            title:"PHP"
        },
        {
            id:2,
            title:"Python"
        }]
}
]
var listCourse= topics.reduce(function(course,topic){
    return course.concat(topic.course)
},[])
