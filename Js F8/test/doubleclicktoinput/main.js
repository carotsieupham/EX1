function convertToInput(element) {
    // Tạo một thẻ input
    var inputElement = document.createElement("input");

    // Gán nội dung của thẻ h1 vào thẻ input
    inputElement.value = element.textContent;

    // Thay thế thẻ h1 bằng thẻ input
    element.parentNode.replaceChild(inputElement, element);

    // Gắn sự kiện blur cho thẻ input để chuyển lại thành thẻ h1 khi người dùng kết thúc chỉnh sửa
    inputElement.addEventListener("blur", function () {
        element.textContent = inputElement.value;
        element.parentNode.replaceChild(element, inputElement);
    });

    // Tự đặt trỏ vào thẻ input và chọn toàn bộ nội dung của nó
    inputElement.focus();
    inputElement.select();
}
