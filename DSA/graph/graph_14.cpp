/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
 #include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

struct List
{
    Node* head=NULL;
    Node* tail=NULL;
};

struct Graph
{
    int v; // số đỉnh của đồ thị 
    List* arr; //mảng của các danh sách
};

//###INSERT CODE HERE -
List insert(List list,int data){
    if(!list.head){
        Node* temp= new Node;
        temp->info=data;
        list.head=temp;
        list.tail=temp;
    }
    else{
        Node* temp = list.head;
        while(temp->next)
            temp=temp->next;
        Node* newNode = new Node;
        newNode->info=data;
        temp->next=newNode;
        list.tail=newNode;
    }
    return list;
}
void print(List list){
    Node* temp=list.head;
    if(!temp) return;
    if(temp)
        cout<<temp->info;
    temp=temp->next;
    while(temp){
        cout<<", "<<temp->info;
        temp=temp->next;
    }
}
void Input(Graph G, int e){
    int d1,d2;
    for(int i=0;i<e;i++){
        cin>>d1>>d2;
        G.arr[d1]=insert(G.arr[d1],d2);
    }
    for(int i=0;i<G.v;i++){
        cout<<i<<": "<<"{";print(G.arr[i]);cout<<"}\n";
    }
}
 
int main()
{
    int e,v;
    cin>>e>>v;
    Graph G;
    G.v=v;
    G.arr = new List[v];
    Input(G,e);
    return 0;
}