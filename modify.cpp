#include "main.h"
using namespace std;

//edit records by id
void account::modify_account()
{
    fstream file;
    file.open("project.txt", ios::in | ios::out);
    file.seekg(0, ios::beg);
    char _name[30];
    cout << "Enter the name of the account you want to modify: ";
    cin >> _name;
    searchForName(_name);
    int _id;
    cout << "Enter the id of the account you want to modify: ";
    cin >> _id;
    account x, a;
    
    while (file.read((char *)&x, sizeof(x)))
    {
        if (x.id == _id)
        {
            cout << "Enter new name: ";
            cin >> a.name;
            cout << "Enter new balance: ";
            cin >> a.balance;
            cout << "Enter new age: ";
            cin >> a.age;
            a.id = _id;
            file.seekp((long long)file.tellg() - sizeof(x));
            file.write((char *)&a, sizeof(a));
            break;
        }
    }
    file.close();
}

