#include <iostream>
using namespace std;

void sap_xep_mang(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int i = 0;
    while (arr[i] < 0)
    {
        i++;
    }

    int j = i;
    while (arr[j] == 0)
    {
        j++;
    }

    for (int k = i; k < j - 1; k++)
    {
        for (int l = k + 1; l < j; l++)
        {
            if (arr[k] < arr[l])
            {
                int temp = arr[k];
                arr[k] = arr[l];
                arr[l] = temp;
            }
        }
    }

    for (int k = j; k < n - 1; k++)
    {
        for (int l = k + 1; l < n; l++)
        {
            if (arr[k] > arr[l])
            {
                int temp = arr[k];
                arr[k] = arr[l];
                arr[l] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sap_xep_mang(arr, n);

    cout << "Mang da sap xep la: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }}