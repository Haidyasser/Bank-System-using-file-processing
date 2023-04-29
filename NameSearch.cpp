#include "main.h"
// Display all records having the same name
int account::searchForName(char name[])
{
    fstream file;
    file.open("project.txt", ios::in);
    file.seekg(0, ios::beg);
    account x;
    bool ok = false;
    while (file.read((char *)&x, sizeof(x)))
    {
        if (strcmp(x.name, name) == 0)
        {
            cout << "ID\tName\tBalance\tAge\n";
            cout << x.id << "\t" << x.name << "\t" << x.balance << "\t" << x.age << "\n";
            ok = true;
        }
    }
    file.close();
    if(!ok)
    {
        cout << "No accounts found\n";
        return 0;
    }
    return 1;
}