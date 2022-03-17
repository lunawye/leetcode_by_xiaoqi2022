#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//将int转为string类型，后可以操作。

int main()
{
    vector<string> aa = {
        "类的访问修饰符，子类是否持有父类的私有成员，子类能否访问父类的私有成员？",
        "C语言和C++的区别与联系",
        "C++重载、重写和重定义的区别",
        "怎么判断机器是32位还是64位",
        "虚析构函数（为什么我们不提虚构造函数呢？）",
        "多态是什么",
        "怎么判断大端小端",
        "构造函数和析构函数的调用顺序（包含多重继承、类中包含对象成员）",
        "纯虚函数与抽象类"};
    ofstream File;
    for (int i = 3; i < 10; i++)
    {
        string bb = "";
        bb = to_string(static_cast<long long>(i));
        File.open("C00" + bb + aa[i - 2] + "_" + ".md");
        File.close();
    }
    return 0;
}
