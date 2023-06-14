#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    string bieuthuc;
    getline(cin,bieuthuc);
    int chieudaibieuthuc=bieuthuc.length();
    stack<char> s;
    for(int i=0;i<chieudaibieuthuc;i++){
        if(bieuthuc[i]=='('||bieuthuc[i]=='{'||bieuthuc[i]=='[') s.push(bieuthuc[i]);
        else if(!s.empty()&&bieuthuc[i]==')'&&s.top()=='(') s.pop();
        else if(!s.empty()&&bieuthuc[i]=='}'&&s.top()=='{') s.pop();
        else if(!s.empty()&&bieuthuc[i]==']'&&s.top()=='[') s.pop();
        else if(bieuthuc[i]==')'||bieuthuc[i]=='}'||bieuthuc[i]==']') s.push(bieuthuc[i]);
    }
    if(s.empty()) cout<<1;
    else cout<<0;
}
