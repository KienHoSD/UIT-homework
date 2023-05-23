#include <iostream>
using namespace std;
int64_t tongsohientai,tongsohangdangxet,f,g,e;
int main(){
    int64_t a[10001];
    int64_t k,n;
    cin>>n>>k;
    for(int64_t i=1;i<=n;i++)
        cin>>a[i];
    int64_t Min=100000000000000;
    for(int i=k;i<=n;i++)
    {
        for(int e=i-k+1;e<=i;e++) tongsohientai+=a[e];
        int w=i-k+1;
        bool behon =true;
        if(w>k){
            for(int g=k;g<w;g++){
                for(int f=g-k+1;f<=g;f++)
                    tongsohangdangxet+=a[f];
                if(tongsohangdangxet>tongsohientai){
                    behon=false;
                    break;
                }tongsohangdangxet=0;
            }tongsohangdangxet=0;
            for(int g=i+k;g<=n;g++){
                for(int f=g-k+1;f<=g;f++)tongsohangdangxet+=a[f];
                if(tongsohangdangxet>tongsohientai){
                    behon=false;
                    break;
                }tongsohangdangxet=0;
            }tongsohangdangxet=0;
        }
        else if (w<=k){
            for(int g=i+k;g<=n;g++){
                for(int f=g-k+1;f<=g;f++) tongsohangdangxet+=a[f];
                if(tongsohangdangxet>tongsohientai){
                    behon=false;
                    break;
                } tongsohangdangxet=0;
            } tongsohangdangxet=0;
        }
        if(behon==true&&tongsohientai<Min) Min=tongsohientai;
        tongsohientai=0;
    }
    cout<<Min;
}

