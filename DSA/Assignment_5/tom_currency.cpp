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
    int temp;
    for(int i =0;i<n;i++){
        cin>>temp;
        arr[temp]++;
    }
    cout<<arr.size()<<'\n';
    for(map<int,int>::iterator it=arr.begin();it!=arr.end();it++)
        cout<<it->first<<" ";
}