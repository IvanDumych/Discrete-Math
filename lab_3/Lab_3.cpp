#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	int size;
	cout << "Розмiр множин : ";
	cin >> size;
	cout << endl;

	int* arr = new int[size];
	int* arr2 = new int[size];

	cout << "Введiть множину 1: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << endl;

	cout << "Введiть множину 2: ";
	for (int i = 0; i < size; i++) {
		cin >> arr2[i];
	}
	int** rel = new int* [size];
	for (int j = 0; j < size; j++) {
		rel[j] = new int[size];
	}
	////відношення
	for (int a = 0; a < size; a++) {
		for (int j = 0; j < size; j++) {
			
			rel[a][j] = (arr[a]+2 > arr2[j]*3);

		}
	}
	cout << endl;
	////вивід матриці
	for (int a = 0; a < size; a++) {
		for (int j = 0; j < size; j++) {
			cout << rel[a][j]<<" ";

		}
		cout << endl;
	}
	////рефлексивність
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (rel[i][i] == 1) { k++; }
	}
	if( k == size){
		cout << "Рефлексивне"<< endl;
	}
	else if (k == 0) {
		cout << "Антирефлексивне" << endl;
	}
	else {
		cout << "Арефлексивне" << endl;
	}
	////симетрія
	int c = 0, l = 0;
	for (int i= 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (rel[i][j]  == 1 && i != j) {
				if(rel[i][j] == rel[j][i]){ c = 1; }
				else if (rel[i][j] != rel[j][i]) { l = 1; }
				
			}
				
		}
		
	}
	if(c == 1 && l == 1) {
		cout << "Асиметричне" << endl;
	}
	else if (c == 1 && l == 0) {
	cout << "Симетричне" << endl;
	}
	else if(k > 0) {
	cout << "Антисиметричне" << endl;
	}
	else{ cout << "Асиметричне" << endl; }
	////транзитивність
	bool y = false, n = false;
	for (int i= 0; i < size;i ++) {
		for (int j = 0; j < size;j ++) {
			for (int k = 0; k < size; k++) {
				if (i == j || j == k) { continue; }
				if (rel[i][j] == 1 && rel[j][k] == 1) {
					if (rel[i][k] == 1) { y = true;}
					else { n = true; }
				}
				
			}
		}
	}
	if (y && n) {
		cout << "Атранзитивне" << endl;
	}
	else if (y && n == false) {
		cout << "Транзитивне" << endl;
	}
	else if (y==false && n) {
		cout << "Антитранзитивне" << endl;
	}

	return 0;
}
