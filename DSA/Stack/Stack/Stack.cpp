#include <iostream>
#define MAX 10000
struct Stack {
    int a[MAX];
    int t;
};
void CreateStack(Stack& s) {

    s.t = -1;

}
bool isEmpty(Stack s) { //Stack có rỗng hay không
    if (s.t == -1)
        return 1;
    return 0;
}
bool isFull(Stack s) {
    if (s.t >= MAX)
        return 1;
    return 0;
}
bool Push(Stack &s, int x) {
    if (!isFull(s)) {
        s.a[++s.t] = x;
        return 1;
    }
    return 0;
}   
bool Pop(Stack& s) {
    if (!isEmpty(s)) {
        s.a[s.t--] = NULL;
        return 1;
    }
    return 0;
}
int Top(Stack s) {
    if (!isEmpty(s)) {
        return s.a[s.t];
    }
    return -1;
}
int main()
{
    std::cout << "Hello World!\n";
}
