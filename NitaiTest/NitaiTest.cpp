// NitaiTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lib.h"
#include <stdlib.h>
#include <iostream>
#define ARR_SIZE 100


using namespace std;

//int arr[10] = { 22, 52, 61, 73, 59, 76, 42, 93, 34, 39 };
int arr[ARR_SIZE];

//__________________________________________________________

void init_array() {

	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = rand() % 1000 + 1;
}

}

//___________________________________________________________

int find_min(int begin_index) {
	int min_number = INT_MAX;
	int min_index = 0;
	for (int i = begin_index; i < ARR_SIZE; i++)
	{
		if (arr[i] < min_number)
		{
			min_number = arr[i];
			min_index = i;
		}
	}
	return min_index;
}

//_________________________________________________________________

void swap(int a,int b) {
	int c;
	c = arr[b];
	arr[b] = arr[a];
	arr[a] = c;
}

//__________________________________________________________________________

void main1()
{

	init_array();

	clrscr();

	int f_m;

	for (int i = 0; i < ARR_SIZE; i++) {
		f_m = find_min(i);
		swap(f_m , i);
	}

	for (int i = 0; i < ARR_SIZE; i++) {
		cout << arr[i] << endl;
	}

	getch();
}



