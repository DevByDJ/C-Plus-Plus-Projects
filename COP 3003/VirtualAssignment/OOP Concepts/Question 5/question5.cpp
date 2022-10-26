/*
* Write a program to create student class, read and print N (at least 4 
* inputs) student’s details.
? Hint: Students details may be name, ID, Discipline, Year of study, age etc.,
**/

#include<iostream>

using namespace std;


class Student
{
  public:

  // -- Variable Declaration --
  int id, age;
  string name, yearOfStudy, discipline;

  /*
  * getStudentInfo() runs all of the get methods created to obtain the information of a
  * new student.
  **/
  void getStudentInfo()
  {
    getID();
    getAge();
    getName();
    getYearOfStudy();
    getDiscipline();
  };

  /*
  * displayStudentInfo() displays the information obtained by getStudentInfo()
  **/
  void displayStudentInfo()
  {
    cout << endl << "===== NEW STUDENT ======";
    cout << endl;
    cout << endl << "Student Name: "  << name;
    cout << endl << "Student ID: " << id;
    cout << endl << "Student age: "  << age;
    cout << endl << "Student's discipline: " << discipline;
    cout << endl << "Student's current year: " << yearOfStudy  << endl;
    cout << endl << "=========================" << endl;

  };


  void getID()
  {
    cout << endl << "Enter your ID number: ";
    cin >> id;
    cin.ignore(1,'\n');

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: You must enter a number!" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> id;
    }

  };

  void getAge()
  {
    cout << endl << "Enter your age: ";
    cin >> age;
    cin.ignore(1,'\n');

    // -- CATCH ERROR --
    while(cin.fail()) 
    {
      cout << endl << "Err: You must enter a number!" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> age;
    }

  };

  void getName()
  {
    cout << endl << "Enter your name: ";
    getline(cin, name);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, name);
    }

  };

  void getYearOfStudy()
  {
    cout << endl << "Enter your year of study (i.e Freshman): ";
    getline(cin, yearOfStudy);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, yearOfStudy);
    };

  };

  void getDiscipline()
  {
    cout << endl << "Enter your discipline: ";
    getline(cin, discipline);

    // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: Invalid submission" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      getline(cin, discipline);
    }

  };


};

int main()
{

  /*
  * The following will have the user determine the size of the array
  * and collect the amount of inputs according the the size of the array.
  ! REQ: The user cannot input a negative number during the size of the array.
  **/
  int numberOfStudents;
  cout << "Enter the amount of students you would like to create: ";
  cin >> numberOfStudents;

  // -- CATCH ERROR --
    while(cin.fail())
    {
      cout << endl << "Err: You must enter a number!" << endl << endl;
      cin.clear();
      cin.ignore(256, '\n');
      cin >> id;
    }


  /*
  * Assign the number of elements to the array and collect the user inputs
  * in a loop until the user reaches the maximum amount of elements.
  ! REQ: OnLY ACCEPT NUMBERS
  **/
  Student student[numberOfStudents];
  
  for(int i = 0; i < numberOfStudents ; i++)
  {
      student[i].getStudentInfo();
  }

  for(int i = 0; i < numberOfStudents ; i++)
  {
      student[i].displayStudentInfo();
  }

  return 0;
}