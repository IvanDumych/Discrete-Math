#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{ 
	int n, r,C;
	cout << "n:";
	cin >> n;
	cout << "r:";
	cin >> r;

	int* N = new int[n];
	for (int i = 0; i < r; i++)
	{
		N[i] = 1;
	}
	C = pow(n, r);

	int k = 0;
	for (int i = 0; i < C; i++) {
		for (int a = 0; a < r; a++) {
			cout << N[a];
		}
		cout << endl;
		if (N[r - 1] == n) {
			k = r - 1;
			for (int a = r-2; a < r; a--) {
				if (N[a] == n)k--;
				else break;
			}
			N[k - 1] += 1;
			for (; k < r; k++) {
				N[k] = 1;
			}

		}
		else {
			N[r - 1]++;
		}


	}
	return 0;
}