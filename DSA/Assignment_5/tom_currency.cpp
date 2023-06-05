#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::vector;

int main(){
    int n;cin>>n;
    map<int,int> arr;
    int temp,dem=0;
    for(int i =0;i<n;i++){
        cin>>temp;
        arr[temp]++;
    }
    for(auto it=arr.begin();it!=arr.end();it++)
        dem++;
    cout<<dem<<'\n';
    for(auto it=arr.begin();it!=arr.end();it++)
        cout<<it->first<<" ";
}