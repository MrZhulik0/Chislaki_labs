#include "approximation.h"
#include "qcustomplot.h"
#include <Qt>
#include <QPen>
#include <QBrush>
#include <QVector>
#include <QPushButton>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <cmath>

#define WINDOW_W 800
#define WINDOW_H 600

using namespace std;

int main(int argc, char **argv){
    ifstream datafile = ifstream("../src/data.txt");
    int len;
    datafile >> len;
    double* t = new double[len];
    for(int i = 0; i < len; i++){
        datafile >> t[i] ;
    }
    double* r = new double[len];
    for(int i = 0; i < len; i++){
        datafile >> r[i] ;
    }

    double* odds = approx(t, r, len);
    double b = odds[0];
    double a = odds[1];
    cout << "a = "<< b << endl<< "b = " << a << endl;
    cout<<"r = a * t + b"<<endl;
     
    for(int i = 0; i < len; i++){
        cout << r[i]  << " = " << a* t[i]  + b <<endl;
    }
    

    QApplication app(argc, argv);    
    QCustomPlot* customPlot = new QCustomPlot();
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::red));
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    QVector<double> x(8), y(8);
    x[0] = 0;
    y[0] = 0;
    for(int i = 1; i <= 7; i++){
        x[i] = t[i] ;    
        y[i] = r[i] ;    
    }
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->rescaleAxes();
    customPlot->resize(WINDOW_W, WINDOW_H);
    customPlot->show();
    delete[] t;
    delete[] r;
    delete[] odds;
    return app.exec();
}
