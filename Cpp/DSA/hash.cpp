#include<iostream>
using namespace std;
#include<vector>
#include<string>

class node
{
     public:
     string key;
     int value;
     node* next;

     node(string key,int value)
     {
        this->key=key;
        this->value=value;
        next=nullptr;
     }
};

class Hashtable
{
    private:
    static const int SIZE=7;
    node* datamap[SIZE];

    public:
    ~Hashtable()
    {
        for(int i=0;i<SIZE;i++)
        {
            node* head=datamap[i];
            node* temp=head;
            while(head)
            {
                head=head->next;
                delete temp;
                temp=head;
            }
        }
    }

    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i <= int(key.length()); i++)
        {
            int asciivalue = int(key[i]);
            hash = (hash + asciivalue * 23) % SIZE;
        }
        return hash;
    }

    void printTable()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<" : "<<endl;
            if(datamap[i])
            {
                node* temp=datamap[i];
                while(temp)
                {
                    cout<<"  {"<<temp->key<<", "<<temp->value<<" }"<<endl;
                    temp=temp->next;
                }
            }
        }
    }

    void set(string key, int value)
    {
        int index=hash(key);
        node* newnode=new node(key,value);
        if(datamap[index]==nullptr)
        {
            datamap[index]=newnode;
        }
        else
        {
            node* temp=datamap[index];
            while(temp->next != nullptr)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }

    int get(string key)
    {
        int index=hash(key);
        node* temp=datamap[index];
        while(temp!=nullptr)
        {
            if(temp->key==key)
                return temp->value;
            temp=temp->next;
        }
        return 0;
    }

    vector<string> keys()
    {
        vector<string> allkeys;
        for(int i=0;i<SIZE;i++)
        {
            node* temp=datamap[i];
            while(temp != nullptr)
            {
                allkeys.push_back(temp->key);
                temp=temp->next;
            }
        }
        return allkeys;
    }
};

int main(void)
{
    Hashtable *myHashTable = new Hashtable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);

    // HASH FUNCTION MUST BE SET TO PUBLIC FOR THESE LINES TO WORK:
    cout << "Hash values of keys are : \n";
    cout << "nails: " << myHashTable->hash("nails");
    cout << "\nbolts: " << myHashTable->hash("bolts");
    cout << "\nlumber: " << myHashTable->hash("lumber");
    cout << "\ntile: " << myHashTable->hash("tile");
    cout << "\nscrews: " << myHashTable->hash("screws");

    cout<<endl<<endl<<"The Hash Table is : \n";

    myHashTable->printTable();

    cout << endl << "Using get function to get value of keys :\n";
    cout << "Lumber: " << myHashTable->get("lumber") << endl;
    cout << "Bolts: " << myHashTable->get("bolts") << endl;

    vector<string> myKeys = myHashTable->keys();
    cout<<endl<<"All keys are : ";

    for (auto key : myKeys)
    {
        cout << key << " ";
    }
    cout<<endl;

    return 0;
}