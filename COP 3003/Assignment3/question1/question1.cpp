#include <iostream>
#include <cstring>

using namespace std;

class Student
{
	public:
    int userChoice;
    string student[5] = {"Danny", "Jacob", "Joseph", "Kaylah", "Karasi"};

    Student()
    {
      userChoice = 1;
    }
		
		//member function to get input
		void chooseStudent (void)
		{
      cout<<"Choose a student:";
      cout<<endl<<"1.) Danny";
      cout<<endl<<"2.) Jacob";
      cout<<endl<<"3.) Joseph";
      cout<<endl<<"4.) Kaylah";
      cout<<endl<<"5.) Karasi";
			cout<<endl<<endl<<"Enter the number corresponding the Student: ";
			cin>>userChoice;

      // -- CATCH ERROR --
      while(cin.fail() || userChoice < 0)
        {
            cout << endl << "Err: You must enter a Student greater than 0!" << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> userChoice;
        }
		}
		//member function to display Student 
		void displayStudent()
		{
			cout<<endl<<"Student: "<<student[userChoice - 1]<<endl<<endl;
		}
};

//Main function
int main()
{

	//declaring pointer to the object 
	Student *ptrN;
	ptrN = new Student; //creating & assigning memory 

	//input values and print 
	ptrN->chooseStudent();
	ptrN->displayStudent();

	return 0;
}