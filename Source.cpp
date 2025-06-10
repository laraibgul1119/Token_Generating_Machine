#include<iostream>
#include"TokenMachine.h"
using namespace std;
int main()
{
	TokenMachine::getNextToken().display();
	cout<< "\n";
	TokenMachine::personIsServiced();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n"; 
	TokenMachine::personIsServiced();
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::personIsServiced();
	cout << "Count of Persons Serviced: "
		<< TokenMachine::getCountOfPersonsServiced();
	TokenMachine::personIsServiced();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";
	TokenMachine::getNextToken().display();
	cout << "\n";

}