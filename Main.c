//Name: Brevin Simon
//Instructor: Andy O' Fallon
//Date: March 16th, 2018
//Assignment: PA 8

#include "header.h"

int main(void) {
	//Question One
	char *sourse = "WasThePointOfThis", *dest = "WhatWas";
	printf("%s \n", my_str_n_cat(dest, sourse));

	//Question Two
	int arr[] = { 1, 2, 3, 4, 5, 11, 12, 13, 14, 15, 21, 22, 23, 24, 25, 100, 299 }, tvalue = 0;
	printf("Guess a number: ");
	scanf("%d", &tvalue);
	printf("The %d position in the array, if '-1' then not in array\n", binary_search(arr, tvalue, 11));

	//Question Three
	int strings = 20;
	char * list[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
	"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Nineteen", "Twenty" };
	bubble_sort(list, strings);

	//Question Four
	int size = 7; //Size of string
	char *string = "ooooooo"; //Probably spelled same forward and back
	printf("Palindrome = 1, Not Palindrome = 0. \"%d\"\n", is_palindrome(string, size));

	//Question Five
	int sum = 0; 
	printf("Sum of primes: %d\n", sum_primes(10));

	//Question Six
	//Got Help On Question 8 From Ben Poile
	Occurrences find[20] = { '\0', 0, 0.0 };
	Occurrences test = maximum_occurences("goodnight", find, 0, 'c'); //Enter word here
	printf("Most occurences is %c and happened %d times. Which is %lf ratio\n", test.ochar, test.num_occurrences, test.frequency);

	return 1;
}