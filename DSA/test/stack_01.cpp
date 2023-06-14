/*Nhập lần lượt từng giá trị cho dãy số nguyên A và chỉ dừng nhập nếu giá trị được nhập bằng -1 và không tính số -1

Cài đặt cấu trúc STACK để chứa các phần tử là số nguyên tố của dãy số nguyên A.

Qui ước  trong stack không chứa phần tử có giá trị trùng nhau nên trước khi thêm 1 phần tử X vào stack phải kiểm tra trong stack chưa có phần tử nào có giá trị bằng X thì mới được thêm vào.

VD: dãy số nguyên A gồm {1,2,3,2,1} --> trong đó có 3 giá trị là số nguyên tố 2,3,2 (số 2 xuất hiện 2 lần) nên kết quả thêm vào stack thì stack chỉ có 2 phần tử là 2 và 3
INPUT 

    Nhập lần lượt giá trị các phần tử của dãy số nguyên A.  

OUTPUT

Xuất ra các phần tử của Stack*/

#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Stack 
struct Stack {
	node* head;
	node* tail;
};
void CreateEmptyStack(Stack &l)
{
    l.head=NULL;
    l.tail=NULL;
}
node* CreateNode(int x)
{
    node* p = new node();
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}
//###INSERT CODE HERE -
#include <map>
void insert_node(Stack& L, int data){
	if(!L.head){
		node* temp = CreateNode(data);
		L.head=temp;
		L.tail=temp;
		return;
	}
	node* prev = L.head;
	while(prev->next)
		prev=prev->next;
	node* newnode = CreateNode(data);
	prev->next = newnode;
}
bool isPrime(int number){
    if (number == 1)
        return false;
    for(int i=2;i*i<number;i++)
        if(number%i==0) return false;
    return true;
}
void CreateStack(Stack& L){
    int nhap; cin>>nhap;
    map<int,bool> already_in_stack;
    while(nhap!=-1){
        if(already_in_stack[nhap]==false&&isPrime(nhap)){
            insert_node(L,nhap);
            already_in_stack[nhap]=true;
        }
        cin>>nhap;
    }
}
void PrintStack(const Stack& L){
    if(!L.head){
        cout<<"No SNT";
        return;
    }
    node* temp = L.head;
    while(temp){
        cout<<temp->info<<' ';
        temp=temp->next;
    }
}
int main() {
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);
    return 0;
}
