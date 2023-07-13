#include<iostream>
#include <math.h>
#include<string>
using namespace std;
void input_interger(string label,int &h);
void input_array(int *arr ,int size);
void print_array(int * arr , int size);
void push(int* &arr, int &size, int x);
int main()
{
	int n ,x;
    int *numbers = new int[n];
    input_interger("N=",n);
    cout<<"Nhap mang:";
    input_array(numbers,n);
    input_interger("x=",x);
    push(numbers,n,x);
    

    cout<<"Mang sau khi them:";
    print_array(numbers,n);}
void input_interger(string label,int &h){
    cout<<label;
    cin>>h;
}
void input_array(int *arr ,int size){
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
}
void print_array(int * arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<<" ";
    }
}
void push(int* &arr, int &size, int x){
    int new_size=size +1;
    int *tmp_arr = new int [new_size];
    for (int i = 0; i < size; i++)
    {
        tmp_arr[i]=arr[i];
    }
    tmp_arr[new_size -1] =x;
    delete []arr;
    arr = tmp_arr;
    size = new_size;
}