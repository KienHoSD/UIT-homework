#include <iostream>
#include <string>
int hamming(std::string a,std::string b){
    int a_len=a.length();
    int b_len=b.length();
    int dem=0;
    int i=0,j=0;
    a.insert(0, b_len-a_len, '0');
    for(i=0;i<b_len;i++)
        if(a[i]!=b[i]) dem++;
    return dem;
}
void strip(std::string &x){
    while (x[0]=='0')
        x.erase(0,1);
}
int main(){
    std::string a,b;
    getline(std::cin,a);
    getline(std::cin,b);
    strip(a);strip(b);
    std::cout<<hamming(a,b);
}
