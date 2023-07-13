#include<iostream>
#include<string>
using namespace std;
class Animal{
public:
    string name;
    int weight;
    Animal(string a, int b,string c){
        name = a;
        weight= b;
        address =c;
    }
    void run(){
        cout<<name<<" eatting....in"<<address;
    }
private:
string address;
};
int main(){
    Animal Cat("bo",20,"Ha noi");
    Cat.run();
}