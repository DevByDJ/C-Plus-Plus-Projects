/*
* Show two type of Inheritance program of your own choice.
**/

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Car // BASE CLASS
{
  public:

  // -- Variable Declaration --
  int year;
  string make, model;

  /*
  * getCarInfo() runs all of the get methods created to obtain the information of a
  * new car.
  **/
  void getCarInfo()
  {
    getMake();
    getModel();
    getYear();
  };

  /*
  * displayCarInfo() displays the information obtained by getCarInfo()
  **/
  void displayCarInfo()
  {
    cout << endl << "===== NEW CAR ======";
    cout << endl;
    cout << endl << "Car's make: "  << make;
    cout << endl << "Car's model: " << model;
    cout << endl << "Car's current year: " << year << endl;
    cout << endl << "=========================" << endl;

  };

  void getMake()
  {
    cout << endl << "Enter your Car's make: ";
    getline(cin >> ws, make);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, make);
    }

  };

  void getYear()
  {
    cout << endl << "Enter your Car's Year: ";
    cin >> year;

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> year;
    };

  };

  void getModel()
  {
    cout << endl << "Enter your Car's model: ";
    getline(cin, model);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, model);
    }

  };


};

class ElectricCar : public Car // DERIVED CLASS
{
  public:

  int voltage, range;

  void getElectricInfo()
  {
    getVoltage();
    getRange();

  };

  void getVoltage()
  {
    cout << endl << "Enter the Car's Voltage: ";
    cin >> voltage;

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> voltage;
    };

  };

  void getRange()
  {
    cout << endl << "Enter the Car's Range: ";
    cin >> range;

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> range;
    };

  };

  void displayElectricInfo()
  {
    cout << endl << "===== Electric Info ======";
    cout << endl;
    cout << endl << "Car's Voltage: "  << voltage << " Watts";
    cout << endl << "Car's Range: " << range << " Miles till next charge.";
    cout << endl << "=========================" << endl;

  };

};

class HybridCar : public ElectricCar // CHILD OR MULTI-INHERITED CLASS
{
  public:

  int gasTank;

  void getHybridInfo()
  {
    getGas();
  };

  void getGas()
  {
    cout << endl << "Enter the Car's Gallons of Gas: ";
    cin >> gasTank;

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> gasTank;
    };

  };


  void displayHybridInfo()
  {
    cout << endl << "===== Hybrids Info ======";
    cout << endl;
    cout << endl << "Car's amount of Gallons of gas are: " << gasTank;
    cout << endl << "=========================" << endl;

  };

};

int main()
{

  Car car;
  ElectricCar tesla;
  HybridCar prius;

  car.getCarInfo();
  car.displayCarInfo();

  tesla.getCarInfo();
  tesla.getElectricInfo();
  tesla.displayCarInfo();
  tesla.displayElectricInfo();

  prius.getCarInfo();
  prius.getElectricInfo();
  prius.getHybridInfo();
  prius.displayCarInfo();
  prius.displayElectricInfo();
  prius.displayHybridInfo();

  return 0;
}