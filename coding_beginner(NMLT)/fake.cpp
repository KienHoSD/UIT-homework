#include <iostream>
using namespace std;
long double n,m;
int64_t h,w;
int solangap1=0;
int solangap2=0;

int main(){
    cin>>n>>m>>h>>w;
    long double defaultn=n, defaultm=m;
    while(true)
    {
        if(n<=h)
            break;
        n/=2, solangap1++;
    }
    while(true)
    {
        if(m<=w)
            break;
        m/=2, solangap1++;
    }
    n=defaultn, m=defaultm;
    while(true)
    {
        if(n<=w)
            break;
        n/=2, solangap2++;
    }
    while(true)
    {
        if(m<=h)
            break;
        m/=2, solangap2++;
    }
    int solangapnhonhat= (solangap1>solangap2)? solangap2:solangap1;
    cout<<solangapnhonhat;
}
