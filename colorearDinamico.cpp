
#include <iostream>
#include <vector>
using namespace std;

int n;
int recursionCount = 0;
int operationsCount = 0;
vector<vector<vector<int> > > matrix;
vector<int> a;


int maximo(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	if (b >= a && b >= c) return b;
	return c;
}

int colorearDinamicoAux( int i, int ultRojo, int ultAzul) {
	
	recursionCount++;
	if (i == n) return 0;

	if ( matrix[i][ultRojo][ultAzul] != -1) return matrix[i][ultRojo][ultAzul];

	int resRojo = -1;
	int resAzul = -1;
	
	
	if (ultRojo == n || a[i] > a[ultRojo]) {
		resRojo = colorearDinamicoAux(i+1, i, ultAzul);
	}

	if (ultAzul == n || a[i] < a[ultAzul]) {
		resAzul = colorearDinamicoAux(i+1, ultRojo, i);
	}
	int resNoPinte = colorearDinamicoAux(i+1, ultRojo, ultAzul);

	operationsCount++;
	matrix[i][ultRojo][ultAzul] = maximo(resAzul, resRojo, resNoPinte);
	cout << "Argumentos: i = " << i << ", ultRojo = " << ultRojo << ", ultAzul = " << ultAzul << endl;
	cout << "Result: " << matrix[i][ultRojo][ultAzul] << endl;
	return matrix[i][ultRojo][ultAzul];
}


int main() {

	n = 5;

	a.push_back(5);
	a.push_back(2);
	a.push_back(8);
	a.push_back(9);
	a.push_back(1);

	for(int i = 0; i < n; i++) {
		vector<vector<int> > v1;
		matrix.push_back(v1);
		for(int j = 0; j <= n; j++) {
			vector<int> v2;
			matrix[i].push_back(v2);
			for(int k = 0; k <= n; k++) {
				matrix[i][j].push_back(-1);
			}
		}
	}

	cout << colorearDinamicoAux(0, n, n) << endl;
	cout << "recursionCount: " << recursionCount << endl;
	cout << "operationsCount: " << operationsCount << endl;
}