#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
    int info;
    NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

//###INSERT CODE HERE -
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(LIST& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}
void AddHead(LIST& L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
void AddTail(LIST& L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void CreateList(LIST& L) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        NODE* temp = CreateNode(x);
        AddTail(L, temp);
    }
}
void SelectionSort(LIST& L) {
    NODE* min;
    for (NODE* i = L.pHead; i != NULL; i = i->pNext) {
        min = i;
        for (NODE* j = i->pNext; j != NULL; j = j->pNext) {
            if (j->info < min->info) min = j;
        }
        swap(i->info, min->info);
    }
}
void Print(const LIST& L) {
    for (NODE* p = L.pHead; p != NULL; p = p->pNext) {
        int temp = p->info % 10;
        int tempp = p->info / 10;
        bool behon = true;
        while (tempp != 0) {
            if (temp <= tempp % 10) {
                behon = false;
                break;
            }   
            temp = tempp % 10;
            tempp =floor(tempp/10);
        }
        if (behon) cout << p->info << " ";
    }
}
void RemoveList(LIST& L) {
    NODE* p;
    while (L.pHead != NULL) {
        p = L.pHead;
        L.pHead = p->pNext;
        delete p;
    }
    L.pTail = NULL;
}

int main()  
{   
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    Print(L);
    return 0;
}