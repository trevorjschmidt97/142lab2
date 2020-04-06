/*
Trevor Schmidt, CS 142 - 002, trevorjschmidt97@gmail.com
Description: Input number of guests and size of tip for an event to determine the number of large, medium,
and small pizzas that will be needed, to determine the total area of pizza and pizza per guest,
and to determine the cost of the pizza with tip.

Test case one:
Input:
2 2
Expected Output:
Please enter the number of guests:
0 large pizzas, 0 medium pizzas, and 2 small pizzas will be needed.

A total of 226.195 square inches of pizza will be purchased (113.097 per guest).

Please enter the tip as a percentage (i.e. 10 means 10%):
The total cost of the event will be: $15
Result:
Passed

Test Case Two:
Input:
999 99
Expected Output:
Please enter the number of guests:
142 large pizzas, 1 medium pizzas, and 2 small pizzas will be needed.

A total of 45037.9 square inches of pizza will be purchased (45.083 per guest).

Please enter the tip as a percentage (i.e. 10 means 10%):
The total cost of the event will be: $4200
Result:
Passed

Test Case Three:
Input:
50 50
Expected Output:
Please enter the number of guests:
7 large pizzas, 0 medium pizzas, and 1 small pizzas will be needed.

A total of 2312.21 square inches of pizza will be purchased (46.2442 per guest).

Please enter the tip as a percentage (i.e. 10 means 10%):
The total cost of the event will be: $165
Result:
Passed
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	const int PPL_PER_LG = 7;
	const int PPL_PER_MD = 3;
	const int PPL_PER_SM = 1;
	int numGuests = 0;
	int largePizzas = 0;
	int medPizzas = 0;
	int smallPizzas = 0;

	// Getting number of guests
	cout << "Please enter the number of guests: " << endl;
	cin >> numGuests;
	int tempGuests = numGuests;

	// Finding number of pizzas
	largePizzas = tempGuests / PPL_PER_LG;
	tempGuests = tempGuests % PPL_PER_LG;
	medPizzas = tempGuests / PPL_PER_MD;
	tempGuests = tempGuests % PPL_PER_MD;
	smallPizzas = tempGuests / PPL_PER_SM;

	// Print number of pizzas needed
	cout << largePizzas << " large pizzas, " << medPizzas << " medium pizzas, and " << smallPizzas << " small pizzas will be needed." << endl << endl;

	// Declare variables for area
	const int SMALL_RAD = 6;
	const int MED_RAD = 8;
	const int LARGE_RAD = 10;
	double totalArea = 0;
	double guestArea = 0;

	// Finding total area of pizzas
	totalArea = smallPizzas * SMALL_RAD * SMALL_RAD * M_PI + medPizzas * MED_RAD * MED_RAD * M_PI + largePizzas * LARGE_RAD * LARGE_RAD * M_PI;
	guestArea = totalArea / numGuests;

	// Print area information
	cout << "A total of " << totalArea << " square inches of pizza will be purchased (" << guestArea << " per guest)." << endl << endl;

	// Declaring variables for price
	const double PRICE_LG = 14.68;
	const double PRICE_MED = 11.48;
	const double PRICE_SM = 7.28;
	double tip = 0;
	double costPizzas = 0;
	double costTip;
	int totalCost = 0;

	//Finding tip percentage
	cout << "Please enter the tip as a percentage (i.e. 10 means 10%): " << endl;
	cin >> tip;

	//Calculating cost of pizzas
	costPizzas = PRICE_LG * largePizzas + PRICE_MED * medPizzas + PRICE_SM * smallPizzas;

	//Calculating cost of tip
	costTip = tip / 100 + 1;

	//Finding total cost rounded up.
	totalCost = costPizzas * costTip + .5;

	//Printing total cost
	cout << "The total cost of the event will be: $" << totalCost << endl;




	return 0;
} 