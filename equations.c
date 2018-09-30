#include "header.h"

char *my_str_n_cat(char *dest, char *sourse) {
	int dest_size = 0, sourse_size = 0, counter = 0; //Declare
	for (counter = 0; dest[counter] != NULL; counter = counter + 1) { //Finding the length of the destination
		dest_size = dest_size + 1;
	}

	for (counter = 0; sourse[counter] != NULL;  ) { //Finding the length of the source, I spell source wrong once and went with it
		sourse_size = sourse_size + 1;
	}
	int size = dest_size + sourse_size; //Declaring size of total final array
	char overallString[BUFFER]; //Self explanatory
	overallString[size] = NULL; //setting the size of the final array
	
	for (counter = 0; counter < dest_size; counter = counter + 1) { //Passing the destination into the function from the start being zero
		overallString[counter] = dest[counter]; //continued...
	}

	for (counter = dest_size; counter < size; counter = counter + 1) { //Passing the source into the array starting from after the destination
		overallString[counter] = sourse[counter - dest_size];
	}
	return overallString; //Returning the final string
}

int binary_search(int arr[], int tvalue, int total){
	int counter = 0, mid;
	#define HALF 2
	mid = sizeof(arr) / HALF; //Cutting it because the price is way too high
	for (counter; counter < pow(total, 2); ++counter) { 
		if (tvalue == arr[mid]) { 
			return mid + 1;
		}
		else if (tvalue < arr[mid]) { //Searching for whether or not the target value is above or below mid then left
			mid = --mid;
		}
		else if (tvalue > arr[mid]) { //Searching for whether or not the target value is above or below mid then right
			mid = ++mid;
		}
	}
	return -1;
}

void bubble_sort(char *list[], char strings) {
	int U = --strings;
	char *move;
	while (strings - U > 1) { // while the unsorted section has more than one element do steps 3 through 7
		int C = HALF - 1; //  set the current element marker C at the second element of the list (C is an integer index value)
		while (U > C) { //while C has not passed U do steps 5 and 6
			if (strcmp(list[C], list[--C]) >= 1) {
				move = list[C]; 
				list[C] = list[--C]; //Hypothetical Syllogism
				list[--C] = move;
			}
			++C; // move C to the right one position
		}
		--U; // move U left one position
	} 
}

int is_palindrome(char *string, int size) { 
	return palindrome_looper(string, size, 0); 
}

int palindrome_looper(char *string, int size, int index) { 
	if (size % 2 == 1 ) { //Seeing if odd
		if (index + 1 == ((int) (size / 2))) { //Adding one to index in order for it to be subtracted by the size
			return 1;
		}
	}

	if (((int) (size / 2)) == index) { //Seeing if even
		return 1;
	}

	if (string[index] != string[size - index - 1]) { //Exit False
		return 0;
	} 
	index = index + 1;
	
	return palindrome_looper(string, size, index); //Return is_palindrome via recurstion (return to function)
}

int sum_primes(unsigned int n) //Declaring unsigned n
{
	if (n >= 2)
	{
		n = is_prime(n) + sum_primes(n - 1); //Taking prime n and adding the sum of the primes - 1
		return n; //Returning the value
	}
	else
	{
		return 0; //Not returning the value
	}
}

int is_prime(int n)
{
	int t = 2;
	int remain = n % t;

	while ((t != n) && (remain != 0)) {
		remain = n % t;
		t = t + 1;
	}
	if (t == n) {
		return n;
	}
	else if (t != n) {
		return 0; 
	}
}

Occurrences maximum_occurences(char * string, Occurrences *occr, int *num, char *args) {
	int size = strlen(string), uniquechars = 0, find_occurs = 0;
	char charizard[20] = { '\0' }; 
	charizard[0] = string[0];

	for (int i = 0; i < size; i++) {
		char a = string[i];
		int option = 1;
		for (int j = 0; j < 20; j++) {
			if (charizard[j] == a)
				option = 0;
		}

		if (option == 1)
			for (int j = 0; j < 20; j++)
				if (charizard[j] == '\0') { 
					charizard[j] = a;
					break; // leave loop
				}
	}

	for (int i = 0; i < 20; i++) {
		if (charizard[i] != '\0') uniquechars++;
	}

	for (int i = 0; i < uniquechars; i++) { 
		occr[i].ochar = charizard[i]; 
		for (int j = 0; j < size; j++) {
			if (string[j] == charizard[i]) //Compares Arrays
				occr[i].num_occurrences++;
		}
		occr[i].frequency = (double)occr[i].num_occurrences / size; //typecast
	}
	for (int i = 0; i < uniquechars; i++) {
		if (occr[i].num_occurrences > occr[find_occurs].num_occurrences) {
			find_occurs = i;
		}
	}
	

	return occr[find_occurs]; 
}