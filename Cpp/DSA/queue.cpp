#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;

    node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class queue
{
private:
    node *first;
    node* last;
    int height;

public:
    queue(int value)
    {
        node *newnode = new node(value);
        first = newnode;
        last = newnode;
        height = 1;
    }

    ~queue()
    {
        node *temp = first;
        while (first)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void printqueue()
    {
        node *temp = first;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getfirst()
    {
        if (first == nullptr)
            cout << "First : Nullptr." << endl;
        else
            cout << "First : " << first->value << endl;
    }

    void getLast()
    {
        if (last == nullptr)
            cout << "Last : Nullptr." << endl;
        else
            cout << "Last : " << last->value << endl;
    }

    int firstValue()
    {
        if (first)
            return first->value;
        return INT32_MIN;
    }

    void getHeight()
    {
        cout << "Height is : " << height << endl;
    }

    bool isEmpty()
    {
        if (height == 0)
            return true;

        return false;
    }

    void enqueue(int value)
    {
        node *newnode = new node(value);
        cout << "Enqueued value is : " << value << endl;
        if(height==0)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
        height++;
    }

    void dequeue()
    {
        if (height == 0)
        {
            cout << "Not possible, height is 0." << endl;
            return;
        }

        node *temp = first;
        int dequeuedValue = first->value;
        if(height==1)
        {
            first=nullptr;
            last=nullptr;
        }
        else
        {
            first=first->next;
        }
        delete temp;
        height--;
        cout << "Dequeued value is : " << dequeuedValue << endl;

        return;
    }
};

int main(void)
{
    queue *myqueue = new queue(5);

    cout << "Queue before enqueue(1):\n";
    cout << "---------------------\n";
    myqueue->printqueue();
    cout << endl;

    myqueue->getfirst();
    myqueue->getLast();
    myqueue->getHeight();

    myqueue->enqueue(1);

    cout << "\n\nqueue after enqueue(1):\n";
    cout << "--------------------\n";
    myqueue->printqueue();
    cout << endl;

    myqueue->getfirst();
    myqueue->getLast();
    myqueue->getHeight();

    myqueue->enqueue(8);

    cout << "\n\nqueue after enqueue(8):\n";
    cout << "--------------------\n";
    myqueue->printqueue();
    cout << endl;

    myqueue->getfirst();
    myqueue->getLast();
    myqueue->getHeight();

    cout << endl;
    myqueue->dequeue();
    myqueue->dequeue();
    myqueue->dequeue();
    myqueue->dequeue();

    return 0;
}