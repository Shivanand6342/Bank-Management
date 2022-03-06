#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>

using namespace std;

class name_details
{
public:
    string name, f_name;
    long int ph_no;
    int amount, acc_no;
};


int account_number_generator = rand();
int account_number = account_number_generator, acc_count = 0;

name_details holders[10000];
int temp, temp2, i, j;
long int li_temp;
float bal;
string c_temp;
bool valid;

void instruction();
void createacc();
void addamount();
void withdraw();
void accdetails();
void transaction();
void delete_acc();


int main()
{
    srand(time(0));
    int choice;
    while (1)
    {
        system("CLS");
        instruction();
        cout << "Select your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            createacc();
            break;
        case 2:
            accdetails();
            break;
        case 3:
            addamount();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transaction();
            break;
        case 6:
            delete_acc();
            break;
        case 7:
            cout << "Thank You :)";
            return 0;
        }
        getch();
    }
    return 0;
}

void instruction()
{
    cout << "\n*******************************************\n";
    cout << "\tBANK MANAGEMENT SYSTEM ";
    cout << "\n*******************************************\n\n\n";
    cout << "1. Create a New Account.\n";
    cout << "2. Account Holders Details.\n";
    cout << "3. Add Amount.\n";
    cout << "4. Withdraw.\n";
    cout << "5. Transaction. \n";
    cout << "6. Delete Account.\n";
    cout << "7. Exit\n\n";
}

void createacc()
{
    cout << "Please give necessary info. \n";
    cout << "Enter your name : ";
    fflush(stdin);
    cin.ignore();
    getline(cin, holders[acc_count].name);
    fflush(stdin);
    cout << "Enter your Father name : ";
    getline(cin, holders[acc_count].f_name);
    fflush(stdin);
a:
    cout << "Enter your mobile no. ";
    cin >> holders[acc_count].ph_no;
    li_temp = holders[acc_count].ph_no;
    li_temp = li_temp / 1000000000;
    if (li_temp < 5 || li_temp > 9)
    {
        cout << "Please enter a valid mobile no.\n";
        goto a;
    }
    cout << "Account Created :) \n\n";
    holders[acc_count].acc_no = account_number;
    cout << "Your account number is : " << holders[acc_count].acc_no << endl;
    account_number++;
    acc_count++;
}

void accdetails()
{
    valid = false;
    cout << "Enter your account number : ";
    cin >> temp;
    for (i = 0; i < acc_count; i++)
        if (holders[i].acc_no == temp)
        {
            valid = true;
            break;
        }
    if (!valid || holders[i].acc_no == 0)
    {
        cout << "Enter a valid account number.\n";
        return;
    }
    cout << "Account details of the given account number is given below : \n";
    cout << "Name : " << holders[i].name
         << "\nFather's Name : " << holders[i].f_name
         << "\nContsact Number : " << holders[i].ph_no
         << "\nCurrent Balance in your account : " << holders[i].amount << endl;
}

void addamount()
{
    valid = false;
    cout << "Enter the account number : ";
    cin >> temp;
    for (i = 0; i < acc_count; i++)
        if (holders[i].acc_no == temp)
        {
            valid = true;
            break;
        }
    if (!valid)
    {
        cout << "Enter a valid account number.\n";
        return;
    }
    cout << "Enter the amount : ";
    cin >> temp;
    holders[i].amount += temp;
    cout << "Updated balance in your account : " << holders[i].amount << endl;
}

void withdraw()
{
    valid = false;
    cout << "Enter the account number : ";
    cin >> temp;
    for (i = 0; i < acc_count; i++)
        if (holders[i].acc_no == temp)
        {
            valid = true;
            break;
        }
    if (!valid)
    {
        cout << "Enter a valid account number.\n";
        return;
    }
    if (holders[i].amount <= 500)
    {
        cout << "Amount in your balance is not enough.\n";
        return;
    }
    cout << "Enter the amount you want to withdraw : ";
    cin >> temp;
    if(holders[i].amount-temp < 0){
        cout << "Amount in your balance is not enough.\n";
        return;
    }
    holders[i].amount -= temp;
    cout << "Updated balance in your account : " << holders[i].amount << endl;
}

void transaction()
{
    cout << "Enter account number from which you want to do a transaction : ";
    cin >> temp;
    valid = false;
    for (i = 0; i < acc_count; i++)
        if (holders[i].acc_no == temp)
        {
            valid = true;
            break;
        }
    if (!valid)
    {
        cout << "Please enter a valid account number.\n";
        return;
    }
    valid = false;
    cout << "Enter account number to which you want to do a transaction : ";
    cin >> temp2;
    for (j = 0; j < acc_count; j++)
        if (holders[j].acc_no == temp2)
        {
            valid = true;
            break;
        }
    if (!valid)
    {
        cout << "Enter a valid account number.\n";
        return;
    }
    if (holders[i].amount <= 500)
    {
        cout << "There is not enough balance in your account.\n";
        return;
    }
    cout << "Enter the amount you want to transfer from " << holders[i].name << " to " << holders[j].name << " : ";
    cin >> temp;
    if(holders[i].amount-temp < 0)
    {
        cout << "Amount in your balance is not enough.\n";
        return;
    }
    holders[i].amount -= temp;
    holders[j].amount += temp;
    cout << "\nUpdated balance in " << holders[i].name << " is : " << holders[i].amount << endl;
    cout << "Updated balance in " << holders[j].name << " is : " << holders[j].amount << endl;
}

void delete_acc()
{
    valid = false;
    cout << "Enter the account number which you would like to delete : ";
    cin >> temp;
    for (i = 0; i < acc_count; i++)
        if (holders[i].acc_no == temp)
        {
            valid = true;
            break;
        }
    if (!valid)
    {
        cout << "Enter a valid account number.\n";
        return;
    }
    cout << "Account deleted successfully.\n";
    holders[i].acc_no == 0;
    holders[i].amount = 0;
    holders[i].f_name = "";
    holders[i].name = "";
    holders[i].ph_no = 0;
}

