#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;
string s;
int64_t i;
void chuanhoachu(int64_t interger,string strings){
    if(strings[interger]>='a'&&strings[interger]<='z') strings[interger]-=32;
    int64_t e;
    for(e=interger+1;e<strings.length();e++){
        if(strings[e]>='A'&&strings[e]<='Z') strings[e]+=32;
        else if(strings[e]==' ') break;
    }
    s=strings;
    i=e;
}
int main(){
    getline(cin,s);
    while(s[0]==' ') s.erase(0,1);
    chuanhoachu(0,s);
    while(true){
        while(s[i]==' '&&s[i+1]==' ') s.erase(s.begin()+i);
        chuanhoachu(i+1,s);
        if(s[i+1]==0) break;
    }cout<<s;
}
