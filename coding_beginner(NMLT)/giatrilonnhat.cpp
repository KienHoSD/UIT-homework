#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n],maxx=-1,solan=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxx){
            maxx=a[i];
            solan=1;
        }
        else if(a[i]==maxx) solan++;
    }
    cout<<maxx<<endl<<solan;
}
