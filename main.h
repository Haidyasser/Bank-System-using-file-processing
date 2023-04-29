#ifndef MAIN__H
#define MAIN_H
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class account
{
public:
    char name[20]{};
    int balance, id;
    int age;


public:
    account()
    {
        balance = 0;
        id = 0;
        age = 0;
    }
public:
    void create_account();
    void display_accounts();
    void search(char[]);
    void delete_account();
    void modify_account();
    int searchForName(char[]);
    void dep(int , int );
    void withdraw(int , int );
    void deposit_withdraw(int , int );
};

#endif
