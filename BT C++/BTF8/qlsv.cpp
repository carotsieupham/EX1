#include <iostream>
#include<string>
#include <vector>
using namespace std;
class School;

struct Date{
    int day;
    int month;
    int year;
    friend istream& operator>>(istream& is, Date& date){
        is>>date.day>>date.month>>date.year;
        return is;
    }
    friend ostream& operator<<(ostream& os, Date& date){
        os<<date.day<<"/"<<date.month<<"/"<<date.year;
        return os;
    }
};
class Student {
private:
    string name;
    Date date;
public:
    string get_name(){
        return this->name;
    }
    Date get_date(){
        return this->date;
    }
    friend School;
    void print_hs();
};
class School {
    vector<Student> students;
    public:
    void add_student(string& name,Date& date){
        Student new_student;
        new_student.name= name;
        new_student.date = date;
        this->students.push_back(new_student);
    }
    void get_student(string& name){
        int index =-1;
        for (int i = 0; i < this->students.size(); i++)
        {
            if(!name.compare(this->students[i].name)){
                index =i;
                break;
            }
        }
        if(index!=-1){
            cout<<"Name: "<<this->students[index].name;
            cout<<", Date"<<this->students[index].date;
        }
        else cout<<"Not found!!";
    }
    void print_hs(){
        if (!this->students.size())
        {
            cout<<"Trong"<<endl;
        }
        else{
        for (int i = 0; i < this->students.size(); i++)
        {
            cout<<"Name: "<<this->students[i].name<<",Date: "<<this->students[i].date<<endl;
        }}
        
    }
    void delete_hs(string name){
        int index =-1;
        for (int i = 0; i < this->students.size(); i++)
        {
            if(!name.compare(this->students[i].name)){
                index =i;
                break;
            }
        }
        if(index!=-1){
            this->students.erase(this->students.begin()+ index);
        }
        else cout<<"Not found!!";
    }
} ;

int Menu(){
    int choose;
    cout<<"======Menu======"<<endl;
    cout<<"1.Coi danh sach hoc sinh"<<endl;
    cout<<"2.Them hoc sinh"<<endl;
    cout<<"3.Xoa hoc sinh"<<endl;
    cout<<"4.Chon hoc sinh"<<endl;
    cout<<"0.Quit"<<endl;
    cout<<"Lua chon cua ban:";cin>>choose;
    return choose;
}

int main(){
    School uth;
    string name;
    Date date;
    vector<Student> students;
while (true)
{   system("cls");
    int choose= Menu();
    switch (choose)
    {
    case 1:
        uth.print_hs();
        break;
    case 2:
        cout<<"Nhap ten hs:";cin>>name;
        cout<<"Nhap ngay thang nam sinh:";cin>>date;
        uth.add_student(name,date);
        break;
    case 3:
        cout<<"Nhap ten hs:";cin>>name;
        uth.delete_hs(name);
        break;
    case 4: 
        cout<<"Nhap ten hs:";cin>>name;
        uth.get_student(name);
        break;
    case 0:
        cout<<"Bye Bye"<<endl;
        break;    
    default:
        cout<<"Lua chon sai"<<endl;
        break;
    }
    bool is_countinue;
    cout<<"Ban co muon tiep tuc khong(1/0):";cin>>is_countinue;
    if(!is_countinue) cout<<"Bye Bye"<<endl;
}

    
}