#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string ketqua= "Win";
    getline(cin,s);
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]==s[0]&&s[i+1]==s[s.length()-1]){
            ketqua="Lose";
            break;
        }
        else if (s[0]==s[s.length()-1]){
            ketqua="Win";
            break;
        }
    }
    cout<<ketqua;
}
