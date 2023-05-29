/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include <map>
#include <set>
#include <iostream>
using namespace std;
void Input(map<int,set<int>> number_list,int n){
    cin>>n;
    int etemp,vtemp;
    set<int> test;
    for(int i=0;i<n;i++){
        cin>>etemp>>vtemp;
        number_list[etemp].insert(vtemp);
    }
    int dem=0;
    map<int,int> ans;
    for (auto it = number_list.begin();it!=number_list.end();it++){
        ans[it->first]=1;
        set<int> st = it->second;
        for(auto et = st.begin();et!=st.end();et++)
            ans[*et]=1;
    }
    for(auto it = ans.begin();it!=ans.end();it++)
        cout<<it->first<<" ";
}
int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
