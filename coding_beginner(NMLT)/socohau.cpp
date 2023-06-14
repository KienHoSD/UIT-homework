#include <iostream>
#include <math.h>
using namespace std;
int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}
int main(){
    long long n,m;
    cin>>n>>m;
    int dem=0;
    for(long long i=0;i<=m;i+=(pow(10,countDigit(n)))+0.1){
        if(i+n<=m)
            dem++;
    }
    cout<<dem;
}
