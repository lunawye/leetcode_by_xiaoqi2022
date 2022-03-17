#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//将int转为string类型，后可以操作。

int main()
{
    ofstream File;
    for (int i = 1; i < 10; i++)
    {
        string bb = "";
        bb = to_string(static_cast<long long>(i));
        File.open("C00" + bb + "_" + ".md");
        File.close();
    }
    return 0;
}
