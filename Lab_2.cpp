#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void main()
{	
	setlocale(LC_ALL, "Ukrainian");

	int size, size2, size3, n;
	cout << "Розмiр множини 1 : ";
	cin >> size;
	cout << "Розмiр множини 2 : ";
	cin >> size2;

	char* arr = new char[size];
	char* arr2 = new char[size2];

	size3 = size + size2;
	char* arr3 = new char[size3];


	cout << "Введiть множину 1:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << endl;

	cout << "Введiть множину 2:" << endl;
	for (int i = 0; i < size2; i++) {
		cin >> arr2[i];
	}
	cout << endl;
	///////// Обєднання
	for (int i = 0; i < size; i++) {
		arr3[i] = arr[i];

	}
	for (int i = size,a=0; i < size3; i++,a++) {
		arr3[i] = arr2[a];
	}
	//////сортування
	int temp; 

	for (int i = 0; i < size3 - 1; i++) {
		for (int j = 0; j < size3 - i - 1; j++) {
			if (arr3[j] > arr3[j + 1]) {
				temp = arr3[j];
				arr3[j] = arr3[j + 1];
				arr3[j + 1] = temp;
			}
		}
	}	//////виключення зайвих
	n = size3;
	for (int i = 0; i < n - 1; i++) {
		if (arr3[i] == arr3[i + 1]) {
			for (int a = i; a < n - 1; a++) {
				arr3[a] = arr3[a + 1];
			}
			n--; 
			i--;
		}
	}
	cout << "Обєднання множин: ";
	for (int i = 0; i < n; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;
	//////знаходження булеана
	int w,e=0;
	w = pow(2,n);

	cout << "Булеан множини: ";
	for (int i = 0; i < w; i++) 
	{
		cout << "{";
		for (int j = 0; j < n; j++) {
			
			if (i & (1 << j)) {
				if (e)
					cout << ",";
				cout << arr3[j];
				e++;


			}
		}
		e = 0;
		cout << "} ";
	}

}
