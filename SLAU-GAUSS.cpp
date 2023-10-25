#include "Header.h"

void ForwardRunGauss(vector<vector<double>>& table) { // DOESNT ACCOUNT FOR r < n;
	size_t n = table.size(); // stroki
	size_t r = table[0].size() - 1; //stolbci bez svobodnogo chlena

	cout << "Do pryamogo hoda: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
	cout << endl; 

	if (n < r) {
		throw invalid_argument("beskonechnost' resheniy (esli ne r-n nulevih stolbcov, ya ne budu eto proveryat)");
	}

	if (r < n) {
		throw invalid_argument("razmernost' ne nxn (oops!)");
	}

	for (size_t jmin = 0; jmin < r; jmin++) {
		size_t imin = jmin;

		double AMAX = 0;
		size_t IMAX;

		for (size_t ee = jmin; ee < r; ee++) { // finding out which row has the element with the largest module within this column;
			if (abs(table[ee][jmin]) > abs(AMAX)) {
				AMAX = table[ee][jmin];
				IMAX = ee;
			}
		}
		AMAX;

		if (AMAX == 0) throw invalid_argument("beskonechnost' resheniy ili net resheniy (AMAX = 0)"); // if a column consists entirely of 0;

		for (int jswap = jmin; jswap < (r + 1); jswap++) { // swapped the first row with the row found earlier;
			double a = table[imin][jswap];
			table[imin][jswap] = table[IMAX][jswap];
			table[IMAX][jswap] = a;
		}

		for (int j1 = jmin; j1 < (r + 1); j1++) {
			table[imin][j1] /= AMAX;
		} // divided the "first" row by the "first" element;
		for (size_t i2 = imin + 1; i2 < r; i2++) {
			double A2 = table[i2][jmin];
			for (size_t j2 = jmin; j2 < r + 1; j2++) {
				table[i2][j2] -= A2 * table[imin][j2];
			}
		} // subtracted the "first" row from all later rows, multiplied by the first element of each later row;
	}
	cout << "Treugolnyy vid:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void ReverseRunGauss(vector<vector<double>>& table, vector<double>& solution) {
	size_t n = table.size();
	size_t r = table[0].size() - 1;

	for (int imin = r - 1; imin > -1; imin--) {
		int jmin = imin;
		solution[jmin] = table[imin][r]; // q

		for (int j = jmin + 1; j < r; j++) {
			solution[jmin] -= table[imin][j] * solution[j]; // q - an*xn - ...;
		}
	}
	solution;
}