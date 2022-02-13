/**
Danny Joseph
COP 2001 Programming Methodology
SPRING 2024
autocalc.cpp 
*/
#include <iostream>

int main() {

	char doAnother;
	// start calculation
	do {
		// declare input variables
		double price = 0.0;
		double rate = 0.0;
		int term = 0;
		double payment = 0.0;

		// gather inputs
		std::cout << "Price: ";
		std::cin >> price;

		std::cout << "Rate: ";
		std::cin >> rate;
	
		std::cout << "Term: ";
		std::cin >> term;

		// did they give a term
		if (term) {
			// calculate payment

		}
		// otherwise
		else {
			std::cout << "Payment: ";
			std::cin >> payment;

			// calculate term
		}


		// display outputs
		double totalPayments = term * payment;
		double interestPaid = totalPayments - price;

		std::cout << "Total of Payments: " << totalPayments << std::endl;
		std::cout << "Interest Paid: " << interestPaid << std::endl;

		// ask if want to continue
		std::cout << "Do another contract (Y): ";
		std::cin >> doAnother;

		// do another calc if continue
	} while (doAnother == 'Y' || doAnother == 'y');

	return 0;
}