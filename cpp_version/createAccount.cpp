#include "main.h"
using namespace std;


// Last Id in the file
int LastId()
{
    fstream file;
    file.open("project.txt", ios::in);
    file.seekg(0, ios::beg);
    account x;
    int cnt = 0;
    while (file.read((char *)&x, sizeof(x)))
    {
        cnt = x.id;
    }
    return cnt;
}
// create new account
void account::create_account()
{
    account a;
    cout << "Enter name: ";
    cin >> a.name;
    cout << "Enter age: ";
    cin >> a.age;
    cout << "Enter balance: ";
    cin >> a.balance;
    a.id = LastId() + 1;

    // add this record to the file
    fstream file;
    file.open("project.txt", ios::out | ios::app);
    file.write((char *)&a, sizeof(a));
    file.close();
    cout << "Account created successfully\n";
}

