#include <bits/stdc++.h>
using namespace std;
bool findLargestDivisor1(uint64_t n) {
    if (n % 4 == 0)
        return false;
    for (int p = 3; p * p <= n; p += 2) {
        int count = 0;
        for (; n % p == 0; n /= p) {
            if (++count > 1)
                return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uint64_t lf,rt,dem1=0,dem2=0;
    vector<uint64_t> num1,num2;
    cin>>lf>>rt;
    for(int i=lf;i<=rt;i++)
        if(findLargestDivisor1(i)){
            for (uint64_t w:num1)
                if(findLargestDivisor1(w*i)) dem1++;
            num1.push_back(i);
        }
    cout<<dem1;
}
