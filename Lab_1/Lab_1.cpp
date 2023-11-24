#include"Header.h"

int main()
{
	size_t lines; // srtrok
	size_t column; // stolbcov ne schitaya svobodnyie chleny

	cout << "n (number of lines) = ?" << endl;
	cin >> lines;
	if (!lines) {
		cout << "n != 0";
		return 0;
	}
	cout << endl;

	cout << "r (number of columns) = ?" << endl;
	cin >> column;
	if (!column) {
		cout << "r != 0";
		return 0;
	}
	cout << endl;

	vector<vector<double>> table = vector<vector<double>>();
	for (size_t i = 0; i < lines; i++) {
		table.push_back(vector<double>(column + 1, 0));
	}
	for (size_t i = 0; i < lines; i++) {
		for (size_t j = 0; j < column + 1; j++) {
			cout << "input " << i + 1 << " " << j + 1 << endl;
			cin >> table[i][j];
		}
	}
	vector<vector<double>> tableCopy = table;

	system("cls");

	ForwardRunGauss(table);

	vector<double> solution(column, 0);

	ReverseRunGauss(table, solution);

	for (size_t i = 0; i < column; i++) {
		cout << "X" << i << " = " << solution[i] << endl;
	}
	cout << endl;

	double norma = 0;
	cout << "Vektor nevyazki: " << endl; //Vektor nevyazki
	for (int w = 0; w < column; w++)
	{
		double s = 0;
		for (int f = 0; f < column; f++)
			s += tableCopy[w][f] * solution[f];
		if (abs(s - tableCopy[w][column]) > norma)
			norma = s - tableCopy[w][column];
		cout << s - tableCopy[w][column] << endl;
	}
	cout << endl;
	
	
	cout << "Norma vektora nevyazki = " << norma << endl;
	//cout << "Otnosit. pogreshnost' = " << norm / solution[Delta_I] << endl;

}
