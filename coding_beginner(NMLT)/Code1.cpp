#include <iostream>
#include strings
using namespace std;
int main()
{
    cout<<"cho biet 4 chu so xe cua ban:";
    int chusoxe;
    cin>>chusoxe;
    int chusoxethunhat = chusoxe/1000;
    int chusoxethuhai = chusoxe%1000/100;
    int chusoxethuba = chusoxe%1100/10;
    int chusoxethutu = chusoxe%1110;
    int sonut= chusoxethutu + chusoxethuba + chusoxethuhai + chusoxethunhat;
    cout<<sonut %10;
}
