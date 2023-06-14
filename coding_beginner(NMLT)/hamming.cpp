#include <iostream>
#include <string>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string x,y;
    int64_t hamming=0;
    int64_t j=0;
    getline(cin,x);
    getline(cin,y);
    int precision = y.length()-x.length();
    x.insert(0, precision, '0');
    for(int i=y.length()-1;i>=0;i--){
        j++;
        if(x[i]!=y[i])hamming=j;
    }
    cout<<hamming;
    return 0;
}
