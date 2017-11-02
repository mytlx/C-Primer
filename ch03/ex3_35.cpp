#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[size] = { 0,1,2,3,4,5,6,7,8,9 };

    for (auto i : arr)
        cout << i << " ";
    for (auto ptr = arr; ptr != arr + size; ++ptr)
        *ptr = 0;
    cout << endl;
    for (auto i : arr)
        cout << i << " ";
}
