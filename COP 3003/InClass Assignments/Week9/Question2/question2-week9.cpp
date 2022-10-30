/*
* Using multilevel inheritance write a program to manage patient bills in a hospital
**/

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Patient // BASE CLASS
{
  public:

  // -- Variable Declaration --
  int age;
  string name, gender;

  /*
  * getPatientInfo() runs all of the get methods created to obtain the information of a
  * new Patient.
  **/
  void getPatientInfo()
  {
    getname();
    getgender();
    getage();
  };

  /*
  * displayPatientInfo() displays the information obtained by getPatientInfo()
  **/
  void displayPatientInfo()
  {
    cout << endl << "===== NEW Patient ======";
    cout << endl;
    cout << endl << "Patient's name: "  << name;
    cout << endl << "Patient's gender: " << gender;
    cout << endl << "Patient's age: " << age << endl;
    cout << endl << "=========================" << endl;

  };

  void getname()
  {
    cout << endl << "Enter your Patient's name: ";
    getline(cin >> ws, name);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, name);
    }

  };

  void getage()
  {
    cout << endl << "Enter your Patient's age: ";
    cin >> age;

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> age;
    };

  };

  void getgender()
  {
    cout << endl << "Enter your Patient's gender: ";
    getline(cin, gender);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, gender);
    }

  };


};

class Surgery : public Patient // DERIVED CLASS
{
  public:

  string typeOfSurgery;

  void getSurgeryInfo()
  {
    getTypeOfSurgery();

  };

  void getTypeOfSurgery()
  {
    cout << endl << "Enter the Patient's type of Surgery: ";
    getline(cin >> ws, typeOfSurgery);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, typeOfSurgery);
    };

  };

  void displaySurgeryInfo()
  {
    cout << endl << "===== Surgery Info ======";
    cout << endl;
    cout << endl << "Patient had a "  << typeOfSurgery << " performed.";
    cout << endl << "=========================" << endl;

  };

};

class Bill : public Surgery // CHILD OR MULTI-INHERITED CLASS
{
  public:

  int price;

  void getBillPrice()
  {
    getPrice();
  };

  void getPrice()
  {
    cout << endl << "Enter the price of the surgery: ";
    cin >> price;

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> price;
    };

  };


  void displayBillPrice()
  {
    cout << endl << "===== TOTAL COST ======";
    cout << endl;
    cout << endl << "Total Cost is: " << price;
    cout << endl << "=========================" << endl;

  };

};

int main()
{
  Bill newPatient;

  newPatient.getPatientInfo();
  newPatient.getTypeOfSurgery();
  newPatient.getBillPrice();
  newPatient.displayPatientInfo();
  newPatient.displaySurgeryInfo();
  newPatient.displayBillPrice();

  return 0;
}