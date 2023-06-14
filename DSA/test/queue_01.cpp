/*Cài đặt cấu trúc QUEUE để mã hóa 1 chuỗi nhập theo qui ước chuyển đổi các ký tự trong bảng mã ASSCII và các ký tự giống ở gần nhau sẽ được gom chung như sau:

VD1: chuỗi s="aaa" --> "973"

Giải thích kết quả "973" --> '97' là chuyển đổi của 'a' và '3' là do có 3 ký tự a liền kề nhau.

VD2: chuỗi s="aabbb" --> "972983"

Giải thích kết quả "972983" --> gồm "972" và "983" trong đó:

"972" --> '97' là chuyển đổi của 'a' và '2' là do có 2 ký tự a liền kề nhau

("972" là mã hóa của "aa")

"983" --> '98' là chuyển đổi của 'b' và '3' là do có 3 ký tự b liền kề nhau

("983" là mã hóa của "bbb")*/
#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Queue
struct Queue{
	node* head;
	node* tail;
};
void CreateEmptyQueue(Queue &l)
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
void insertNode(Queue& L, int data){
    if(!L.head){
        node* temp = CreateNode(data);
        L.head=temp;
        L.tail=temp;
        return;
    }
    node* prev = L.head;
    while(prev->next) prev=prev->next;
    node* newNode = CreateNode(data);
    prev->next=newNode;
}
int concat(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s = s1 + s2;
    int c = stoi(s);
    return c;
}
void CreateQueue(Queue& L){
    string temp; cin>>temp;
    int count=1;
    for(int i=0;temp[i];i++){
        if(temp[i]==temp[i+1]) count++;
        else{
            insertNode(L,concat((int)temp[i],count));
            count=1;
        }
    }
}
void PrintQueue(Queue l)
{
     for(node*p=l.head; p!=NULL; p=p->next)
        cout<<p->info;
}
int main() {
    Queue L;
    CreateEmptyQueue(L);
    CreateQueue(L);
    PrintQueue(L);
    return 0;
}
