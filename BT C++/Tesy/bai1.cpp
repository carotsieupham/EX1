#include <iostream>
using namespace std;
int countarr(int arr[], int n)
{
    int count = 1;
    int j ;
    for (int i = 1; i < n; i++)
    {
        
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;
        if (i == j)
            count++;
    }
    return count;
}
int main(){
    
    int arr[100],n;
    cout<<"So phan tu trong mang:";cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap phan tu thu "<<i+1<<":";cin>>arr[i];
    }
   cout<<countarr(arr,n);
}