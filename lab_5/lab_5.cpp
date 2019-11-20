#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Ukrainian");

	int v, count = 0, min = 0, k, t;
	bool check =false;
	cout << "Кiлькiсть вершин графа : ";
	cin >> v;
	int* tops = new int[v];
	int** graph = new int* [v];
	int** ribs = new int* [v - 1];

	for (int j = 0; j < v; j++) {
		graph[j] = new int[v];
	}

	for (int j = 0; j < v - 1; j++) {
		ribs[j] = new int[2];
	}

	for (int a = 0; a < v; a++) {
		for (int j = 0; j < v; j++) {
			cin >> graph[a][j];

		}
	}
	//////Будуємо дерево, що включає в себе одну вершину

	tops[count] = 1;
	count++;

	 ///Знаходження мінімального кістякового дерева
	for (int i = 0; count < v; i++) {
		for (int j = 0; j < count;j++) {
			for (int a = 0; a < v; a++) {
				for (int m = 0; m < count; m++) {
					if (tops[m] == a + 1) {
						check = true;
					}
				}
				if (check) { check = false; continue; }
				if (min == 0 && graph[tops[j] - 1][a] > 0) {
					min = graph[tops[j] - 1][a]; 
					k = ribs[count - 1][0] = tops[j]; t = ribs[count - 1][1] = a + 1;
					continue;
				}
				if (graph[tops[j] - 1][a] > 0 && graph[tops[j] - 1][a] < min) {
					min = graph[tops[j] - 1][a];
					k=ribs[count-1][0] = tops[j]; t = ribs[count-1][1] = a + 1;
				}
			}
			

		}

		graph[k-1][t-1] = 0; graph[t-1][k-1] = 0;

		tops[count] = t;
		count++;
		min = 0;


	}
	/////Результат
	

	cout << "V: { ";
	for (int j = 0; j < v; j++) {
		cout << tops[j]<<", ";
	}
	cout << "}";
	cout <<endl<< "E:{ ";
	for (int j = 0; j < v - 1; j++) {
		cout << "( " << ribs[j][0]<<", "<< ribs[j][1]<<" ), ";
	}
	cout << "}";

		return 0;
	}

	/*
0 2 7 1 0 0 0 0 0 0 0
2 0 0 0 2 0 7 0 0 0 0
7 0 0 0 1 4 0 0 0 0 0
1 0 0 0 0 3 5 0 0 0 0
0 2 1 0 0 0 0 4 5 0 0
0 0 4 3 0 0 0 6 0 2 0
0 7 0 5 0 0 0 0 3 7 0
0 0 0 0 4 6 0 0 0 0 3
0 0 0 0 5 0 3 0 0 0 4
0 0 0 0 0 2 7 0 0 0 4
0 0 0 0 0 0 0 3 4 4 0

	*/

	