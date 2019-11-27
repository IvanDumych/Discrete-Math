#include <iostream>
#include <fstream>
using namespace std;

long int factorial(int N)
{
	if (N < 0) return 0;
	if (N == 0) return 1;
	else
		return N * factorial(N - 1);
}

int main()
{
	int n,m;
	cout << "(x+y)^n"<<endl;
	cout << "n: ";
	cin >> n;
	for (int k = 0; k <= n; k++) {
		m = factorial(n) / (factorial(n - k) * factorial(k));
		if(m!=1) cout << factorial(n) / (factorial(n - k) * factorial(k))<<"*";
		if(k!=0){
			if(k==1)cout << "y";
		    else cout << "y^" << k;
		}
		if (n - k != 0) {
			if(k!=0)cout << "*";

			if (n - k == 1)cout << "x";
			else cout << "x^" << n - k;
		}

		if (k != n) {
			cout << " + ";
		}
	}
	cout << endl << endl;
	return 0;
}

