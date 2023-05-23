#include "iostream"
#include "array"
#include "string"
#include <vector>
template<typename T>
void swaps(T &x, T &y){
    T temp = x;
    x=y;
    y=temp;
}

void swaps(int &x,int &y){
    std::cout<<"x and y is int type";
}

int main(){
    std::vector<char> name;
    std::string name1;

    char arr[]= "I dont know jus testing";
    //std::cout<<sizeof(arr)/sizeof(arr[0]);
    std::cout<<(1<<20);
}
