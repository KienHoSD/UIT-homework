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
void Push(Stack& L, int x) {
    node* temp = CreateNode(x);
    if (L.head == NULL) {
        L.head = temp;
        L.tail = L.head;
    }
    else {
       temp->next = L.head;
       L.head = temp;
    }
}
bool Empty(Stack L) {
    if (L.head == NULL) return true;
    else return false;
}
bool Pop(Stack& L, int &result) {
    node* p;
    if (Empty(L) == false) {
        if (L.head != NULL) {
            p = L.head;
            result = p->info;
            L.head = L.head->next;
            if (L.head == NULL) L.tail = NULL;
            return 1;
        }
    }
    return 0;
}
bool CheckNguyenTo(int n) {
    if (n <= 1) return false;
    else {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
void RemoveDuplicate(Stack& L) {
    node* ptr1, * ptr2, * dup;
    ptr1 = L.head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->info == ptr2->next->info) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
            }
            else ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void CreateStack(Stack& L) {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;
        if (CheckNguyenTo(n) == true)
            Push(L, n);
        else if (CheckNguyenTo(n) == false) continue;
    }
    if (L.head == NULL) return;
    RemoveDuplicate(L);
}
void PrintStack(Stack L) {
    if (Empty(L) == true) cout << "No SNT";
    else for (node* i = L.head; i != NULL; i = i->next) cout << i->info << ' ';
}
int main() {
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);
    return 0;
}
