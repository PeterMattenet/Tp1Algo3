
#include <iostream>
using namespace std;

bool PuedoColorear(int c, int ultimoRojo, int ultimoAzul, int k) {
	//cout << "Color: " << c << ", numero:" << k << ", ultimoRojo" <<
	if (c==0) {
		return (ultimoRojo == -1) || (ultimoRojo < k);
	}
	return (ultimoAzul == -1) || (ultimoAzul > k);
}

void colorearAux(int n, int a[], int k, int resTemp, int &resMax, int arreglotemp[], int arregloMax[], int ultimoRojo, int ultimoAzul) {
	if (k == n) {
		if (resTemp > resMax) {
			resMax = resTemp;
			for (int i= 0; i<n; i++)
			{
				arregloMax[i] = arreglotemp[i];
			}
		}
	}
	else 
	{
		for(int c = 0; c<2; c++)
		{
			if (PuedoColorear(c,ultimoRojo, ultimoAzul, a[k]))
			{
				arreglotemp[k] = c;
				if (c ==1)
				{
					colorearAux(n, a, k+1, resTemp+1, resMax, arreglotemp, arregloMax, ultimoRojo, a[k] );
				}
				else
				{
					colorearAux(n, a, k+1, resTemp+1, resMax, arreglotemp, arregloMax, a[k], ultimoAzul );
				}
				
			}
		}
		if ( resTemp + n - k  >  resMax)
		{
			colorearAux(n, a, k+1, resTemp, resMax, arreglotemp, arregloMax, ultimoRojo, ultimoAzul );
		}
	}
}


int main() {
	int n = 2;
	int a[3];
	a[0] = 3;
	a[1] = 2;
	//a[2] = 1;
	int resTemp = 0;
	int resMax = 0;
	int arreglotemp[n];
	int arregloMax[n];
	colorearAux(n, a, 0, resTemp, resMax, arreglotemp, arregloMax, -1, -1);
	for (int i = 0; i < n; i++) {
		cout << arregloMax[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos no pintados: " << n - resMax << "." << endl;
	cout << "Rojo: [" ;
	for(int i = 0; i< n ; i++) {
		if (arregloMax[i] == 0){
			if (i == n-1){
				cout << a[n-1];
			}
			else {
				cout << a[i] << ", ";
			}
		}
	}
	cout << "]" << endl;
	cout << "Azul: [";
	for(int i = 0; i< n ; i++) {
		if (arregloMax[i] == 1){
			if (i == n-1){
				cout << a[n-1];
			}
			else {
				cout << a[i] << ", ";
			}
		}
	}
	cout << "]" << endl;
	
}