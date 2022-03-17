#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//将int转为string类型，后可以操作。

int main()
{
    ofstream File;
    for (int i = 11; i < 21; i++)
    {
        string bb = "";
        bb = to_string(static_cast<long long>(i));
        File.open("C0" + bb + "_" + ".md");
        File.close();
    }
    return 0;
}
