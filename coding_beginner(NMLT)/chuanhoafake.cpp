#include "iostream"
#include "array"
using namespace std;
int main(){
    array<int,10> a;

    for(int i=0;i<10;i++)
        cin>>a[i];
    int finding;cin>>finding;
    for(auto i = a.begin();i!=a.end();i++){
        if(*i==finding) cout<<i-a.begin()+1;
    }
}
