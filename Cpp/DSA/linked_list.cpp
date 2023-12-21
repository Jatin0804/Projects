#include <iostream>
using namespace std;
#include<bits\stdc++.h>

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

class ll
{
private:
    node *head;
    node *tail;
    int length;

public:
    ll(int value)
    {
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
        length = 1;
        cout << "Linked list created with value : " << value << endl;
    }

    ~ll()
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
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
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

    void insert(int index,int value)
    {
        if (index < 0 || index > length)
        {
            cout << "The entry is not possible."
                    "\nTry again.!!!!"<< endl;
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
                tail = newnode;
            }
            length++;
            cout << value << " inserted at index " << index << endl;
            return;
        }

        node *newnode = new node(value);
        node *temp = get(index - 1);
        newnode->next = temp->next;
        temp->next = newnode;
        length++;
        cout << value << " inserted at index " << index << endl;
        return;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            cout<<"Deletion not possible because idex value is not present."<<endl;
            return ;
        }
        if (length == 0)
        {
            cout<<"Deletion of node not possible because no node is available."<<endl;
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
            }
            delete temp;
            cout<<"Deletion of starting node is done."<<endl;
            length--;
            return;
        }
        if (index == length - 1)
        {
            node *temp = head;
            if (length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                node *pre = head;
                while (temp->next)
                {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            cout<<"Deletion of last node is completed."<<endl;
            length--;
            return;
        }

        node *prev = get(index - 1);
        node *temp = prev->next;

        prev->next = temp->next;
        delete temp;
        cout<<"Deletion of node at index "<<index<<" is done."<<endl;
        length--;
        return;
    }

    /*void deleteNode(int index)
    {
        if (index < 0 || index >= length)
            return;
        if (index == 0)
            return deleteFirst();
        if (index == length - 1)
            return deleteLast();

        Node *prev = get(index - 1);
        Node *temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }*/

    /*void reverselist()
    {
        node *temp = head;
        head = tail;
        tail = temp;
        node *after = temp->next;
        node *before = nullptr;
        for (int i = 0; i < length; ++i)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }*/

    void reverse()
    {
        node *temp = head;
        head = tail;
        tail = temp;
        node *after = temp->next;
        node *before = nullptr;
        for (int i = 0; i < length; ++i)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    node *findMiddleNode()
    {
        int count = 0;
        node *temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }
        int middle = count / 2;

        node *temp1 = head;
        for (int i = 0; i < middle; i++)
        {
            temp1 = temp1->next;
        }

        return temp1;
    }

    node *findMiddleNode2()
    {
        // Initialize slow and fast pointers to head
        node *slow = head;
        node *fast = head;

        // Traverse the list until fast reaches the end
        while (fast != nullptr && fast->next != nullptr)
        {
            // Move slow pointer one step forward
            slow = slow->next;

            // Move fast pointer two steps forward
            fast = fast->next->next;
        }

        // When the loop ends, slow points to the middle
        return slow;
    }

   //To check if the list has any loop
    bool hasLoop()
    {
        node *slow = head;
        node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    //function to return kth node from last of list
    node *findKthFromEnd(int k)
    {
        //int length;
        node *temp = head;
        /*while (temp)
        {
            length++;
        }*/
        if (k > length)
        {
            cout<<"\nkth node from last is larger than length";
            return nullptr;
        }
        else
        {
            int i = length - k;
            temp = head;
            for (int j = 0; j < i; j++)
            {
                temp = temp->next;
            }
            return temp;
        }
    }

    // Function to find the kth node from the end of the list
    node *findKthFromEnd2(int k)
    {
        // Initialize slow and fast pointers to head
        node *slow = head;
        node *fast = head;

        // Move the fast pointer k steps ahead
        for (int i = 0; i < k; ++i)
        {
            // If fast reaches the end, k is too large
            if (fast == nullptr)
            {
                return nullptr;
            }
            // Move fast to the next node
            fast = fast->next;
        }

        // Traverse the list until fast reaches the end
        while (fast != nullptr)
        {
            // Move slow and fast pointers to the next nodes
            slow = slow->next;
            fast = fast->next;
        }

        // Return the slow pointer, now at the kth node
        // from the end of the list
        return slow;
    }

    //function to reverse list between to index values
    void reverseBetween(int m, int n)
    {
        // Return if the list is empty
        if (head == nullptr)
            return;

        // Create a dummy node for easier head manipulation
        node *dummy = new Node(0);
        dummy->next = head;
        node *prev = dummy;

        // Move prev to the node just before the sublist
        for (int i = 0; i < m; i++)
        {
            prev = prev->next;
        }

        // Set current to m-th node
        node *current = prev->next;

        // Reverse segment between m and n
        for (int i = 0; i < n - m; i++)
        {
            node *temp = current->next; // Temp node to move
            current->next = temp->next; // Remove temp from position
            temp->next = prev->next;    // Prepare temp for insertion
            prev->next = temp;          // Insert temp at reversed start
        }

        // Update head of the list
        head = dummy->next;

        // Delete dummy node to prevent memory leaks
        delete dummy;
    }

    // function to Implement the partitionList member function for the LinkedList class, which partitions the list 
    //such that all nodes with values less than x come before nodes with values greater than or equal to x.
    void partitionList(int x)
    {
        // Return if the list is empty
        if (head == nullptr)
            return;

        // Create dummy nodes for two lists
        node dummy1(0);
        node dummy2(0);
        // Initialize pointers for two lists
        node *prev1 = &dummy1;
        node *prev2 = &dummy2;
        // Initialize the current pointer
        node *current = head;

        // Iterate through the list
        while (current != nullptr)
        {
            // If the value is less than x
            if (current->value < x)
            {
                prev1->next = current;
                prev1 = current;
            }
            else
            { // If the value is >= x
                prev2->next = current;
                prev2 = current;
            }
            // Move to the next node
            current = current->next;
        }

        // Terminate the second list
        prev2->next = nullptr;
        // Connect the two lists
        prev1->next = dummy2.next;
        // Update the head of the list
        head = dummy1.next;
    }


    //function to remove duplicate from list
    //without using set
    void removeDuplicates()
    {
        node *current = head; // Start at the head of the list
        while (current != nullptr)
        {                           // Iterate through the list
            node *runner = current; // Secondary iterator
            // Check all subsequent nodes
            while (runner->next != nullptr)
            {
                // If a duplicate is found
                if (runner->next->value == current->value)
                {
                    node *temp = runner->next; // Temp node for deletion
                    // Bypass the node to be deleted
                    runner->next = runner->next->next;
                    delete temp; // Delete the node
                    length -= 1; // Decrement length
                }
                else
                {
                    runner = runner->next; // Move to next node
                }
            }
            current = current->next; // Move to next node
        }
    }
    
    //using set
    void removeDuplicates()
    {
        unordered_set<int> values; // Stores unique list values
        node *previous = nullptr;  // Points to previous node
        node *current = head;      // Starts at head of list

        // Traverse list until end (nullptr)
        while (current != nullptr)
        {

            // If value exists in set
            if (values.find(current->value) != values.end())
            {

                // Bypass current node
                previous->next = current->next;

                // Delete current node
                delete current;

                // Move to next node
                current = previous->next;

                // Decrement list length
                length -= 1;
            }
            else
            {
                // Insert value in set
                values.insert(current->value);

                // Update previous to current node
                previous = current;

                // Move to next node
                current = current->next;
            }
        }
    }

};

int main(void)
{
    int value;
    cout << "Enter the value : ";
    cin >> value;
    ll *myll = new ll(value);
    
    myll->insert(0,3);
    myll->insert(0, 5);
    myll->insert(0, 2);
    myll->insert(0, 6);
    myll->insert(3, 8);
    myll->insert(1, 10);
    myll->insert(2, 20);

    cout << "\nLL before deleteNode():\n";
    myll->printList();

    myll->deleteNode(2);
    cout << "\nLL after deleteNode() in middle:\n";
    myll->printList();

    myll->deleteNode(0);
    cout << "\nLL after deleteNode() of first node:\n";
    myll->printList();

    myll->deleteNode(2);
    cout << "\nLL after deleteNode() of last node:\n";
    myll->printList();

    cout<<"\nList before reverse : \n";
    myll->printList();
    cout << "\nReverse of list : \n";
    myll->reverse();
    myll->printList();

    auto middle= myll->findMiddleNode();
    cout<<"\n The middle node of the list is : "<<middle->value;

    auto k=myll->findKthFromEnd(6);
    cout<<"\nThe kth node from last of list is : "<< k->value;

    auto k = myll->findKthFromEnd(2);
    cout << "\nThe kth node from last of list is : " << k->value;

    return 0;
}