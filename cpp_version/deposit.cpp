#include "main.h"
using namespace std;

/**
 * @brief This function deposits money in the account
 * @param _id 
 * @param amount 
 */
void account::dep(int _id  , int amount)
{
    fstream file;
    int bal ;
 
    file.open("project.txt", ios::in | ios::out);
    file.seekg(0, ios::beg);
    
    account x ;
    
    while (file.read((char *)&x, sizeof(x)))
    {
        if (x.id == _id)
        {
            bal = x.balance + amount ;
            x.balance = bal;
            
            file.seekp((long long)file.tellp() - sizeof(x));
            file.write((char *)&x, sizeof(x));
            break;
        }
    }
    file.close();
}

/**
 * @brief This function withdraws money from the account
 * @param _id 
 * @param amount 
 */
void account::withdraw(int _id  , int amount)
{
    fstream file;
    int bal ;
 
    file.open("project.txt", ios::in | ios::out);
    file.seekg(0, ios::beg);
    
    account x ;
    
    while (file.read((char *)&x, sizeof(x)))
    {
        if (x.id == _id)
        {
 
             bal = x.balance - amount ; 
             x.balance = bal;
             if(x.balance  < 500){
                cout <<" Sorry! It isn't valid ......" ;
                return ; 
             } 
             else {
                    bal = x.balance - amount ;
                    x.balance = bal;
                  }
            file.seekp((long long)file.tellp() - sizeof(x));
            file.write((char *)&x, sizeof(x));
            break;
        }
    }
    file.close();
}

/**
 * @brief This function is used to deposit or withdraw money from the account
 * @param n 
 * @param op 
 */ 
void account::deposit_withdraw(int n ,  int op){
  int amt ;int bal;
  bool found = true;
  account ac;
  fstream file ;
  file.open("project.txt",ios::in|ios::out);
  if(!file)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
  while(!file.eof() && found==true){
    file.read((char *)&ac , sizeof(ac));
    if(ac.id == n ){
      if(op == 1 ){
        cout<<"*****************To Deposite Amount********************\n";
        cout<<"     Enter Amount to be Deposited : ";
        cin>>amt;
        dep(n , amt);
 
      }
      if(op == 2){
        cout<<"*****************To Withdraw Amount*******************\n";
        cout<<"     Enter Amount to be Withdrawed :";
        cin>>amt;
        withdraw(n , amt);
       
      }
      
            cout<<"\n\n\t Done :) \n";
            found=false;
    }
 
  }
  file.close();
    if(found)   cout<<"\n\n Record Not Found :( \n";
 
}
