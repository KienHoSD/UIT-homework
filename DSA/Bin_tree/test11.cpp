/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -
void CreateTree(TREE &T){
    T=NULL;
}
TNODE* CreateNode(int x){
    TNODE* p=new TNODE();
    if(p==NULL)
        exit(1);
    else{
        p->key=x;
        p->pLeft=NULL;
        p->pRight=NULL;
    }
    return p;
}
int Insert(TREE &T, int x){
    if(T){
        if(T->key == x)
            return 0;
        if(T->key > x)
            return Insert(T->pLeft,x);
        return Insert(T->pRight,x);
    }
    T= CreateNode(x);
    return 1;
}
void Input(TREE &T){
    int x=0;
    cin>>x;
    while(x!=-1){
        Insert(T,x);
        cin>>x;
    }

}
int treeHeight(TNODE* T){
    if(!T) return -1;
    int a =treeHeight(T->pLeft);
    int b =treeHeight(T->pRight);
    return (a > b? a:b) +1;
}
int countnode=0;
void LNRsolve(TREE T,int x){
    if(T){
        LNRsolve(T->pLeft,x);
        if(treeHeight(T)==x){
            cout<<T->key<<" ";
            countnode++;
        }
        LNRsolve(T->pRight,x);
    }
}
void Function(TREE T){
	Input(T);
    int x; cin>>x;
    LNRsolve(T,x);
    if(!countnode) cout<<"No Node";
}


int main() {
	TREE T;
	CreateTree(T);
	Function(T);
	return 0;
}

