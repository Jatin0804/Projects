#include<iostream>
using namespace std;
#include<queue>

class node
{
    public:
    int value;
    node* right;
    node* left;

    node(int value)
    {
        this->value=value;
        left=nullptr;
        right=nullptr;
    }
};

class BST
{
    public:
    node* root;

    BST()
    {
        root=nullptr;
    }

    BST(int value)
    {
        node* newnode= new node(value);
        root=newnode;
    }

    void destroy(node* current)
    {
        if(current->right) 
            destroy(current->right);
        if(current->left)
            destroy(current->left);
        delete current;
    }
    ~BST()
    {
        destroy(root);
    }

    bool insert(int value)
    {
        node* newnode=new node(value);
        if(root==nullptr)
        {
            root=newnode;
            return true;
        }
        node* temp=root;
        while(true)
        {
            if(newnode->value == temp->value)
                return false;
            else if(newnode->value < temp->value)
            {
                if(temp->left == nullptr)
                {
                    temp->left=newnode;
                    return true;
                }
                temp=temp->left;
            }
            else
            {
                if(temp->right == nullptr)
                {
                    temp->right=newnode;
                    return true;
                }
                temp=temp->right;
            }
        }
    }

    bool contains(int value)
    {
        //this if is optional 
        if(root == nullptr)
            return false;
        
        node* temp=root;
        while(temp)
        {
            if(value < temp->value)
                temp=temp->left;
            else if(value > temp->value)
                temp=temp->right;
            else 
                return true;
        }
        return false;
    }

    
    void present(int value)
    {
        if(root == nullptr)
        {
            cout<<"There are no values in tree.";
            return ;
        }

        node* temp=root;
        while(temp)
        {
            if(value == temp->value)
            {
                cout<<value<<" is present in tree.";
                return;
            }
            if(value < temp->value)
                temp=temp->left;
            else if(value > temp->value)
                temp=temp->right;
        }
        cout<<value<< " is not present in tree.";
    }

    void BFS()
    {
        queue<node *> myqueue;
        myqueue.push(root);

        while (myqueue.size() > 0)
        {
            node *current = myqueue.front();
            myqueue.pop();
            cout << current->value << " ";
            if (current->left)
                myqueue.push(current->left);
            if (current->right)
                myqueue.push(current->right);
        }
    }

    void DFSPreOrder(node *current)
    {
        cout << current->value << " ";
        if (current->left)
            DFSPreOrder(current->left);
        if (current->right)
            DFSPreOrder(current->right);
    }

    void DFSPredOrder()
    {
        DFSPreOrder(root);
    }

    void DFSPostOrder(node *current)
    {
        if (current->left)
            DFSPostOrder(current->left);
        if (current->right)
            DFSPostOrder(current->right);

        cout << current->value << " ";
    }

    void DFSPostdOrder()
    {
        DFSPostOrder(root);
    }

    void DFSInOrder(node *current)
    {
        if (current->left)
            DFSInOrder(current->left);

        cout << current->value << " ";

        if (current->right)
            DFSInOrder(current->right);
    }

    void DFSInOrder()
    {
        DFSInOrder(root);
    }
};

int main(void)
{
    // BST* myBST = new BST(); also true
    BST *myBST=new BST(50);

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);

    cout << "Root: " << myBST->root->value;

    cout << endl << "\nContains 27: " << myBST->contains(27);
    cout << "\nContains 17: " << myBST->contains(17);

    cout << endl << "\nContains 27: " ;
    myBST->present(27);
    cout << "\nContains 17: " ;
    myBST->present(17);

    cout << endl << endl << "BST using Binary First search : ";
    myBST->BFS();

    cout << endl << endl << "BST using Depth First search : \nPreOrder : ";
    myBST->DFSPredOrder();

    cout << endl << "PostOrder : ";
    myBST->DFSPostdOrder();

    cout << endl << "InOrder : ";
    myBST->DFSInOrder();

    return 0;
}