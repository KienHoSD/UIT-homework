#include <iostream>
#include <string>
using namespace std;

struct QNode {
    string data;
    QNode* next;
    QNode(string d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode* front, * rear;
    Queue() { front = rear = NULL; }

    void enQueue(string x)
    {

        // Create a new LL node
        QNode* temp = new QNode(x);

        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;

        // Store previous front and
        // move front one node ahead
        QNode* temp = front;
        front = front->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};
void removeDupWord(string str,Queue queue)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            cout << word << endl;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    queue.enQueue(word);
}
int main() {
    Queue queue;
    string str;
    getline(cin, str);
    removeDupWord(str, queue);
    
}
