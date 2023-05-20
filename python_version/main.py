#------------------------------------------------------------------------------
#find last id in file
def lastId():
    l = 0
    with open("project1.txt", "r+") as file:
        for line in file:
            l = line.split()[0]
    return int(l)
 
# writing a record to a file
def writeToFile():
    
    with open("project1.txt", 'a') as file:
        Id = str(lastId() + 1)
        name = input("enter your name : ")
        age = input("enter age :  ")
        balance = input("Enter the amount of your balance : ")
        while int(balance) < 500 :
            print("Sorry you can't create an account :( \n Your balance can't be less than <<500>> \n Put another maount  .... )")
            balance = input("Enter the amount of your balance : ")
        file.write(Id + '\t' + name + '\t' + age + '\t' +balance+'\n')
        print("Record added sucessfully  :) ")
 
#------------------------------------------------------------------------------------------------ 
#read all data from a file
def readFromFile():
    flag = False
    try:
        with open("project1.txt", "r") as file:
            print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
            print("ID\tName\tAge\tBalance")
            print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
            for line in file:
                flag = True
                print(line, end="")
                print("--------------------------------")
    except:
        print("File not found")
    if flag == False:
        print("No data found")     
#---------------------------------------------------------------------------                
#Update a record
def UpdateToFile():
    import os
    flag = False
    flag2=False
    tmp = open("tmp.txt", "w")
    with open("project1.txt", "r") as file:
        Id = input("Enter your id : ")
        for line in file:
            if line.startswith(Id):
                print("Your Data :")
                print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                print("ID\tName\tAge\tBalance")
                print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                print(line, end="")
                print("----------------------------------------")
                flag=True
 
                ch = input("Do you want to update your name ? y/n ")
                if ch == 'y':
                    name = input("Enter your new name : ")
                    flag2 = True
                else:
                    name = line.split()[1]
                ch = input("Do you want to update your age ? y/n ")
                if ch == 'y':
                    age = input("Enter your new age : ")
                    flag2 = True
                else:
                    age = line.split()[2]
                l = line.split()
                l[1] = name
                l[2] = age
 
                tmp.write(l[0] + '\t' + l[1] + '\t' + l[2] + '\t' + l[3] + '\n' )
            else:
                tmp.write(line)
    tmp.close()
    os.remove("project1.txt")
    os.rename("tmp.txt", "project1.txt")
    if flag == False:
        print("There is no data for this id")
    elif flag2==False:
        print("There is no changes")
    else:
        print("your data updated successfully ")
#--------------------------------------------------------------------------- 
#delete a record 
def DeleteRecordFromFile():
    import os
    id = input("Enter id for deleteing : ")
    file = open("project1.txt",'r')
    tempFile = open("temp.txt",'w')
    flag = False
    for line in file:
        l = line.split('\t')
        if id != l[0]:
            tempFile.write(line)
        else:
            flag = True
    file.close()
    tempFile.close()
    os.remove("project1.txt")
    os.rename("temp.txt","project1.txt")
    if not flag:
        print("record does not exit in the file!!!")
    else:
        print("record was deleted successfully!!")
#--------------------------------------------------------------------------- 
# search and show specific record --> by name 
def search():
    name=input("Enter the name of Customer:\n")
    with open ("project1.txt","r")as f:
        flag=False
        for line in f:
            st=line.split("\t")
            if st[1]==name:
                flag=True
                print("ID     :",st[0])
                print("Name   :",st[1])
                print("Age    :",st[2])
                print("Balance:",st[3])
        if not flag:
            print("Account not found!\n")
            return False
        else:
            return True
#--------------------------------------------------------------------------
def dep():
    import os
    flag = search()
    if flag == False:
        return
    id = input("Enter ID : ")
    print("---------------------------------------")
    amt=input(" Enter amount to be deposited  : ")
 
    flag = False
    tmp = open("tmp.txt", "w")
    with open("project1.txt", "r") as file:
        for line in file:
            l = line.split('\t')
            if id == l[0]:
                flag = True
                iD = l[0]
                namee = l[1]
                lastbal = l[3]
                l[3] = int(l[3]) + int(amt)
                newbal = l[3]
                tmp.write(l[0] + '\t' + l[1] + '\t' + l[2] + '\t' + str(l[3]) + '\n')
            else:
                tmp.write(line)
    
    tmp.close()
    os.remove("project1.txt")
    os.rename("tmp.txt", "project1.txt")
 
    if flag == False:
        print("Your id not found")
    else:
        print("your Balance updated successfully ")
        report(iD , namee , lastbal , newbal)
#---------------------------------------------------------------------------
def withdraw():
    import os
    flag=search()
    if flag==False:
        return 
    id = input("Enter ID : ")
    flag = False
    tmp = open("tmp.txt", "w")
    with open("project1.txt", "r") as file:
        for line in file:
            l = line.split('\t')
            if id == l[0]:
                while flag == False :
                    print("---------------------------------------")
                    amt = input(" Enter amount to be Withdrawed :  \n")
 
                    if (int(l[3]) - int(amt) < 500 ) :
                        print("Sorry you can't withdraw this amount :( \n Your balance can't be less than <<500>> \n Put another maount  .... )")
                    else :
                        flag = True
                        iD = l[0]
                        namee = l[1]
                        lastbal = l[3]
                        l[3] = int(l[3]) - int(amt)
                        newbal = l[3]
                        tmp.write(l[0] + '\t' + l[1] + '\t' + l[2] + '\t' + str(l[3]) + '\n')
            else:
                tmp.write(line)
 
    tmp.close()
    os.remove("project1.txt")
    os.rename("tmp.txt", "project1.txt")
 
    if flag == False:
        print("Your id not found")
    else:
        print("your Balance updated successfully ")
        report(iD , namee , lastbal , newbal)
#---------------------------------------------------------------------------
def report(iD , namee , lastbal , newbal ) :
    import datetime
    print("<< Employee Data  >>")
    employee_name  = input(" Emolyee Name  : ")
    with open("report.txt" ,'a') as file :
        lastbal = int(lastbal)
        newbal = int(newbal)
        localdt = datetime.datetime.now()
        file.write(str(iD) +'\t\t'+  str(namee) + '\t\t' + str(lastbal) +'\t\t'+ str(newbal) +'\t\t'+ str(employee_name) +'\t\t'+ str(localdt) +'\n')
        print("\naddead to report succefully ^o^  ")
        
def readReport():
 
     id = input("Enter the customer id  : ")
     print("\n--------------")
     print("| Islamic Bank |")
     print(  "--------------")
     print("-------------------------------------------------------------------------------------------------------------")
     print("Customer ID\tCustomer Name\tLast Balance\tNewBalance\tEmployee Name\tDate ")
     print("-------------------------------------------------------------------------------------------------------------")
 
     with open("report.txt", "r") as file:
          for line in file:
            if line.startswith(id):
                print(line, end="") 
                print("-------------------------------------------------------------------------------------------------------------")       
#---------------------------------------------------------------------------
# main function            
def main():  # sourcery skip: do-not-use-bare-except
        c='y'
        while(c=='y'):
            print("---------------------------------------------------------")
            print("|              H  e   l   l   o    In                   |")
            print("|          Bank      Mangement      System              |")
            print("---------------------------------------------------------")
            print("\n")
            print("******************  MAIN  MENU  ******************")
            print("            -----------------------------")
            print("            | 1 | Create  Account       |")
            print("            -----------------------------")
            print("            | 2 | Deposite              |")
            print("            -----------------------------")
            print("            | 3 | Withdraw              |")
            print("            -----------------------------")
            print("            | 4 | Search for Acount     |") 
            print("            -----------------------------")
            print("            | 5 | Delete Your Acount    |")
            print("            -----------------------------")
            print("            | 6 | Update Your Account   |")
            print("            -----------------------------")
            print("            | 7 | Show all Accounts     |")
            print("            -----------------------------")
            print("            | 8 | Show a report         |")
            print("            -----------------------------")
 
            L = [writeToFile,dep,withdraw,search,DeleteRecordFromFile,UpdateToFile,readFromFile ,readReport]
            op=input("\nEnter Number Of Transaction You Want: ") 
            try:
                op = int(op)
                L[op - 1]()
            except:
                print("Invalid input")
 
            c=input("\nDo you want to continue?y/n.\n")
            if c=='n':
                print("Thank you for using our system :)")
main()