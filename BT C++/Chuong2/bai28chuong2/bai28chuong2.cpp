#include<iostream>
using namespace std;
int main()
{
 
  int n;
  do
  {
     cout<<"Nhap vao so n: ";
  cin>>n;
  } while (n<100||n>999);
  
 
  
  int b = n % 10;
  
  int a = n / 100;
  int c = (n - a * 100) / 10;
  
   switch(a){
      case 1: cout<<"Mot tram ";break;
      case 2: cout<<"Hai tram ";break;
      case 3: cout<<"Ba tram ";break;
      case 4: cout<<"Bon tram ";break;
      case 5: cout<<"Nam tram ";break;
      case 6: cout<<"Sau tram ";break;
      case 7: cout<<"Bay tram ";break;
      case 8: cout<<"Tam tram ";break;
      case 9: cout<<"Chin tram ";break;
    }
 
    
    switch(c){
      case 1: cout<<"Muoi ";break;
      case 2: cout<<"Hai muoi ";break;
      case 3: cout<<"Ba muoi ";break;
      case 4: cout<<"Bon muoi ";break;
      case 5: cout<<"Nam muoi ";break;
      case 6: cout<<"Sau muoi ";break;
      case 7: cout<<"Bay muoi ";break;
      case 8: cout<<"Tam muoi ";break;
      case 9: cout<<"Chin muoi ";break;
    }
  
    switch(b){
      case 1: cout<<"moy ";break;
      case 2: cout<<"hai ";break;
      case 3: cout<<"ba ";break;
      case 4: cout<<"bon ";break;
      case 5: cout<<"lam ";break;
      case 6: cout<<"sau ";break;
      case 7: cout<<"bay ";break;
      case 8: cout<<"tam ";break;
      case 9: cout<<"chin ";break;
    }
  
}