#include <iostream>
using namespace std;

int main()
{
    int a[3] = {1, 2, 3};
    // 类型 (&引用名)[数组中元素个数] = 数组名
    int(&b)[3] = a;
    cout << "sizeof(b): " << sizeof(b) << endl;
    return 0;
}
