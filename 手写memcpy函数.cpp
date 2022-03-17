#include <iostream>
#include <cassert>
using namespace std;

void *memcpy2(void *memTo, const void *memFrom, size_t size)
{
    assert((memTo != NULL) && (memFrom != NULL));
    char *tempFrom = (char *)memFrom; //保存memFrom首地址
    char *tempTo = (char *)memTo;
    while (size-- > 0)
    {
        *tempTo++ = *tempFrom++;
    }
    return memTo;
}

int main()
{
    int x;
    char strSrc[] = "Hello World ! Fighting!";
    char strDest[20];
    cout << "please enter x" << endl;
    cin >> x;
    memcpy2(strDest, strSrc, x);
    strDest[x] = '\0';
    cout << "strDest:" << strDest << endl;
    return 0;
}