#include <iostream>
using namespace std;
//tạo TNODE
struct TNODE{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;
//tạo cây rỗng

void CreateEmptyTree(TREE &T){
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
void NLR(TREE T){
    if(T){
        cout<<T->key<<" ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

void LNR(TREE T){
    if(T){
        LNR(T->pLeft);
        cout<<T->key<<" ";
        LNR(T->pRight);
    }
}

TNODE* searchNode(TREE T, int x){
    if(T){
        if(T->key==x) return T;
        else {
            if(x<T->key) searchNode(T->pLeft,x);
            else searchNode(T->pRight,x);
        }
    }
    return NULL;
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
        if(T->key!=x){
            cout<<T->key<<" ";
            countnode++;
        }
        LNRsolve(T->pRight,x);
    }
}

int main(){
    TREE T;
    CreateEmptyTree(T);
    Input(T);
    int x; cin>>x;
    LNRsolve(T,x);
    if(treeHeight(searchNode(T,x))==1){
        cout<<"No descendant";
        return 0;
    }
    if(!countnode){
        cout<<"No Find";
        return 0;
    }
}
