#include <iostream>
using namespace std ;
int main(){
    char ch,*pc;
    pc=&ch;
    *pc='A';
    cout<< ch;
}