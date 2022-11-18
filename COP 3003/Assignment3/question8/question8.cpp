/**
 * * Write a program to maintain employee database using virtual class.
 * ? Hint:
 * ? a. Create employee class details such as name, id
 * ? b. Create account class that has the pay, bonus etc.,
 * ? c. Create admin class that had experience, designation etc.,
 * ? d. create a master class that switches to
 * ? (1) Enter the details of the employee
 * ? (2) Display the details of the employee
 * ? (3) Update information if needed
 * ? (4) Quit the program.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class employee
{
  protected:
      char name[20];
      int code;
  public:
      void getdetail(void)
      {
        cout<<endl<<endl<< "Enter name :- ";
        cin>>name;
        cout<<endl<<"Enter code :- ";
        cin>>code;
      }
      void dispdetail(void)
      {
        cout<<endl<<endl<<"NAME      :- "<<name;
        cout<<endl<<"CODE      :- "<<code;
      }
};

class account : virtual public employee
{
  protected:
       float pay;
  public:
       void getpay(void)
       {
          cout<<endl<<"Enter Pay amount :- ";
          cin>>pay;
       }
       void dispay(void)
       {
          cout<<endl<<"PAY       :- "<<pay;
       }
};

class admin : virtual public employee
{
  protected:
       int experience;
  public:
       void getexpr(void)
       {
          cout<<endl<<"Enter Experience in yrs :- ";
          cin>>experience;
       }
       void dispexpr(void)
       {
          cout<<endl<<"EXPERIENCE:- "<<experience;
       }
};

class master : public account, public admin
{
    public:
    void create(void)
    {
       cout<<endl<<endl<<"=====GETDATA IN====="<<endl;
       getdetail();
       getpay();
       getexpr();
    }

    void display(void)
    {
      cout<<endl<<endl<<"=====DISPLAY DETAILS====="<<endl;
      dispdetail();
      dispay();
      dispexpr();
    }

    void update(void)
    {
      cout<<endl<<endl<<"=====UPDATE DETAILS====="<<endl;
      cout<<endl<<"Choose detail you want to update"<<endl;
      cout<<"1)  NAME"<<endl;
      cout<<"2)  CODE"<<endl;
      cout<<"3)  EXPERIENCE"<<endl;
      cout<<"4)  PAY"<<endl;
      cout<<"Enter your userChoice:- ";
      int userChoice;
      cin>>userChoice;
      switch(userChoice)
      {
        case 1 : cout<<endl<<endl<<"Enter name : - ";
             cin>>name;
             break;
        case 2 : cout<<endl<<endl<<"Enter code :- ";
             cin>>code;
             break;
        case 3 : cout<<endl<<endl<<"Enter pay :- ";
             cin>>pay;
             break;
        case 4 : cout<<endl<<endl<<"Enter Expereince :- ";
             cin>>experience;
             break;
        default: cout<<endl<<endl<<"Invalid userChoice"<<endl<<endl;
             break;
      }
    }
};

int main()
{
    master newObject;
    int userChoice;

    while(1)
    {

       cout<<endl<<endl<<"====EMPLOYE DATABASE====="<<endl<<endl;
       cout<<endl<<"Choose Operation you want to perform"<<endl;
       cout<<"1)  Create  Record"<<endl;
       cout<<"2)  Display Record"<<endl;
       cout<<"3)  Update  Record"<<endl;
       cout<<"4)  Exit"<<endl;
       cout<<endl<<"Enter your userChoice:- ";
       cin>>userChoice;
       switch(userChoice)
       {
         case 1 : newObject.create();
              break;
         case 2 : newObject.display();
              break;
         case 3 : newObject.update();
              break;
         case 4 : exit(1);

         default : cout<<endl<<endl<<"Invalid userChoice"<<endl<<"Try Again"<<endl<<endl;
              break;
       }

    }

    return 0;
}