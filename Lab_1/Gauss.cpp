#include "Header.h"
using namespace std;

void IntializationOftableElements(int n, double** table,double** TableS) {
	for (int i = 0; i < n; i++) {
		table[i] = new double[n];
		TableS[i] = new double[n];
	}
}
void ZeroingFandAx(int n, double* F, double* Ax) {
	for (int i = 0; i < n; i++) {
		F[i] = 0;
		Ax[i] = 0;
	}
}
void EnterMethod(int& n){
	cin >> n;
}
void EnterElements(int n, double** table,double** TableS) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
			TableS[i][j] = table[i][j];
		}
	}
}
void EnterFreeElements(int n,double* b,double*bs){
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		bs[i] = b[i];
	}
}
void CoutInitialtable(int n, double** table,double* b){
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			//cout << "[" << i << "]" << "[" << j << "]";
			cout << table[i][j] << "  ";
		}
		cout << "| " << b[i];
		cout << endl << endl;
	}
}
void ExpandedtableComputation(int n, double** table, double* b,double*x) {
	for (int k = 0; k < n; k++) {
		double d = 0;
		if (table[k][k] == 0) {
			continue;
		}
		for (int j = k + 1; j < n; j++) {
			d = table[j][k] / table[k][k];
			for (int i = k; i < n; i++)
			{
				table[j][i] = table[j][i] - d * table[k][i];
			}
			b[j] = b[j] - d * b[k];

		}
	}
	for (int k = 0; k < n; k++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (table[k][j] == 0) {
				count++;
			}
		}
		if (count == 2)
		{
			for (int j = 0; j < n; j++) {
				swap(table[k][j], table[n - 1][j]);
				
			}
			swap(b[k], b[n - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}

	for (int k = n - 1; k >= 0; k--)
	{
		double d = 0;
		double s;
		if (table[k][k] == 0) {
			continue;
		}

		for (int j = 0; j < n; j++)
		{
			s = table[k][j] * x[j];
			d = d + s;
		}
		x[k] = b[k] - d;
		x[k] = x[k] / table[k][k];

	}
}
void CoutOfX(int n, double* x) {
	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "]=" <<  setprecision(17) << x[i] << " " << endl;
	}
}
void CalculationOfResidualVectorAndNorm(int n,double** TableS, double* x,double*bs,double* F,double& Delta){
	double max = F[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			F[i] = F[i] + (TableS[i][j] * x[j]);
		}
		F[i] = F[i] - bs[i];
	}
	for (int i = 0; i < n; i++) {
		if (abs(F[i]) > max) {
			max = abs(F[i]);
		}
		if (i == n - 1) {
			Delta = abs(max);
		}
	}
}
void CoutOfFAndDelta(int n,double*F,double Delta) {
	for (int i = 0; i < n; i++) {
		cout << "F[" << i << "]=" << F[i] << endl;
	}
	cout << "Delta:" << endl;
	cout << Delta << endl;
}
void CalculationOfAx(int n,double* Ax, double** table,double** TableS,double *x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Ax[i] = Ax[i] + (TableS[i][j] * x[j]);
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			table[i][j] = TableS[i][j];
		}
	}
}
void CalculationOfdelta(int n,double*x,double* xs,double& delta) {
	double max = 0;
	double max1 = 0;
	for (int i = 0; i < n; i++) {
		if (abs(x[i]) > max) {
			max = abs(x[i]);
		}
		if (abs(xs[i] - x[i]) > max1) {
			max1 = abs(xs[i] - x[i]);
		}
	}
		delta = abs(max1) / abs(max);
}
