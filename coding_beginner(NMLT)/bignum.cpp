#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void solve(){
    std::string f;
    ifstream ifs("test.txt");
    ofstream ofs("output.txt");
    int i,e,t; ifs>>t;
    uint64_t n;
    for(i=1;i<=t;i++){
        ifs>>n;
        while(true){
            e=n%10;
            if(e==1)n+=9;
            else if(e==2)n+=8;
            else if(e==3)n+=27;
            else if(e==4)n+=16;
            else if(e==5)n+=5;
            else if(e==6)n+=24;
            else if(e==7)n+=63;
            else if(e==8)n+=32;
            else if(e==9)n+=81;
            n/=10;
            if(n==1 || n==3 || n==7 || n==9){
                f=f+char(n+48)+"\n";
                break;
            }
        }
        if(i%5==0){
           ofs<<f;
            f="";
        }
    }
    i--;
    if(i%5!=0)
       ofs<<f;
}
int main(){
    solve();
    return 0;
}
