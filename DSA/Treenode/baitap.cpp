//https://www.youtube.com/watch?v=t3Du4NMwxog&t=10423s

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* node, int data){
    if(!node){
        Node* temp = new Node;
        temp->data=data;
        return temp;
    }
    if(data > node->data) node->right = insert(node->right,data);
    if(data < node->data) node->left = insert(node->left,data);
    return node;
}
void LNR(Node* node){
    if(node){
        LNR(node->left);
        cout<<node->data<<" ";
        LNR(node->right);
    }
}

void print_one_child_node(Node* node){
    if(node){
        print_one_child_node(node->left);
        if((node->left==NULL&&node->right!=NULL) || (node->left!=NULL&& node->right==NULL))
            cout<<node->data<<" ";
        print_one_child_node(node->right);
    }
}

int dem_node_la(Node* node){
    if (!node) return 0;
    if (node->left==NULL&&node->right==NULL) return 1;
    return dem_node_la(node->left) + dem_node_la(node->right);
}

void in_node_bac_k(Node* node,int k){
    if(!node)
        return;
    if(k==0) cout<<node->data<<" ";
    else{
        in_node_bac_k(node->left,k-1);
        in_node_bac_k(node->right,k-1);
    }
}
Node* delete_min(Node* node){
    if(!node) return node;
    if(node->left) node->left = delete_min(node->left);
    else{
        Node* temp = node;
        node = node->right;
        delete temp;
    }
    return node;
}
int find_max(Node* node){
    while(node->right)
        node=node->right;
    return node? node->data : -1;
}

int special_number(Node* node){
    if(!node) return 0;
    int count = (node->data/100.0<1&&node->data/10.0>=1&&int(node->data/10)*(node->data%10)+node->data%10+int(node->data/10)==node->data)? 1 : 0;
    count+=special_number(node->left);
    count+=special_number(node->right);
    return count;
}


int main(){
    int k,data;cin>>k;
    Node* tree=NULL;
    for(int i=0;i<k;i++){
        cin>>data;
        tree=insert(tree,data);
    }
    print_one_child_node(tree);
}
