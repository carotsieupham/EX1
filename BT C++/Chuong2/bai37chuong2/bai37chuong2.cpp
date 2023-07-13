#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int i;
    double PI{3.14159265};
    cout<<"x"<<setw(15)<<"sin(x)"<<setw(15)<<"cos(x)"<<setw(15)<<"tan(x)"<<endl;
    for(i=0;i<=180;i+=5){cout<<i<<setw(15)<<sin(i*(PI/180))<<setw(15)<<cos(i*(PI/180))<<setw(15)<<tan(i*(PI/180))<<endl;}
}
    
  