/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

//###INSERT CODE HERE -
void Input(int v, map<string, int> v_index, int e, vector<vector<int>> G){
    string nuoc1,nuoc2;
    for(int i=0;i<v;i++){
        cin>>nuoc1;
        v_index[nuoc1]=i;
    }
    for(int i=0;i<e;i++){
        cin>> nuoc1 >> nuoc2;
        G[v_index[nuoc1]][v_index[nuoc2]]=1;
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
	// DFS(G,v_index,v);
	return 0;
}
