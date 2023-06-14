#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;string srv;
    cin>>s; srv=s;
    reverse(srv.begin(),srv.end());
    cout<<boolalpha<<(srv==s)?true:false;
}
