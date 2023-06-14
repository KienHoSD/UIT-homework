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
void print(const Graph& G){
    int k;cin>>k;
    int nuabacngoai=0;
    int nuabactrong=0;
    Node* temp=G.arr[k].head;
    while(temp){
        nuabacngoai++;
        temp=temp->next;
    }
    for(int i=0;i<G.v;i++){
        if(i!=k){
            Node* temp=G.arr[i].head;
            while(temp){
                if(temp->info==k)
                    nuabactrong++;
                temp=temp->next;
            }
        }
    }
    if(nuabacngoai||nuabactrong)
        cout<<"Nua bac ngoai: "<<nuabacngoai<<"\nNua bac trong: "<<nuabactrong;
    else cout<<"No find";
}
void Input(Graph G, int e){
    int d1,d2;
    for(int i=0;i<e;i++){
        cin>>d1>>d2;
        G.arr[d1]=insert(G.arr[d1],d2);
    }
    print(G);
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