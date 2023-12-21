#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void rem();
        void edit();
        void list();
        void receipt();
};

void shopping :: menu()
{
start:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|     SuperMarket Main Menu     |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  1) Administrator.            |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  2) Buyer.                    |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  3) Exit.                     |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";

    cout << "\n\t\t\t\t\t Please Select. :   \n";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "\t\t\t Please Login. \n";
            cout << "\t\t\t Enter E-mail :  \n";
            cin >> email;
            cout << "\t\t\t Enter Password :  \n";
            cin >> password; 

            if(email == "admin@gmail.com" && password == "admin@123" )
            {
                admin();
            }
            else{
                cout << "Invalid Credentials."<<endl;
            }

            break;
        }

        case 2:
        {
            buyer();

            break;
        }

        case 3:
        {
            exit(0);

            break;
        }

        default:
            cout<<"Please Select from the given options."<<endl;
    }
    goto start;
}

void shopping :: admin()
{
start : 
    int choice;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|          Admin Menu           |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  1) Add the Product.          |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  2) Modify the Product.       |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  3) Delete the Product.       |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  4) Back to Main Menu.        |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";

    cout << "\n\t\t\t\t\t Please Select Your Choice :   \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }

    case 2:
    {
        edit();
        break;
    }

    case 3:
    {
        rem();
        break;
    }

    case 4:
    {
        menu();
        break;
    }

    default:
        cout << "Invalid Choice.  \nPlease Select from the given options." << endl;
    }
    
    goto start;
}

void shopping ::buyer()
{
start:
    int choice;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|          Buyer Menu           |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  1) Buy Product.              |\n";
    cout << "\t\t\t\t\t\t|                               |\n";
    cout << "\t\t\t\t\t\t|  2) Go Back.                  |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";

    cout << "\n\t\t\t\t\t Please Select Your Choice :   \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        receipt();
        break;
    }

    case 2:
    {
        menu();
        break;
    }

    default:
        cout << "Invalid Choice.  \nPlease Select from the given options." << endl;
    }

    goto start;
}

void shopping :: add()
{
start:
    fstream data;
    int c;
    int token  = 0;
    float p ;
    float d;
    string n;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|      Add New Product.         |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";
    
    cout << "\n\n\t Prodcut code of product : \n";
    cin>>pcode;
    cout << "\n\n\t Name of product : \n";
    cin >> pname;
    cout << "\n\n\t Price of product : \n";
    cin >> price;
    cout << "\n\n\t Discount on product : \n";
    cin >> dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else{
        data >> c >> n >> p >> d;
        
        while(!data.eof()){
            
            if(c == pcode)
                token++ ;
            
            data >> c >> n >> p >> d;
        }
        data.close();

    if (token == 1)
        goto start;
    else{

        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    }
    cout<<"\n\n\t Record Inserted!!!."<<endl;
}

void shopping :: edit()
{
    fstream data1, data;

    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|      Modify Record.           |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";

    cout << "\n\t\t\t Product Code : ";
    cin >> pkey ;

    data.open("database.txt", ios::in);

    if(!data){
        cout << "\n\t\t File doesn't exist!!!."<<endl;
    }
    else{

        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while(!data.eof()){

            if(pkey == pcode){

                cout << "\n\n\t Prodcut new code : \n";
                cin >> c;
                cout << "\n\n\t Name of product : \n";
                cin >> n;
                cout << "\n\n\t Price of product : \n";
                cin >> p;
                cout << "\n\n\t Discount on product : \n";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << "\n";

                cout << "\n\n\t  Record Edited.";
                token++;
            }
            else{

                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0)
            cout << "\n\n Record not found. \nSorry.!!";
    }
}

void shopping :: rem()
{
    fstream data, data1;

    int pkey;
    int token = 0;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|      Delete Record.           |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";

    cout << "\n\t\t\t Product Code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\t\t File doesn't exist!!!." << endl;
    }
    else
    {

        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {

            if (pkey == pcode)
            {
                cout << "\n\n\t  Prodcut Deleted Successfully..";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
            cout << "\n\n Record not found. \nSorry.!!";
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios :: in);
    cout << "\n\n|________________________________________________________________|";
    cout << "Product no. \t\t Name \t\t Price "<<endl;
    cout << "\n\n|________________________________________________________________|";

    data >> pcode >> pname >> price >> dis;
    while(!data.eof())
    {
        cout << pcode << "\t\t " << pname << "\t\t " << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }

    data.close();
}

void shopping :: receipt()
{

    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|           Receipt.            |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";

    data.open("database.txt", ios :: in);
    if(!data)
    {
        cout << "\n\n Empty DataBase. ";
    }
    else{
        data.close();

        list();
        cout << "\t\t\t\t\t\t_________________________________\n";
        cout << "\t\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t\t|    Please Place the Order.    |\n";
        cout << "\t\t\t\t\t\t|                               |\n";
        cout << "\t\t\t\t\t\t|_______________________________|\n";

        do{
            start : 

            cout << "\n\n Enter the Product Code : ";
            cin >> arrc[c];
            cout << "\n\nEnter the Product Quantity : ";
            cin >> arrq[c];

            for (int i = 0; i<c ;i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout<<"\n\n Duplicate Product code.\n";
                    cout << "Please Try again.";

                    goto start;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another Product : \n";
            cout << "If yes (press 'y') else no"; 
            cin>>choice;

        }while(choice == 'y' or choice == 'Y');

        cout << "\t\t\t\t\t\t_________________________________\n";
        cout << "\t\t\t\t\t\t|           Receipt.            |\n";
        cout << "\t\t\t\t\t\t|_______________________________|\n";
        cout << "\n\nProduct No. \t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount\n";

        for (int i = 0 ; i<c ; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while(!data.eof()){

                if(pcode == arrc[i]){

                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;

                    cout << "\n" << pcode << " \t " << pname << " \t " << arrq[i] << " \t " << price << " \t " << amount << " \t " << dis << " \n ";

                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }

    cout << "\t\t\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t\t\t|          Total Amount.        |\n";
    cout << "\t\t\t\t\t\t|          "<<total<<"          |\n";
    cout << "\t\t\t\t\t\t|_______________________________|\n";
}

int main()
{
    shopping s;
    s.menu();
}