var json ='{"name":"Minh Tri","tuoi":19}'
var a= '1'
// trạng thái
// Pending
//Fulfill
//Reject
var promise = new Promise(
    function (resolve, reject){
        //Logic
        // Thành công:resolve()
        //Thất bại:reject()
    }
)
promise
        .then()     //thực hiện khi thành công
        .catch()    // thực hiện khi lỗi
        .finally()  //thực hiện khi hoàn tất
