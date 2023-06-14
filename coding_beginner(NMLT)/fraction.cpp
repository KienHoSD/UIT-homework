#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int phanso(int a, int b,int c,int d){
    int gcdab;
    int solan=0;

    while(true){
        if(a==c&&b==d||solan==1000000) break;
        solan++;
        a++;b++;
        gcdab=gcd(a,b);
        if(gcdab>1){
            a/=gcdab;
            b/=gcdab;
        }

    }
    if(solan==1000000) solan=0;
    return solan;
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<phanso(a,b,c,d);

}
