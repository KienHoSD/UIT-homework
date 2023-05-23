#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
    string tennguoi;
    cout<<"Nhap Strings:";
    getline(cin, tennguoi);
    for(int i=0;i<tennguoi.length();i++)
        tennguoi[i]=toupper(tennguoi[i]);
    cout<<tennguoi;
}
