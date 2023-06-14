#include <iostream>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

void CreateTree(TREE& T) {
    T = NULL;
}

TNODE* CreateNode(int x) {
    TNODE* p = new TNODE();
    if (p == NULL)
        exit(1);
    else {
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

int Insert(TREE& T, int x) {
    if (T) {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void Input(TREE& T) {
    int x = 0;
    cin >> x;
    while (x != -1) {
        Insert(T, x);
        cin >> x;
    }
}

TNODE* SearchNode(TREE T, int x) {
    if (T != NULL) {
        if (T->key == x) return T;
        else if (x > T->key) return SearchNode(T->pRight, x);
        else return SearchNode(T->pLeft, x);
    }
    return NULL;
}

int treeHeight(TNODE* T) {
    if (!T) return -1;
    int a = treeHeight(T->pLeft);
    int b = treeHeight(T->pRight);
    return (a > b ? a : b) + 1;
}

void LNRsolve(TREE T, int x) {
    if (T) {
        LNRsolve(T->pLeft, x);
        if (T->key != x) {
            cout << T->key << " ";
        }
        LNRsolve(T->pRight, x);
    }
}

void LNR(TREE T) {
    if (T) {
        LNR(T->pLeft);
        cout << T->key << " ";
        LNR(T->pRight);
    }
}

void Function(TREE T) {
    Input(T);
    int x;
    cin >> x;

    TNODE* node = SearchNode(T, x);
    if (node == NULL) {
        cout << "No Find";
        return;
    }

    if (node->pLeft == NULL && node->pRight == NULL) {
        cout << "No descendant";
        return;
    }

    LNRsolve(node, x);
    if (node->key != x) {
        cout << x << " ";
    }
}

int main() {
    TREE T;
    CreateTree(T);
    Function(T);
    return 0;
}
