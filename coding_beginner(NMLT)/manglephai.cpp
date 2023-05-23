#include <iostream>
#include <vector>
#include <string>
using namespace std;
int sophantuA(int a){
    int dem=0;
    if (a<0)dem++;
    a=abs(a);
    while(a>0){
        a/=10;
        dem++;
    }
    return dem;
}
int main(){
    int r,c; cin>>r>>c;
    int a;
    vector<int> v;
    vector<int> dodai(c,0);
    int dodaia=0;
    for(int i=0 ; i<r*c ; i++){
        cin>>a;
        v.push_back(a);
        dodaia=sophantuA(a);
        if(dodaia>dodai[i%c])
            dodai[i%c]=dodaia;
    }
    for(int i=0 ; i<r*c ; i++){
        for(int j=0;j<dodai[i%c]-sophantuA(v[i]);j++) cout<<" ";
        cout<<v[i];
        if((i+1)%c==0) cout<<"\n";
        else cout<<" ";
    }
}
