#include <iostream>
#include <string>
using namespace std;
struct Sp
{   string ten;
    float gia;
    int sl;
    friend istream& operator>>(istream& is,Sp &a){
        cout<<"Nhap ten sp:";is.ignore();getline(is,a.ten);
        cout<<"Nhap gia:";is>>a.gia;
        cout<<"Nhap so luong:";is>>a.sl;
        return is ;
    }
    friend ostream& operator<<(ostream& os,Sp &a){
        os<<"Ten sp:"<<a.ten;
        os<<",Gia sp:"<<a.gia;
        os<<",So luong sp:"<<a.sl;
        return os;
    }
};
int show_menu(){
    int chose;
    cout<<"======MENU======"<<endl;
    cout<<"1.Xem danh sach san pham"<<endl;
    cout<<"2.Them san pham moi"<<endl;
    cout<<"3.Xoa san pham"<<endl;
    cout<<"0.Thoat chuong trinh"<<endl;
    cout<<"Lua chon cua ban la";cin>>chose;
    return chose;
}
void printsp(Sp *a, int size){
    if (!size)
    {
        cout<<"Chua co sp"<<endl;
    }
    else{
        cout<<"Danh sach sp: "<<endl;
        for (int i = 0; i < size; i++)
        {
            cout<<a[i]<<endl;
        }
        
    }
}
void add(Sp* &a,int &size){
    Sp new_sp;
    cout<<"Nhap thong tin sp moi: "<<endl;
    cin>>new_sp;
    int newsize=size+1;
    Sp *tmp_sp= new Sp[newsize];
    for (int i = 0; i < newsize; i++)
    {
        tmp_sp[i]=a[i];
    }
    tmp_sp[newsize-1]=new_sp;
    delete[] a;
    a= tmp_sp;
    size=newsize;
    cout<<"Them sp thang cong!!!"<<endl;
}
void deletesp(Sp* &a,int &size){
    string delete_name;
    cout<<"Nhap ten sp can xoa:";
    getline(cin,delete_name);
    int delete_index=-1;
    for (int i = 0; i < size; i++)
    {
        if (!delete_name.compare(a[i].ten))
        {
            delete_index=i;
            break;
        }
    }
    if(delete_index==-1){
        cout<<"Khong tim thay sp "<<endl;
        return;
    }    
    for (int i = delete_index; i < size-1; i++)
    {
        a[i]=a[i+1];
    }
    size--;
    Sp *tmp_sp=new Sp[size];
    for (int i = 0; i < size; i++)
    {
        tmp_sp[i]=a[i];
    }
    delete [] a;
    a= tmp_sp;
}
int main(){
    Sp *a;int size=0;
    a= new Sp[size];
   
    while(true){
        int chose= show_menu();
         system("cls");
        switch (chose)
        {
        case 1 :
            // Xem ds
            printsp(a,size);
            break;
        
         case 2 :
            // Them sp
            add(a,size);
            break;
         case 3 :
            // Xoa sp
            deletesp(a,size);
            break;
        case 0:
            cout<<"Bye Bye";
            return 0;
        default:
            cout<<"Lua chon khong hop le"<<endl;
            break;
        }
        cout<<"ban co muon tiep tuc khong (1/0) ";
        bool iscontinue;
        cin>>iscontinue;
        if(!iscontinue){
            cout<<"Bye";
            break;
        } 
    }
    return 0;
}
