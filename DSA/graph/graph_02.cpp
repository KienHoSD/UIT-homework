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
    cin>>n;
    for (auto it = number_list.begin();it!=number_list.end();it++){
        if(it->first == n){
            set<int> st = it->second;
            for(auto et = st.begin();et!=st.end();et++)
                cout<<*et<<" ";
        }
    }

}
int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
