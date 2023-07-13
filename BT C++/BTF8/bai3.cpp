#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Bank;
class Account{

private:
    string name;
    int balance;
public:
string get_name(){
    return this->name;
}
 int get_balance(){
    return this->balance;
}
friend Bank;
};
class Bank{
private:
vector<Account> accounts;
public:
void add_account(string name, int balance){
    Account new_account;
    new_account.name = name;
    new_account.balance= balance;
    this->accounts.push_back(new_account);
}
void get_account(string name){
    int index =-1;
    for(int i =0;i <this->accounts.size();i++){
        if (!name.compare(this->accounts[i].name))
        {
            index = i;
            break;
        }
        
    }
    if (index!=-1)
    {
        cout<<"Name: "<<this->accounts[index].name;
        cout<<", balance: " <<this->accounts[index].balance<<endl;
    }
    else cout<<"Not found!";
}
};
int main(){
    Bank bank;
    bank.add_account("Tri",200);
    bank.add_account("Duy",300);
    bank.add_account("Nhi",2000000);
    bank.get_account("Duy1");
    return 0;
}