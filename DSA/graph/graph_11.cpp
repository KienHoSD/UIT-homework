/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void Input(int v, map<string, int> v_index, int e, vector<vector<int>> G){
    int etemp,vtemp;
    string nuoc1,nuoc2;
    for(int i=0;i<v;i++){
        cin>>nuoc1;
        v_index[nuoc1]=i;
    }
    for(int i=0;i<e;i++){
        cin>> nuoc1 >> nuoc2 >> vtemp;
        G[v_index[nuoc1]][v_index[nuoc2]]+=vtemp;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
}
int main()
{
    int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	return 0;
}

