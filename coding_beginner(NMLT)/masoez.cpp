#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream ifs("test.txt");
    string s;
    ifs>>s;
    int dodai=s.length();
    uint dem=0;
    for(int i=0;i<dodai-1;i++){
        for(int j=i+1;j<dodai;j++){
            if(s[i]!=s[j])
                dem++;
        }
    }
    cout<<dem+1;
}
