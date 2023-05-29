/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include <iostream>
#include <map>
#include <set>
using namespace std;
void Input(map<int,set<int>> number_list, int n){
    cin>>n;
	int a[1000];
	int te,et;
	for(int i=0;i<n;i++){
        cin>>te>>et;
        a[te]++;
	}
	cin>>n;
	cout<<a[n];
}
int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
