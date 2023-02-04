//***************************************************
// Mortgage Payment Calculator program
// This program determines the monthly payments on a
// mortgage given the loan amount, the yearly interest,
// and the number of years.
//***************************************************
#include <iostream>		// Access cout
#include <cmath>	    // Access power function
#include <iomanip>

using namespace std;

float LOAN_AMOUNT;      // Amount of loan   //Removing the constant declaration allows for
float YEARLY_INTEREST; // Yearly interest   //user to input values into the program
int NUMBER_OF_YEARS;  // Number of years
float monthlyInterest; // Monthly interest rate
int numberOfPayments; // Total number of payments
float payment;	     // Monthly payment
char again;         //Variable to play again

int main()
{
    //Greet user
    cout << "**********************************" << endl;
    cout << "**         Welcome to the       **" << endl;
    cout << "** Mortgage Calculator Program! **" << endl;
    cout << "**********************************" << endl << endl;
    do {    //"PLAY AGAIN" DO-WHILE LOOP
    // Prompt user for input values
    cout << "Please enter loan amount: " << endl;
    cin >> LOAN_AMOUNT;
    //Input validation loop
    while (!cin || LOAN_AMOUNT < 0 ){
    cout << "Invalid input." << endl << endl;
    cin.clear();                                            //clear input stream
    cin.ignore(500, '\n');                                  //ignore any remaining letters
    cout << "Please enter loan amount: " << endl << endl;   //prompt user for valid input
    cin >> LOAN_AMOUNT;}

    cout << "Please enter yearly interest rate: " << endl;
    cin >> YEARLY_INTEREST;
    //Input validation loop
    while (!cin || YEARLY_INTEREST < 0 ){
    cout << "Invalid input." << endl << endl;
    cin.clear();
    cin.ignore(500, '\n');
    cout << "Please enter yearly interest rate: " << endl << endl;
    cin >> YEARLY_INTEREST;}

    cout << "Please enter number of years this loan is for : " << endl;
    cin >> NUMBER_OF_YEARS;
    //Input validation loop
    while (!cin || NUMBER_OF_YEARS < 0 ){
    cout << "Invalid input." << endl << endl;
    cin.clear();            //clear input stream
    cin.ignore(500, '\n');  //ignore and remaining letters
    cout << "Please enter number of years this loan is for : " << endl; //prompt user for valid input
    cin >> NUMBER_OF_YEARS;}

    //Input conversion for whole numbers
    if (YEARLY_INTEREST>1)
    YEARLY_INTEREST = YEARLY_INTEREST/100;

    // Calculate values
    monthlyInterest = YEARLY_INTEREST / 12;
    numberOfPayments = NUMBER_OF_YEARS * 12;
    payment =(LOAN_AMOUNT *
              pow(monthlyInterest + 1, numberOfPayments)
              * monthlyInterest)/(pow(monthlyInterest + 1,
              numberOfPayments) - 1);

    // Output results
    cout << endl;
    cout << "******************************************" << endl;
    cout << "**For a loan amount of $" << LOAN_AMOUNT << "          **" << endl;
    cout << "**with an interest rate of "
    //Output conversion for readability
         << YEARLY_INTEREST * 100 << "%         **" << endl;
    cout << "**and a " << NUMBER_OF_YEARS << " year mortgage,               **" << endl;

    cout << "**your monthly payments are $" << payment << ".   **" << endl;
    cout << "******************************************" << endl << endl;

    //PROMPT USER TO USE PROGRAM AGAIN
    cout << "Would you like to calculate the payments for another mortgage? (Y/N)" << endl << endl;
    cin >> again;
    cin.ignore(100, '\n');  // Removes any extra letters from input stream
    again = toupper(again); //AUTOMATE TO CAPITAL LETTER
    } while (again == 'Y'); //LOOP CONDITION TO CONTINUE PROGRAM
    cout << "Thank you for using the mortgage calculator program. Good bye!" << endl;  //EXIT MESSAGE
    return 0;
}
