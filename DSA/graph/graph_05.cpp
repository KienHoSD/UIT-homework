/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include <iostream>
#include <vector>
using namespace std;

void Input(vector<vector<int>> G, int v, int e){
    int etemp,vtemp;
    for(int i=0;i<e;i++){
        cin>>etemp>>vtemp;
        G[vtemp][etemp]=1;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<G[j][i]<<" ";
        cout<<"\n";
    }

}
int main()
{
	int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0));
	Input(G,v,e);
	return 0;
}
