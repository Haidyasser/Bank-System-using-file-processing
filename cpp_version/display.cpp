#include "main.h"

/**
 * @brief This function displays all the accounts in the file
 * @return void
 */
void account :: display_accounts()
{
    account a;
    fstream file;
    bool ok = false;
    file.open("project.txt", ios::in);
    file.seekg(0, ios::beg);
    cout << "ID\tName\tBalance\t Age\n";
    while (file.read((char *)&a, sizeof(a)))
    {
        cout << a.id << "\t" << a.name << "\t" << a.balance << "\t " << a.age << "\n";
        ok = true;
    }
    if (!ok)
        cout << "No accounts found\n";
    file.close();
}
