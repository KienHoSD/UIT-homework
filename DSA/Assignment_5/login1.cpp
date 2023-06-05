#include <iostream>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
using std::cin;
using std::cout;
using std::ios;
void checkUser(const unordered_map<string,string>& database,const string& tk){
    auto it = database.find(tk);
    if (it == database.end())
        cout<< "Chua Dang Ky!\n";
    else 
        cout<< it->second + '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    string tk,mk;
    unordered_map<string,string> database;
    for(int i=0;i<n;i++){
        cin>>tk>>mk;
        database[tk]=mk;
    }
    for(int i=0;i<q;i++){
        cin>>tk;
        checkUser(database,tk);
    }
}
