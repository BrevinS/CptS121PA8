#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define BUFFER 99999

char *my_str_n_cat(char *dest, char *sourse);

int binary_search(int arr[], int tvalue, int total);

void bubble_sort(char *list[], char strings);

int is_palindrome(char *string, int size);

int palindrome_looper(char *string, int size, int index);

int sum_primes(unsigned int n);
int is_prime(int n);

typedef struct occurrences //http://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA8.htm
{
	int num_occurrences;
	char ochar; //added
	double frequency;
} Occurrences;

Occurrences maximum_occurences(char * string, Occurrences *rep, int *number, char *cond);