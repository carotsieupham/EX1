#include <iostream>
using namespace std;
int main(){
    int i,count{0};
    for ( i = 0; i <=100; i++)
    {
        if(i%3==0||i%7==0){
            count++;
        }
    } 
    cout<<"So luong so chia het cho 3 hoac 7 la:"<<count; 
}