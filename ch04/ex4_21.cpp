#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main()
{
    vector<int> vec;
    // 添加元素
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    // 修改元素
    for (auto &i : vec)
        i = (i % 2) ? (i * 2) : i;
    // 打印元素
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
