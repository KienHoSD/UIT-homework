#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,Max,Min;
    cin>>a>>b;
    Max= (a+b+abs(a-b))/2;
    Min= (a+b-abs(a-b))/2;
    cout<<"max = "<<Max<<endl;
    cout<<"min = "<<Min;

}
