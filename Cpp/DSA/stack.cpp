#include<iostream>
using namespace std;

class node
{
    public:
    int value;
    node* next;

    node(int value)
    {
        this->value=value;
        next=nullptr;
    }
};

class stack
{
    private:
    node* top;
    int height;

    public:
    stack(int value)
    {
        node* newnode=new node(value);
        top = newnode;
        height=1;
    }

    ~stack()
    {
        node* temp=top;
        while(top)
        {
            top=top->next;
            delete temp;
            temp=top;
        }
    }

    void printStack()
    {
        node* temp=top;
        while(temp)
        {
            cout<<temp->value<<endl;
            temp=temp->next;
        }
    }

    void getTop()
    {
        if(top==nullptr)
            cout<<"Top : Nullptr."<<endl;
        else
            cout<<"Top : "<<top->value<<endl;
    }

    int topValue()
    {
        if (top)
            return top->value;
        return INT32_MIN;
    }

    void getHeight()
    {
        cout<<"Height is : "<<height<<endl;
    }

    bool isEmpty()
    {
        if(height==0)
            return true;

        return false;
    }

    void push(int value)
    {
        node* newnode=new node(value);
        newnode->next=top;
        top=newnode;
        height++;
        cout<<"Pushed value is : "<<value<<endl;
    }

    void pop()
    {
        if(height==0)
        {
            cout<<"Not possible, height is 0."<<endl;
            return ;
        }

        node* temp=top;
        int poppedValue=top->value;
        top=top->next;
        delete temp;
        height--;
        cout<<"Popped value is : "<<poppedValue<<endl;

        return ;
    }

};

int main(void)
{
    stack* myStack=new stack(5);

    cout << "Stack before push(1):\n";
    cout << "---------------------\n";
    myStack->printStack();
    cout << endl;

    myStack->getTop();
    myStack->getHeight();

    myStack->push(1);

    cout << "\n\nStack after push(1):\n";
    cout << "--------------------\n";
    myStack->printStack();
    cout << endl;

    myStack->getTop();
    myStack->getHeight();

    myStack->push(8);

    cout << "\n\nStack after push(8):\n";
    cout << "--------------------\n";
    myStack->printStack();
    cout << endl;

    myStack->getTop();
    myStack->getHeight();

    cout<<endl;
    myStack->pop();
    myStack->pop();
    myStack->pop();
    myStack->pop();

    return 0;
}