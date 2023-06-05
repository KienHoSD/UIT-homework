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

Node* sap_xep(Node* head){
    int sonode=0;
    Node* temp=head;
    while(temp){
        ++sonode;
        temp=temp->next;
    }
    if(sonode%2==0){
        Node* le = head;
        Node* chan= head->next;
        Node* noi = head->next;
        temp=le->next->next;
        while(temp){
            le->next=le->next->next;
            chan->next=chan->next->next;
            le=le->next;
            chan=chan->next;
            temp=le->next->next;
        }
        le->next=noi;
    }
    else{
        Node* le = head;
        Node* chan= head->next;
        Node* noi = head->next;
        temp=chan->next;
        while(temp){
            le->next=le->next->next;
            chan->next=chan->next->next;
            le=le->next;
            chan=chan->next;
            temp=le->next;
        }
        le->next=noi;
    }
    return head;
}
int main(){
    Node* head = NULL;
    int n,temp;cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        pushback(head,temp);
    }
    head = sap_xep(head);
    print(head);
}
