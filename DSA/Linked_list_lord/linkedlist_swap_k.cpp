#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* makeNode(int x){
    Node* temp = new Node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}
void pushfront(Node*& head,int x){
    Node* temp=new Node;
    temp->next=head;
    temp->data=x;
    head=temp;
}
void pushback(Node*& head,int x){
    if(!head){
        pushfront(head, x);
    }
    else{
        Node* temp =head;
        while(temp->next)
            temp=temp->next;
        temp->next=makeNode(x);
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next= NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* swap_k(Node* head,int k){
    Node* prev_x=NULL;
    Node* prev_y=NULL;
    Node* x=head,*y=head;
    Node* dem=head;
    int sonode=0;
    while(dem){
        dem=dem->next;
        sonode++;
    }
    for(int i=1;i<k;i++){
        prev_x=x;
        x=x->next;
    }
    for(int i=1;i<sonode-k+1;i++){
        prev_y=y;
        y=y->next;
    }
    if(prev_x)
        prev_x->next=y;
    if(prev_y)
        prev_y->next=x;
    Node* temp = y->next;
    y->next=x->next;
    x->next= temp;
    if(k==1) head=y;
    if(k==sonode) head=x;
    return head;
}
int main(){
    Node* head = NULL;
    int n,temp;cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        pushback(head,temp);
    }
    int k; cin>>k;
    swap_k(head,k);
    print(head);
}
