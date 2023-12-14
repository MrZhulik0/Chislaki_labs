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
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 10)));
    QVector<double> x(8), y(8);
    for(int i = 0; i < 7; i++){
        x[i] = t[i];    
        y[i] = a*t[i] + b;    
    }
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->rescaleAxes();
    //customPlot->show();
    //customPlot->resize(WINDOW_W, WINDOW_H);
//////////////////////////////////////////////////////////////////////////
    //QCustomPlot* customPlot1 = new QCustomPlot();
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::green));
    customPlot->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 10)));
    QVector<double> x1(7), y1(7);
    x1[0] = 19.1;
    y1[0] = 76.3;
    x1[1] = 25.0;
    y1[1] = 77.8;
    x1[2] = 30.1;
    y1[2] = 79.75;
    x1[3] = 36.0;
    y1[3] = 80.80;
    x1[4] = 40.0;
    y1[4] = 82.35;
    x1[5] = 45.1;
    y1[5] = 83.90;
    x1[6] = 50.0;
    y1[6] = 85.0;
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->graph(1)->setData(x1, y1);
    customPlot->graph(1)->rescaleAxes();
    customPlot->show();
    customPlot->resize(WINDOW_W, WINDOW_H);
/////////////////////////////////////////////////////////////////////////////
    
    delete[] t;
    delete[] r;
    delete[] odds;
    return app.exec();
}
