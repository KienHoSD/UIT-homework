#include <iostream>
using namespace std;
int main(){
    int n;
    int a[100001];
    int x,i;
    bool coso=false;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    cin>>x;
    for(i=1;i<=n;i++){
        if(a[i]==x) {
            cout<<i<<" ";
            coso=true;
        }
    }
    if(coso==false)
        cout<<"NO";
}
