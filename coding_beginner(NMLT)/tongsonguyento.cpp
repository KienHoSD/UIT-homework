/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
Fibo
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main(){
    int n;
    int tong=0;
    int e=0;
    while(true)
    {
        cin>>n;
        if(n>0&&n<=50){
            for(int i=0;;i++){
                if(isPrime(i)){
                    tong+=i;
                    e++;
                }
                if(e==n) break;
            }
            cout<<"Tong "<<n<<" so nguyen to dau tien la: " <<tong;
            break;
        }
        else cout<<"Gia tri vua nhap la "<<n<<", khong hop le. Vui long nhap lai."<<endl;
    }
}
