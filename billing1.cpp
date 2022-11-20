#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    /* data */
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add_product();
    void edit();
    void remove_product();
    void display_product_list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t________________________________________________\n";
    cout << "                                                \n";
    cout << "\t\t\t*************SUPERMARKET MAIN MENU**************\n";
    cout << "\t\t\t________________________________________________\n";
    cout << "                                                \n";
    cout << "\t\t\t 1)Administrator \n";
    cout << "                                                \n";
    cout << "\t\t\t 2)Buyer \n";
    cout << "                                                \n";
    cout << "\t\t\t 3)Exit \n";
    cout << "                                                \n";
    cout << "\t\t\t Please select any option : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\t\t\t Please Login \n";
        cout << "\n";
        cout << "\t\t\t Enter Your Email : ";
        cin >> email;
        cout << "\t\t\t Enter Your Password : ";
        cin >> password;
        if ((email == "elli@gmail.com" ||email == "elli") && password == "elli123")
        {
            administrator();
        }
        else
        {
            cout << "\n\t\t\t**Invalid email/password**\n";
        }
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);

    default:
        cout << "\n\t\t\t**Please select from the given options**\n";
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\t\t\t***********Administrator Menu*************\n\n";
    cout << "\t\t\t__________________________________________\n\n";
    cout << "\t\t\t 1) Add the product \n\n";
    cout << "\t\t\t 2) Modify the product \n\n";
    cout << "\t\t\t 3) Delete the product \n\n";
    cout << "\t\t\t 4) Back to main menu  \n\n";
    cout << "\t\t\t Please select an option : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add_product();
        break;
    case 2:
        edit();
        break;
    case 3:
        remove_product();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\t\t\tInvalid choice";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\n\n\t\t\t**************Buyer Menu****************\n";
    cout << "\n\t\t\t________________________________________________\n";
    cout << "\n\n\t\t\t 1) Buy the product";
    cout << "\n\n\t\t\t 2) Go back";
    cout << "\n\n\t\t\t 3) Exit";

    cout << "\n\n\t\t\t Please select any option : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\n\t\t\t|| Invalid choice ||\n";
        break;
    }
    goto m;
}

void shopping::add_product()
{
    m:
    fstream data;
    int code;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t|| Follow the instructions to add new product ||\n";
    cout << "\n\n\t\t\t Enter product code of the product : ";
    cin >> pcode;
    cout << "\n\n\t\t\t Enter name of the product : ";
    cin >> pname;
    cout << "\n\n\t\t\t Enter price of the product : $";
    cin >> price;
    cout << "\n\n\t\t\t Enter discount on product : ";
    cin >> discount;

    //if file exists, open the file in reading mode(ios::in)
    data.open("database.txt", ios::in);

    if (!data)
    {
    //if file doesn't exist open the file in append mode(ios::app) and writing mode(ios::out)
        data.open("database.txt", ios::app | ios::out);
        //writing inside the file
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
    }
    else{
       //reding from the existing file or initializing the file
        data >> code >> n >> p >> d; 

        while (!data.eof())
        {
            if (code == pcode)
            {
            //if code matches with existing pcode there's duplicacy
                token++;
            }
            data >> code >> n >> p >> d; //initializing the file
        }
        data.close();

        if (token == 1){
        //there's duplicate data going back to menue
            cout<<"\n\t\t\t** DUPLICATE PRODUCT CODE TRY AGAIN ! **";
            goto m;
        }
        else{
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t\t || Record has been inserted ! ||\n";
}

//product modification
void shopping::edit()
{
    // data & data1 are objects of fstream class
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    int p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\n\t\t\t Product code :";
    cin >> pkey;

    // opening file in read mode
    data.open("database.txt", ios::in);
    if (!data){
        cout << "\n\n\t\t\t|| File doesn't exist ! ||\n";
    }
    else{
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t\t Product's new code :";
                cin >> c;
                cout << "\n\t\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t\t Price : $";
                cin >> p;
                cout << "\n\t\t\t Discount : ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\t\t\t || Record edited ! ||\n";
                token++;
            }
            else{
            //writing to the file    
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            //reading from the file
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "databse.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t || Sorry! record not found ||\n";
        }
    }
}
void shopping::remove_product()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t\t\t Follow the instructions to delete product";
    cout << "\n\n\t\t\t Product code  : ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data1)
    {
        cout << "\t\t\t|| File doesn't exist ||";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\t\t|| Product deleted successfully ||";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "databse.txt");

        if (token == 0)
        {
            cout << "\n\n|| Record not found ||";
        }
    }
}

void shopping::display_product_list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t\t\t________________________________________________\n";
    cout << "\t\t\tProduct no.\t\tName\t\tPrice\n";
    cout << "\t\t\t________________________________________________\n";
    //reading the data from the file
    cout << "\t\t\t ";
    data >> pcode >> pname >> price >> discount;    

    while (!data.eof())
    {
        cout << " "<<pcode << "\t\t\t" << pname << "\t\t" << price << "\n";
        cout << "\t\t\t ";
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100]; // array of product code
    int arrq[100]; // array of product quantity
    char choice;
    int c = 0;
    float amt = 0;
    float disc = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t\t|| RECEIPT ||\n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t ** Empty database **";
    }
    else
    {
        data.close();
        display_product_list();
        cout << "\n\t\t\t________________________________________________\n\n";
        cout << "\t\t\t                Please place the order          \n";
        cout << "\t\t\t________________________________________________\n";

        do
        {
        m:
            cout << "\n\n\t\t\tEnter the Product code :";
            cin >> arrc[c];
            cout << "\n\n\t\t\tEnter the Product quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n\t\t\t|| Duplicate product code. Please try again ||";
                    goto m;
                }
            }
            c++;
            cout << "\n\n\t\t\t Do you want to buy another product ? Press 'y/Y' for yes and 'n/N' for no : ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y' );

        if (choice == 'n' || choice == 'N')
        {
            cout << "\n\n\t\t\t___________________YOUR ORDER DETAILS________________\n";
            cout << "\n\t\t\tProduct No.\t Product Name\t Quantity\tDiscounted price\n";

            for (int i = 0; i < c; i++)
            {
                data.open("database.txt", ios::in);
                data >> pcode >> pname >> price >> disc; // txt file initialization
                while (!data.eof())
                {
                    if (arrc[i] == pcode)
                    {
                        amt = price * arrq[i];
                        disc = amt - (amt * disc / 100);
                        total += disc;
                        cout << "\n"<< "\t\t\t" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << amt;
                    }
                    data >> pcode >> pname >> price >> disc;
                }
                data.close();
            }
            cout << "\n\t\t\t________________________________________________\n";
            cout << "\n\t\t\t Total Amount : " << total<<"$";
            cout << "\n\t\t\t________________________________________________\n";
        }
        
        
    }
}

int main()
{
    shopping s;
    s.menu();
}