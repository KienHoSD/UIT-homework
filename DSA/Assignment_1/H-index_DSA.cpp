/*#include <iostream>
#include <algorithm>
int main(){
    int n;std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++) std::cin>>a[i];
    std::sort(a,a+n);
    int dem_0=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]>n) continue;
        if(a[i]==0) dem_0++;
        if(a[n-a[i]]>=a[i]&&a[i]!=0){
            std::cout<<a[i];
            return 0;
        }
    }
    std::cout<<n-dem_0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int Solution(const vector<int> &c){
      int n = c.size();
      vector <int> bucket(n + 1);
      for(int i = 0; i < n; i++){
         int x = c[i];
         if(x >= n){
            bucket[n]++;
         } else {
            bucket[x]++;
         }
      }
      int cnt = 0;
      for(int i = n; i >= 0; i--){
         cnt += bucket[i];
         if(cnt >= i)return i;
      }
      return -1;
}
int main(){
   vector<int> v;
   int n;cin>>n;
   int temp;
   for(int i=0;i<n;i++) {
        cin>>temp;
        v.push_back(temp);
   }
   cout << Solution(v);
}
