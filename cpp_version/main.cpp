#include "main.h"

/**
 * main function - entry point
 * @return 0 on success
 */
int main() {
account a;
    char ch;
    int n ; 
    do{  
        cout<<"*****************************Bank Management System*****************************\n";
        cout<<"MAIN MENU:"<<"\n";
        cout<<"1)  NEW ACCOUNT "<<"\n";
        cout<<"2)  DEPOSIT AMOUNT"<<"\n";
        cout<<"3)  WITHDRAW AMOUNT"<<"\n";
        cout<<"4)  MODIFY ACCOUNT "<<"\n";
        cout<<"5)  DELETE ACCOUNT "<<"\n";
        cout<<"6)  Search for an acount "<<"\n";
        cout<<"7)  SHOW ALL ACCOUNTS  "<<"\n";
        cout<<"8)  EXIT "<<"\n";
        cout<<"*********************************************************************************\n";
        cout<<"Enter the number of transaction you want  : "<<endl;
        cin>>ch ;
        switch (ch)
        {
            case '1':
                a.create_account();
                break;
 
            case '2':
                cout<<"Enter Your id to deposite\n";
                cin>>n;
                a.deposit_withdraw(n,1);
                break;
 
            case '3':
                cout<<"Enter Your id to withdraw\n";
                cin>>n;
                a.deposit_withdraw(n,2);
 
                break;
 
            case '4':
                // write function
                a.modify_account();
                break;  
 
            case '5':
                // write function
                a.delete_account();
                break;
 
            case '6':
                // write function
                char name [35];
                cout<<"Enter the name you want to search for:\n";
                cin>>name;
                cout<<"ID  Name  balance  age\n";
                cout<<"------------------------\n";
                a.search(name);
                cout<<"------------------------\n";
                break;
 
            case '7':
                // write function
                a.display_accounts();
                break;  
 
            case '8':
                cout<<"Thanks for using Our Bank Management System\n";
                break;  
 
            default:
                break;
 
        }
        if(ch != '8'){
            char c;
            cout<<"Do you want to continue (y/n) : ";
            cin>>c;
            if(c == 'n' || c == 'N')
                ch = '8';
        }
 
    }while(ch !=  '8');
 
    return 0;
}