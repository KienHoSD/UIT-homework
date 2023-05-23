#include <iostream>
#include <stack>
int main(){
    int n,y;std::cin>>n;
    std::stack<int> bin;
    do{
        y=n%2;n/=2;
        bin.push(y);
    }while(n!=0);
    while (!bin.empty()){
        std::cout<<bin.top();
        bin.pop();
    }
}
