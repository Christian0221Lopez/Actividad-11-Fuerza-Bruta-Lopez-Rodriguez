#include "clista.h"
#include "neurona.h"
#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <QApplication>
#include<QFileDialog>
#include<QMessageBox>
#include <QStringList>
#include <QtCore/QString>
#include <QtGlobal>
#include <cmath>
#include <algorithm>

using namespace std;

Clista::Clista()
{
    Inicio = new Neurona;
    Final = new Neurona;

    Inicio->pSig = Final;
    Final->pAnt = Inicio;

    Final->pSig = NULL;
    Inicio->pAnt = NULL;
}

void Clista::InsertarInicio(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{

    Inicio->InsertarAdelantefloat(id,voltaje,pos_x,pos_y,red,green,blue);
    cont++;

}

void Clista::InsertarFinal(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{

    Final->pAnt->InsertarAdelantefloat(id,voltaje,pos_x,pos_y,red,green,blue);
    cont++;
}

float Clista::EliminarInicio()
{

    Inicio->pSig->pSig->EliminarSiguiente();

    return 0;
}

float Clista::EliminarFinal()
{

    Final->EliminarSiguiente();

    return 0;
}

int Clista::Tamanio()
{
    Neurona* Pnn = Inicio->pSig;
    int l = 0;

    while (Pnn != Final)
    {
        l++;
        Pnn = Pnn->pSig;
    }
    return l;
}

void Clista::Vaciar()
{
    Inicio->pSig = Final;
    Final->pAnt = Inicio;
}

QString Clista::Set()
{
    Neurona* Pnn = Inicio->pSig;
    QString Oracion;
    QString oracion;

    while(Pnn!=Final)
    {
        Oracion.append("ID: ");
        oracion = QString::number(Pnn->Id);
        Oracion.append(oracion);
        Oracion.append(" Voltaje:");
        oracion = QString::number(Pnn->Voltaje);
        Oracion.append(oracion);
        Oracion.append(" Pos_x:");
        oracion = QString::number(Pnn->Pos_x);
        Oracion.append(oracion);
        Oracion.append(" Pos_y:");
        oracion = QString::number(Pnn->Pos_y);
        Oracion.append(oracion);
        Oracion.append(" Red:");
        oracion = QString::number(Pnn->Red);
        Oracion.append(oracion);
        Oracion.append(" Green:");
        oracion = QString::number(Pnn->Green);
        Oracion.append(oracion);
        Oracion.append(" Blue:");
        oracion = QString::number(Pnn->Blue);
        Oracion.append(oracion);
        Oracion.append("\n\n");

        Pnn = Pnn->pSig;
    }

    return Oracion;
}


void Clista::Save(QString filename)
{
    Neurona* Pnn = Inicio->pSig;


    QByteArray ba = filename.toLatin1();
    const char *file = ba.data();

    ofstream File(file);

        if (!File.is_open()) {
                cerr <<"Error de apertura "<<endl;
                return;
            }

        while (Pnn != Final) {
            if (Pnn->Id != -1) {
                File << Pnn->Id << "\n";
                File << Pnn->Voltaje << "\n";
                File << Pnn->Pos_x << "\n";
                File << Pnn->Pos_y << "\n";
                File << Pnn->Red << "\n";
                File << Pnn->Green << "\n";
                File << Pnn->Blue;
            }
            Pnn = Pnn->pSig;
        }

        File.close();
}

void Clista::Recover(QString filename)
{
    Neurona* Pnn = Inicio->pSig;

    QByteArray ba = filename.toLatin1();
    const char *file = ba.data();
    int i = 0;

    ifstream File(file);

    if(!File)
       {
           cout <<"Archivo no encontrado "<<endl;
           return;
       }


        if(File.is_open())
        {

        while(!File.eof())
        {
            int id = 0;
            float V = 0;
            int pX = 0;
            int pY = 0;
            int r = 0;
            int g = 0;
            int b = 0;
            string oracion;
            stringstream ss;
            stringstream ss2;
            stringstream ss3;
            stringstream ss4;
            stringstream ss5;
            stringstream ss6;
            stringstream ss7;

            std::getline(File,oracion);
            ss << oracion;
            ss >> id;

            std::getline(File,oracion);
            ss2 << oracion;
            ss2 >> V;

            std::getline(File,oracion);
            ss3 << oracion;
            ss3 >> pX;

            std::getline(File,oracion);
            ss4 << oracion;
            ss4 >> pY;

            std::getline(File,oracion);
            ss5 << oracion;
            ss5 >> r;

            std::getline(File,oracion);
            ss6 << oracion;
            ss6 >> g;

            std::getline(File,oracion);
            ss7 << oracion;
            ss7 >> b;




                Pnn->InsertarAdelantefloat(id,V,pX,pY,r,g,b);
                Pnn = Pnn->pSig;


            i++;
        if(File.eof())
            {
                break;
            }


        }

    }
         File.close();
}

void Clista::BusquedaL(QString label, int& ID, float& Volt, int& x, int& y, int& r, int& g, int& b)
{
    Inicio->BusquedaL(label,ID,Volt,x,y,r,g,b);
}

void Clista::Busqueda(int* Orden,int* ID, float* Volt, int* x, int* y, int* r, int* g, int* b)
{
    Neurona* Pnn = Inicio->pSig;

    int i = 0;

    while(i<Pnn->cont)
    {
    while (Pnn != Final)
    {
        if (Pnn->Id == Orden[i])
        {
            ID[i] = Pnn->Id;
            Volt[i] = Pnn->Voltaje;
            x[i] = Pnn->Pos_x;
            y[i] = Pnn->Pos_y;
            r[i] = Pnn->Red;
            g[i] = Pnn->Green;
            b[i] = Pnn->Blue;
            i++;
            }
        Pnn = Pnn->pSig;
     }
    if(Pnn = Final)
    {
        Pnn = Inicio->pSig;
    }
 }

    if (i == 0)
    {
        cout << "\n\n\tNinguna neurona encontrada con los IDs especificados..! :S" << endl;
    }
}


void Clista::Sort(int*A,int primero,int ultimo)
{
    int central = 0;
    int i = 0;
    int j = 0;
    double pivote;
    central=(primero+ultimo)/2;
    pivote=A[central];
    i=primero;
    j=ultimo;
    do
        {
            while(A[i]<pivote) i++;
            while(A[j]>pivote) j--;
            if(i<=j)
            {
                double temp;
                temp=A[i];
                A[i]=A[j]; /*intercambia A[i] con A[j] */
                A[j]=temp;
                i++;
                j--;
            }
        }

    while(i<=j);
    if(primero<j)
        Sort(A,primero,j); /*mismo proceso con sublista izquierda*/
    if(i<ultimo)
        Sort(A,i,ultimo); /*mismo proceso con sublista derecha*/

}


void Clista::setID(int *id)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        id[i] = Pnn->Id;
        i++;
        Pnn = Pnn->pSig;
    }
}

void Clista::setV(float *v)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        v[i] = Pnn->Voltaje;
        i++;
        Pnn = Pnn->pSig;
    }
}

void Clista::setX(int* x)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        x[i] = Pnn->Pos_x;
        i++;
        Pnn = Pnn->pSig;
    }
}

void Clista::setY(int* y)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        y[i] = Pnn->Pos_y;
        i++;
        Pnn = Pnn->pSig;
    }
}

void Clista::setR(int* r)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        r[i] = Pnn->Red;
        i++;
        Pnn = Pnn->pSig;
    }
}

void Clista::setG(int* g)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        g[i] = Pnn->Green;
        i++;
        Pnn = Pnn->pSig;
    }
}

void Clista::setB(int* b)
{
    Neurona* Pnn = Inicio->pSig;
    int i = 0;
    while(Pnn != Final)
    {
        b[i] = Pnn->Blue;
        i++;
        Pnn = Pnn->pSig;
    }
}



#include <cmath>
#include <iostream>
#include <vector>

void Clista::BusquedaX(int* Orden,int* posx,int* posy)
{

    Neurona* Pnn = Inicio->pSig;

    int i = 0;

    while(i<Pnn->cont)
    {
    while (Pnn != Final)
    {
        if (Pnn->Pos_x == Orden[i])
        {
            posx[i] = Pnn->Pos_x;
            posy[i] = Pnn->Pos_y;
            i++;
            }
        Pnn = Pnn->pSig;
     }
    if(Pnn = Final)
    {
        Pnn = Inicio->pSig;
    }
 }

    if (i == 0)
    {
        cout << "\n\n\tNinguna neurona encontrada con los IDs especificados..! :S" << endl;
    }
}

void Clista::FuerzaBruta(int* x,int* y,int* x2,int* y2,int n)
{
    //std::sort(x1, x1 + n);

    int contD = 0;
    int band = 0;
    const int INF = numeric_limits<int>::max();
    bool bandera = false;
    int i = 0;

    int dmin = 900;
    for(int i = 1;i<n-1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            int dist = std::sqrt(std::pow(x[i] - x[j], 2) + std::pow(y[i] - y[j], 2));
            if(dist<dmin)
            {
                 dmin = dist;
            }
        }
    }

    for (int i = 0; i < n; i++) {
            int minDist = INF;
            int minIndex = -1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int dist = std::sqrt(std::pow(x[i] - x[j], 2) + std::pow(y[i] - y[j], 2));
                if (dist < minDist) {
                    minDist = dist;
                    minIndex = j;
                }
            }
            x2[i] = x[minIndex];
            y2[i] = y[minIndex];
        }
}



