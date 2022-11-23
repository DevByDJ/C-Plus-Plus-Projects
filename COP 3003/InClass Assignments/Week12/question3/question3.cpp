#include <iostream>

#include <fstream>

using namespace std;

int main() {

  fstream newfile;
	newfile.open("newfile.txt", ios::in);

	if (!newfile) 
  {
		cout << "No file found";
	}
	else 
  {
		char newCharacter;

		while (1) {
			newfile >> newCharacter;
			if (newfile.eof())
				break;

			cout << newCharacter;
		}

	}

	newfile.close();

	return 0;
}