#include<iostream>
using namespace std;
int main()
{
  int n;
  do
  {
     cout<<"Nhập vào số n: ";
  cin>>n;
  } while (n<10||n>99);
  
 
  
  int b = n % 10;
  
  int a = n / 10;
  
  
 
    
    switch(a){
      case 1: cout<<"Mười ";break;
      case 2: cout<<"Hai mươi ";break;
      case 3: cout<<"Ba mươi ";break;
      case 4: cout<<"Bốn mươi ";break;
      case 5: cout<<"Năm mươi ";break;
      case 6: cout<<"Sáu mươi ";break;
      case 7: cout<<"Bảy mươi ";break;
      case 8: cout<<"Tám mươi ";break;
      case 9: cout<<"Chín mươi ";break;
    }
   
    switch(b){
      case 1: cout<<"một ";break;
      case 2: cout<<"hai ";break;
      case 3: cout<<"ba ";break;
      case 4: cout<<"bốn ";break;
      case 5: cout<<"lăm ";break;
      case 6: cout<<"sáu ";break;
      case 7: cout<<"bảy ";break;
      case 8: cout<<"tám ";break;
      case 9: cout<<"chín ";break;
    }
  
}