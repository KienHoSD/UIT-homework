#include <iostream>
using namespace std;
int main(){
    int64_t n,k,p,q;
    int pBob=0;
    int qBob=0;
    cin>>n>>k>>p>>q;
    if(k%2==0){
        pBob=p-k/2;
        if (pBob<=0) pBob=p+k/2;
        if (pBob>(n+1)/2)pBob=0;
        qBob=q;
    }
    else if(k%2==1&&q==1){
        pBob=p+((k+1)/2)-1;
        if(pBob>((n+1)/2)) pBob=p-((k+1)/2);
        if (pBob<=0)pBob=0;
        qBob=2;
    }
    else if(k%2==1&&q==2){
        pBob=p-((k+1)/2)+1;
        if(pBob<=0)pBob=p+((k+1)/2);
        if (pBob>(n+1)/2)pBob=0;
        qBob=1;
    }
    if(pBob*2-2+qBob>n)pBob=0;
    if(pBob==0)cout<<-1;
    else cout<<pBob<<" "<<qBob;
}
