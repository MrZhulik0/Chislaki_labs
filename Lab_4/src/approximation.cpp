 #include "approximation.h"
#include <cmath>

#define M 2

double* approx(double* t , double* r, int n){
    double** sums = new double*[M];
    for(int i = 0; i < M; i++){
        sums[i] = new double[M];
        for(int j = 0; j < M; j++){
            double sum0 = 0;
            for(int k = 0; k < n; k++){
                sum0 += pow(t[k], i+j);
            }
            sums[i][j] = sum0;
        }
    }
    double* sums_y = new double[M];
    for(int i = 0; i < M; i++){
        double sumxy = 0;
        for(int j = 0; j < n; j++){
            sumxy += r[j]*pow(t[j], i);
        }
        sums_y[i] = sumxy;
    }
    double *solutions = new double[M];
    gauss(sums, sums_y, solutions, M);
    return solutions;
}
