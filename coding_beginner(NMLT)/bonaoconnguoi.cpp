#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,kiso,vitri,c,d; cin>>n;
long long a[n+1];
long long b[n+1];
kiso=0;vitri=1;
for (int i=0;i<n;i++){
        cin>>a[i];b[i]=0;
}
a[n]=0;c=0;d=0;
for (int i=0;i<=n;i++){
    b[i+1]=__gcd(b[i],a[i]);
    if(b[i+1]!=b[i])
        vitri=i+1;
    if (b[i+1]==1){
        vitri=i+1;
        break;
    }
}
if ((vitri==2)||(vitri==1)){
        for (int i=2;i<n;i++)
            kiso=__gcd(a[i],kiso);
        c=__gcd(kiso,a[0]);
        d=__gcd(kiso,a[1]);
    if (d>=c){
        vitri=1;kiso=d;
    }

    else{
        vitri=2;kiso=c;
    }

}
else {
    for (int i=0;i<n;i++)
        if (i!=vitri-1)
            kiso=__gcd(a[i],kiso);
}
cout<<vitri<<" "<<kiso;
return 0;

}
