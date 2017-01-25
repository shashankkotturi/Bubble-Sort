#include <iostream>
#include "Sorting.h"

using namespace std;

void displayNames(int numNames, char* firstName[], char* lastName[], int age[]){
	for (int i = 0; i < numNames; i++)
		cout << firstName[i] << " " << lastName[i] << " " << age[i] << endl;
}


void stringSwap(char* &str1, char* &str2){
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}

void bubbleSort(int numNames, char* firstName[], char* lastName[], int age[]){
	
	int tempAge = 0;
	
	for (int i = 0; i < numNames; i++){
		for (int j = 0; j < numNames - 1; j++){
			
			// If the 1st last name is behind the 2nd last name
			if (stringCmp(lastName[j], lastName[j + 1]) < 0){
				
				// Swap first and last names
				stringSwap(lastName[j], lastName[j + 1]);
				stringSwap(firstName[j], firstName[j + 1]);
				
				// Swap Ages
				tempAge = age[j];
				age[j] = age[j + 1];
				age[j + 1] = tempAge;
				
			}
			
			// If the 1st last name is the same as the 2nd last name
			else if (stringCmp(lastName[j], lastName[j + 1]) == 0){
				
				// If the 1st first name is behind the 2nd first name
				if (stringCmp(firstName[j], firstName[j + 1]) < 0){
					
					// Swap first and last names
					stringSwap(lastName[j], lastName[j + 1]);
					stringSwap(firstName[j], firstName[j + 1]);
					
					// Swap Ages
					tempAge = age[j];
					age[j] = age[j + 1];
					age[j + 1] = tempAge;					
				}
				
			}
		
		}
		
	}
}
/*
int main() {

	// ** INITIALIZATION **
	// For basic testing, a list of 6 names is created (along with the corresponding age)
	const int numNames = 6;
	char* firstName[numNames] = {"Andrew", "John", "Jean", "Stephen", "Alice", "Jean"};
	char* lastName[numNames] = {"Hawking", "Smith", "Smith", "Hawking", "Cooper", "Smith"};
	int age[] = {13, 27, 19, 72, 68, 28};

	// STEP 1: Show on screen the list of names and ages BEFORE sorting
	cout << "Before sorting:"<< endl;
	displayNames(numNames, firstName, lastName, age);

	// STEP 2: Sort the list according to last name (in alphabetical order) and then by first name
	bubbleSort(numNames, firstName, lastName, age);

	// STEP 3: Show on screen the list of names and ages AFTER sorting
	cout << endl << "After sorting:"<< endl;
	displayNames(numNames, firstName, lastName, age);

	return 0;
}
*/