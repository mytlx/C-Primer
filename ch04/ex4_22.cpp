#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    int grade;
    cin >> grade;

    // 条件运算符
    cout << ((grade > 90) ? "high pass"
        : (grade < 60) ? "fail"
        : (grade < 75) ? "low pass" : "pass");
    cout << endl;
    // if语句
    if (grade > 90)
        cout << "high pass" << endl;
    else if (grade < 60)
        cout << "fail" << endl;
    else if (grade < 75)
        cout << "low pass" << endl;
    else
        cout << "pass" << endl;
    return 0;
}
