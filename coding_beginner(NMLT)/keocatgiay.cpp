#include <iostream>
using namespace std;
int main(){
    int64_t n,m; cin>>n>>m;
    int64_t tong=0;
    int64_t base= (n>m)? m:n;
    int64_t mdecoy=m-2;
    tong+=(mdecoy*(mdecoy+1))/2-((mdecoy-base+1)*(mdecoy-base+2))/2;
    int64_t ndecoy=n-1;
    tong+=(ndecoy*(ndecoy+1))/2-((ndecoy-base+1)*(ndecoy-base+2))/2;
    cout<<tong;
}
