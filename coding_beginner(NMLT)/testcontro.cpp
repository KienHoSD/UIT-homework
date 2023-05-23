#include<iostream>
#include <cstring>
using namespace std;
int main() {
    char str[20] = "hello class";
    char *p;
    int n = strlen(str);
    p = str;
    for (int i = 0; i<=n; i++)
    *(p+i) = toupper(*(p+i));
    cout << p;
}
