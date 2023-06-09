#include <iostream>
using namespace std;

typedef long long ll;
const int primeMax = 1000000;
int num[primeMax + 1];
ll prime[100000];
int primecnt = 0;

int main()
{
    for (int i = 2; i <= primeMax; i++) num[i] = i;

    for (int i = 2; i <= primeMax; i++) {
        for (int j = 2; j <= primeMax / i ; j++) {
             num[i * j] = -1;
        }
    }

    for (int i = 2; i <= primeMax; i++)
        if (num[i] != -1) {
          prime[primecnt++] = (ll)num[i] * num[i];
      }
    cout << "last prime squared " << prime[primecnt-1] << " number " << primecnt;
 }
