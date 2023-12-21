#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class node
{
public:
    int value;
    node *next;
    node *prev;

    node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class dll
{
private:
    node *head;
    node *tail;
    int length;

public:
    dll(int value)
    {
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
        length = 1;
        cout << "Doubly Linked list created with value : " << value << endl;
    }

    ~dll()
    {
        node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        if (head == nullptr)
            cout << "Head : nullptr" << endl;
        else
            cout << "Head : " << head->value << endl;
    }

    void getTail()
    {
        if (tail == nullptr)
            cout << "Tail : nullptr" << endl;
        else
            cout << "Tail : " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Length  : " << length << endl;
    }

    node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        node *temp = head;
        if(index<length/2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp=tail;
            for (int i = length-1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value)
    {
        node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    void insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            cout << "The entry is not possible."
                    "\nTry again.!!!!"
                 << endl;
            return;
        }

        if (index == 0)
        {
            node *newnode = new node(value);
            if (length == 0)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            length++;
            cout << value << " inserted at index 0 " << endl;
            return;
        }
        if (index == length)
        {
            node *newnode = new node(value);
            if (length == 0)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
            }
            length++;
            cout << value << " inserted at index " << index << endl;
            return;
        }

        node *newnode = new node(value);
        node *before = get(index - 1);

        newnode->next = before->next;
        newnode->prev = before;
        before->next->prev=newnode;
        before->next = newnode;
        length++;
        cout << value << " inserted at index " << index << endl;
        return;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Deletion not possible because idex value is not present." << endl;
            return;
        }
        if (length == 0)
        {
            cout << "Deletion of node not possible because no node is available." << endl;
            return;
        }
        if (index == 0)
        {
            node *temp = head;
            if (length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            cout << "Deletion of starting node is done." << endl;
            length--;
            return;
        }
        if (index == length - 1)
        {
            node *temp = tail;
            if (length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            cout << "Deletion of last node is completed." << endl;
            length--;
            return;
        }

        node *temp = get(index);
        
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        cout << "Deletion of node at index " << index << " is done." << endl;
        length--;
        return;
    }

    // to swap first and last value of list
    void swapFirstLast()
    {
        int temp = head->value;
        head->value = tail->value;
        tail->value = temp;
        return;
    }

    // to reverse the whole list and its attributes
    void reverse()
    {
        // Initialize current pointer to head node
        node *current = head;

        // Initialize temp pointer to nullptr
        node *temp = nullptr;

        // Iterate through the list
        while (current != nullptr)
        {
            // Save the previous node pointer in temp
            temp = current->prev;

            // Swap the previous and next pointers of the current node
            current->prev = current->next;
            current->next = temp;

            // Move current pointer to the next node in reversed order
            current = current->prev;
        }

        // Swap head and tail pointers
        temp = head;
        head = tail;
        tail = temp;
    }

    /*

    // segmantation fault
    void reverse()
        {
            Node* temp=head;
            Node* after=temp->next;
            Node *before=nullptr;
            head=tail;
            tail=temp;
            for(int i=0;i<length;i++)
            {
                if(i==0)
                {
                    tail->next=nullptr;
                    tail->prev=after;
                    before=temp;
                    temp=after;
                    after=after->next;
                    continue;
                }
                if(i==length-1)
                {
                    head->next=before;
                    head->prev=nullptr;
                    continue;
                }
                temp->next=before;
                temp->prev=after;
                before=temp;
                temp=after;
                after=after->next;
            }
        }
    */

   // to check if list is palindrome
    bool isPalindrome()
    {
        node *temp = head;
        node *temp1 = tail;

        if (length <= 1)
            return true;

        for (int i = 0; i < length / 2; i++)
        {
            if (temp->value != temp1->value)
            {
                return false;
            }
            temp = temp->next;
            temp1 = temp1->prev;
        }
        return true;
    }

    // to swap 2 concurrent values in pairs
    void swapPairs()
    {
        // Create a dummy node with value 0
        node dummy(0);
        // Set dummy's next to head of list
        dummy.next = head;
        // Set prev as the address of dummy
        node *prev = &dummy;

        // Iterate while head and head's next exist
        while (head != nullptr && head->next != nullptr)
        {
            // Assign first and second nodes
            node *firstNode = head;
            node *secondNode = head->next;

            // Update next pointers for swapping
            prev->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            // Update prev pointers for swapping
            secondNode->prev = prev;
            firstNode->prev = secondNode;
            // Update prev pointer of next node if exists
            if (firstNode->next != nullptr)
            {
                firstNode->next->prev = firstNode;
            }

            // Move head and prev pointers forward
            head = firstNode->next;
            prev = firstNode;
        }

        // Update head of the list
        head = dummy.next;
        // Set prev of new head to nullptr
        if (head)
            head->prev = nullptr;
    }
};

int main()
{

    dll *myDll = new dll(1);
    myDll->insert(0, 3);
    myDll->insert(0, 5);
    myDll->insert(0, 2);
    myDll->insert(0, 6);
    myDll->insert(3, 8);
    myDll->insert(1, 10);
    myDll->insert(2, 20);

    cout << "\nLL before deleteNode():\n";
    myDll->printList();

    myDll->deleteNode(2);
    cout << "\nLL after deleteNode() in middle:\n";
    myDll->printList();

    myDll->deleteNode(0);
    cout << "\nLL after deleteNode() of first node:\n";
    myDll->printList();

    myDll->deleteNode(2);
    cout << "\nLL after deleteNode() of last node:\n";
    myDll->printList();

    return 0;
}