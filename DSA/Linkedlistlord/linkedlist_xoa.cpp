// xoa tat ca cac node ma co it nhat mot node ben phai co gia tri lon hon
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
    Node* temp=head->next;
    int max=0;
    while(temp){
        if(temp->data>max)  max=temp->data;
        temp=temp->next;
    }
    // xac dinh head
    if(max>head->data){
        while(head->data!=max)
            head=head->next;
    }
    Node* curr = head->next;
    Node* prev = head;
    Node* next = curr->next;
    while(curr){
        max = 0;
        next = curr->next;
        while(next){
            if(next->data>max)  max=next->data;
            next=next->next;
        }
        if(curr->data<max){
            prev->next=curr->next;
            prev=curr;
            curr=curr->next;
        }
        else{
            prev->next=curr;
            prev=curr;
            curr=curr->next;
        }
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
    head =sap_xep(head);
    print(head);
}