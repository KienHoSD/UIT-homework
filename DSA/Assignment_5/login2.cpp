#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::cin;
using std::cout;
using std::ios;
using std::vector;
void checkUser(const unordered_map<string, vector<string>>& database, const string& tk) {
    auto it = database.find(tk);
    if (it == database.end()) {
        cout << "Chua Dang Ky!\n";
    } else {
        const vector<string>& mks = it->second;
        for (auto mk = mks.begin(); mk != mks.end(); ++mk) 
            cout << *mk << " ";
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    string tk,mk;
    unordered_map<string,vector<string>> database;
    for(int i=0;i<n;i++){
        cin>>tk>>mk;
        database[tk].push_back(mk);
    }
    for(int i=0;i<q;i++){
        cin>>tk;
        checkUser(database,tk);
    }
}
