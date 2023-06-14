/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
 

//###INSERT CODE HERE -
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int checkngang(int i,int v, const vector<vector<int>>& G){
    int bangk=0;
    for(int j=0;j<v;j++)
        bangk+=G[i][j];
    return bangk;
}
int checkdoc(int i,int v, const vector<vector<int>>& G){
    int bangk=0;
    for(int j=0;j<v;j++)
        bangk+=G[j][i];
    return bangk;
}
void Input(int v, map<string, int> v_index, int e, vector<vector<int>> G){
    int vtemp;
    string nuoc1,nuoc2;
    for(int i=0;i<v;i++){
        cin>>nuoc1;
        v_index[nuoc1]=i;
    }
    for(int i=0;i<e;i++){
        cin>> nuoc1 >> nuoc2 >> vtemp;
        G[v_index[nuoc1]][v_index[nuoc2]]=1;
    }
    
    cin>>nuoc2;
    map<string, int>::iterator it;
    bool having=0;
    for(int j=0;j<v;j++)
        if(G[v_index[nuoc2]][j]!=0)
            for(it=v_index.begin();it!=v_index.end();it++)
                if(it->second==j){
                    cout<<it->first<<" ";
                    having=1;
                } 
                
    if(!having) cout<<"No find";
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
