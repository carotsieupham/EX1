#include <iostream>

int main(){
    int arrayThang[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ngay, thang, nam;
    std::cout << "Nhap ngay cua nam hien tai: ";
    std::cin >> ngay;
    std::cout << "Nhap thang cua nam hien tai: ";
    std::cin >> thang;
    std::cout << "Nhap nam cua nam hien tai: ";
    std::cin >> nam;
    if ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0))){ // kiem tra nam nhuan
        arrayThang[1]++;
    }
    if((ngay > 0) && (ngay <= arrayThang[thang - 1] && (thang > 0) && (thang < 13) && nam > 1800)){
        if (thang == 1 || thang == 2 || thang == 3){
            std::cout << "Thang " << thang << " Thuoc quy I!" << std::endl;
        }else if (thang == 4 || thang == 5 || thang == 6){
            std::cout << "Thang " << thang << " Thuoc quy II!" << std::endl;
        }else if (thang == 7 || thang == 8 || thang == 9){
            std::cout << "Thang " << thang << " Thuoc quy III!" << std::endl;
        }else{
            std::cout << "Thang " << thang << " Thuoc quy IV" << std::endl;
        }
        std::cout << "Thang " << thang << " Co " << arrayThang[thang - 1] << " Ngay!" << std::endl;
        if (thang == arrayThang[thang -1]){
            std::cout << "Ngay hom sau la ngay 1" << std::endl;
        }else{
            std::cout << "Ngay hom sau la ngay: "<< ngay + 1 << std::endl;
        }
        if (ngay == 1){
            std::cout << "Ngay hom truoc la ngay: "<< arrayThang[thang -2] << " Thang " << thang - 1 << std::endl;
        }else{
            std::cout << "Ngay hom truoc la ngay: "<< ngay - 1<< std::endl;
        }
    }else{
        std::cout << "Ngay thang ban nhap khong hop le!" << std::endl;
    }
    
    return 0;
}