#include "Newton.h"
#include "Gauss.h"

using namespace std;

double f1(double x, double y) {
    return 2*x*x*x - y*y - 1;
}

double f2(double x, double y) {
    return x*y*y*y- y - 4;
}

void computeJacobianNumerically(double x, double y, vector<vector <double>>& J, double M) {
    double f1_val = f1(x, y);
    double f2_val = f2(x, y);
    double df1_dx = (f1(x + M, y) - f1_val) / M;
    double df2_dx = (f2(x + M, y) - f2_val) / M;
    double df1_dy = (f1(x, M + y) - f1_val) / M;
    double df2_dy = (f2(x, M + y) - f2_val) / M;
    J[0][0] = df1_dx;
    J[0][1] = df1_dy;
    J[1][0] = df2_dx;
    J[1][1] = df2_dy;
}

void computeJacobianAnalytically(double x, double y, vector<vector <double>>& J) {
    double df1_dx = 6*x*x;
    double df1_dy = 2*y;
    double df2_dx = y*y*y;
    double df2_dy = 3*x*y*y - 1;
    J[0][0] = df1_dx;
    J[0][1] = df1_dy;
    J[1][0] = df2_dx;
    J[1][1] = df2_dy;
}

void printNumerically(double M){
    const double e1 = 1e-9;
    const double e2 = 1e-9;
    const int NIT = 100;
    double x = 1.0;
    double y = 1.0;
    int k = 1;
    cout<<"##############################################################################"<<endl;
    cout<<"M = "<<M<<endl;
    cout<<"Iteration |" << setw(12) << "x" << setw(6)<<"|"<< setw(12) << "y" << setw(6)<<"|"<< setw(12) << "b1" << setw(6)<<"|" << setw(12)<< "b2" << endl;
    while (k <= NIT) {
        vector<vector<double>> J(2, vector<double>(2));
        computeJacobianNumerically(x, y, J, M);
        vector<double> F = {f1(x, y), f2(x, y)};
        vector<double> increments(2);
        if(!gauss(J, F, 2, increments))
            break;
        x-=increments[0];
        y-=increments[1];
        double b1 = max(abs(F[0]), abs(F[1]));
        double b2 = max(abs(increments[0]), abs(increments[1]));
        b2 = max(b2, abs(increments[0] / x));
        b2 = max(b2, abs(increments[1] / y)); 
        cout << k ;
        if(k<10)
            cout<<setw(10);
        else
            cout<<setw(9);
        cout<<"|"<<setw(12)<< x << setw(6)<<"|"<< setw(12) << y << setw(6)<<"|"<< setw(12) << b1 << setw(6)<<"|" << setw(12)<< b2 << endl;        
        if (b1 <= e1 && b2 <= e2) {
            cout << "Converged to the desired precision." << endl;            
            break;
        }
        if (k >= NIT) {
            cout << "Iteration limit reached. IER = 2" << endl;
            break;
        }
    k++;
    }
    cout << "f1("<< x <<","<< y <<") = "<<f1(x, y) << endl;
    cout << "f2("<< x <<","<< y <<") = "<<f2(x, y) << endl;
}

void printAnalytically(){
    const double e1 = 1e-9;
    const double e2 = 1e-9;
    const int NIT = 100;
    double x = 1.0;
    double y = 1.0;
    int k = 1;
    cout<<"##############################################################################"<<endl;
    cout<<"Jacobian Analytically:"<<endl;
    cout<<"Iteration |" << setw(12) << "x" << setw(6)<<"|"<< setw(12) << "y" << setw(6)<<"|"<< setw(12) << "b1" << setw(6)<<"|" << setw(12)<< "b2" << endl;
    while (k <= NIT) {
        vector<vector<double>> J(2, vector<double>(2));
        computeJacobianAnalytically(x, y, J);
        vector<double> F = {f1(x, y), f2(x, y)};
        vector<double> increments(2);
        if(!gauss(J, F, 2, increments))
            break;
        x-=increments[0];
        y-=increments[1];
        double b1 = max(abs(F[0]), abs(F[1]));
        double b2 = max(abs(increments[0]), abs(increments[1]));
        b2 = max(b2, abs(increments[0] / x));
        b2 = max(b2, abs(increments[1] / y)); 
        cout << k ;
        if(k<10)
            cout<<setw(10);
        else
            cout<<setw(9);
        cout<<"|"<<setw(12)<< x << setw(6)<<"|"<< setw(12) << y << setw(6)<<"|"<< setw(12) << b1 << setw(6)<<"|" << setw(12)<< b2 << endl;        
        if (b1 <= e1 && b2 <= e2) {
            cout << "Converged to the desired precision." << endl;            
            break;
        }
        if (k >= NIT) {
            cout << "Iteration limit reached. IER = 2" << endl;
            break;
        }
    k++;
    }
    cout << "f1("<< x <<","<< y <<") = "<<f1(x, y) << endl;
    cout << "f2("<< x <<","<< y <<") = "<<f2(x, y) << endl;
}
