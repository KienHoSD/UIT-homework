#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;
int main() {
  int tt;
  cin>>tt;
  while (tt--) {
    LL n, ans1 = -1, ans2 = -1, best = -1;
    cin>>n;
    n = n * 2 - 1;
    for (LL i = 1; i * i * 2 < n; ++i) {
      if ((n - i) % (2 * i + 1) == 0) {
        LL j = (n - i) / (2 * i + 1);
        if (j < i) break;
        if (best == -1 || best > j - i) {
          best = j - i;
          ans1 = i;
          ans2 = j;
        }
      }
    }
    cout<<ans1<<" "<<ans2<<endl;
  }
}
