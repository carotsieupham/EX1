var listCourses = document.querySelector('#list-courses');
var courseApi = 'http://localhost:3000/courses';
var isEditing = false; // Biến để kiểm tra xem người dùng đang trong chế độ chỉnh sửa hay không
var editingId = null; // Lưu ID của khóa học đang được chỉnh sửa

function getCourses(cb) {
    fetch(courseApi)
        .then(function (response) {
            console.log(response)
            return response.json();
        })
        .then(cb);
}

function renderCourse(courses) {
    var htmls = courses.map(function (course) {
        return `<li class="course-item-${course.id}">
        <h4>${course.name}</h4>
        <p>${course.description}</p>
        <div>
            <button onclick="deleteCourse(${course.id})">Xóa</button>
            <button onclick="startEditing(${course.id})">Chỉnh sửa</button>
        </div>
        </li>`;
    });
    listCourses.innerHTML = htmls.join('');
}

function createCourse(data, cb) {
    options = {
        method: 'POST',
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify(data)
    };
    fetch(courseApi, options)
        .then(function (response) {
            return response.json();
        })
        .then(cb);
}

function deleteCourse(id) {
    options = {
        method: 'DELETE',
        headers: {
            "Content-Type": "application/json",
        },
    };
    fetch(courseApi + '/' + id, options)
        .then(function (response) {
            return response.json();
        })
        .then(function () {
            var courseItem = document.querySelector('.course-item-' + id);
            if (courseItem) {
                courseItem.remove();
            }
        });
}

function startEditing(id) {
    // Ngăn người dùng chỉnh sửa nhiều khóa học cùng lúc
    if (isEditing) {
        alert("Bạn đang chỉnh sửa một khóa học khác. Hoàn thành hoặc hủy bớt chỉnh sửa trước.");
        return;
    }

    // Lưu trạng thái chỉnh sửa và ID của khóa học đang chỉnh sửa
    isEditing = true;
    editingId = id;

    // Tìm phần tử khóa học để chỉnh sửa
    var courseItem = document.querySelector('.course-item-' + id);
    if (courseItem) {
        var nameElement = courseItem.querySelector('h4');
        var descriptionElement = courseItem.querySelector('p');

        // Tạo các trường nhập dữ liệu để chỉnh sửa
        var nameInput = document.createElement("input");
        nameInput.value = nameElement.textContent;

        var descriptionInput = document.createElement("input");
        descriptionInput.value = descriptionElement.textContent;

        // Thay thế nội dung hiện có bằng các trường nhập
        nameElement.innerHTML = '';
        nameElement.appendChild(nameInput);

        descriptionElement.innerHTML = '';
        descriptionElement.appendChild(descriptionInput);

        // Tạo nút lưu thay đổi và nút hủy
        var saveButton = document.createElement("button");
        saveButton.textContent = "Lưu";
        saveButton.onclick = function () {
            saveChanges(id, nameInput.value, descriptionInput.value);
        };

        var cancelButton = document.createElement("button");
        cancelButton.textContent = "Hủy";
        cancelButton.onclick = cancelEditing;

        // Thêm nút lưu và nút hủy vào phần tử khóa học
        courseItem.appendChild(saveButton);
        courseItem.appendChild(cancelButton);
    }
}

function saveChanges(id, newName, newDescription) {
    var updatedData = {
        name: newName,
        description: newDescription
    };

    options = {
        method: 'PUT', // Sử dụng phương thức PUT để cập nhật khóa học
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify(updatedData)
    };

    fetch(courseApi + '/' + id, options)
        .then(function (response) {
            return response.json();
        })
        .then(function () {
            // Sau khi cập nhật, tải lại danh sách khóa học và kết thúc chế độ chỉnh sửa
            getCourses(renderCourse);
            cancelEditing();
        });
}

function cancelEditing() {
    // Kết thúc chế độ chỉnh sửa và đặt lại biến isEditing và editingId
    isEditing = false;
    editingId = null;

    // Tải lại danh sách khóa học để hiển thị dữ liệu mới
    getCourses(renderCourse);
}

function handle() {
    var createBtn = document.querySelector('#create');
    createBtn.onclick = function () {
        var name = document.querySelector('input[name="name"]').value;
        var description = document.querySelector('input[name="description"]').value;
        var formData = {
            name: name,
            description: description
        };
        createCourse(formData, function () {
            getCourses(renderCourse);
        });
    };
}

function start() {
    getCourses(function (courses) {
        renderCourse(courses);
        handle();
    });
}

start();
