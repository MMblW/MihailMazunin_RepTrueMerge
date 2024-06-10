#include <iostream>
using namespace std;
void TrueMerge(int *arr, int right, int left)
{
    int PackOne = 1;
    int PackTwo = 1;
    int index = 0;
    bool NeedOneMore = false;
    while (arr[index] <= arr[index + 1] && index < right - 1) // Вычисление размера первой серии
    {
        PackOne++;
        index++;
    }
    if (arr[index] > arr[index + 1] && index < right - 1) // Вычисление размера второй серии
    {
        index++;
        NeedOneMore = true;
        while (arr[index] <= arr[index + 1] && index < right - 1)
        {
            PackTwo++;
            index++;
        }
    }
    int number = index + 1; // Number = индекс первого числа последовательности, не входящего в серию
    int *farr = new int[PackOne]; // farr и sarr - серии. Далее они инициализируются
    int *sarr = new int[PackTwo];
    for (index = 0; index < PackOne; index++)
    {
        farr[index] = arr[index];
    }
    int tempindex = 0;
    if (NeedOneMore)
    {
        for (index = PackOne; index < PackOne + PackTwo; index++)
        {
            sarr[tempindex] = arr[index];
            tempindex++;
        }
    }
    cout << endl;
    cout << "1: ";
    for (int i = 0; i < PackOne; i++)
    {
        cout << farr[i] << " ";
    }
    cout << endl << endl;
    cout << "2: ";
    for (int i = 0; i < PackTwo; i++)
    {
        cout << sarr[i] << " ";
    }
    cout << endl << endl;
    int j = 0;
    int l = 0;
    if (NeedOneMore)
    {
        for (index = 0; index < number; index++)
        {
            if ((farr[l] < sarr[j] || j >= PackTwo) && l < PackOne)
            {
                arr[index] = farr[l];
                l++;
            }
            else
            if ((farr[l] > sarr[j] || l >= PackOne) && j < PackTwo)
            {
                arr[index] = sarr[j];
                j++;
            }
            else
            if (farr[l] == sarr[j] && j < PackTwo && l < PackOne)
            {
                arr[index] = farr[l];
                arr[index + 1] = sarr[j];
                l++;
                j++;
                index++;
            }
        }
    }
}
void Sort(int *arr, int right, int left)
{
    if (left < right)
    {
        TrueMerge(arr, right, left);
        Sort(arr, right, left + 1);
    }
}
int main()
{
    int arr[] = {1, 10, 12, 3, 40, 15, 68, 12, 22, 37, 105, 2, 7, 18, 4, 2, 91, 6, 13, 76, 4, 55, 8, 1, 17};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    Sort(arr, sizeof(arr)/sizeof(int), 0);
    cout << endl;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout << arr[i] <<" ";
    }
}