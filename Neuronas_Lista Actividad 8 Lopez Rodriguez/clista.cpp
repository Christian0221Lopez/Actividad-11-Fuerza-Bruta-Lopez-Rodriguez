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



        if(Pnn == nullptr)
        {
            Pnn = new Neurona;
            Pnn->InsertarAdelantefloat(id,V,pX,pY,r,g,b);
        }
        else
        {
            Pnn->InsertarAdelantefloat(id,V,pX,pY,r,g,b);
        }

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

    while(i<=Pnn->cont)
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


/*void Clista::ordenarCoordenadas(int* x1, int n,int* x2,int* Fx)
{
    std::sort(x1, x1 + n);
    int contR = 0;
    int j = 0;
    int i = 0;

    while(j<n)
    {
            if(x1[j]>x2[i])
            {
                Fx[j] = x2[i];
                j++;
            }
            i++;
         if(i=n)
         {
             i = 0;
         }
    }

    std::cout << "Coordenadas ordenadas1: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "(" << Fx[i] << ", " << ")" << std::endl;
    }


    std::cout << "Coordenadas ordenadas2: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "(" << x2[i] << ", " << ")" << std::endl;
    }
}*/;
/*void Clista::ordenarCoordenadas(int* x1, int n, int* x2, int* Fx)
{
    std::sort(x1, x1 + n);
    std::vector<bool> used(n, false); // Vector para marcar las coordenadas ya utilizadas en Fx
    int j = 0;

    for (int i = 0; i < n; i++) {
        // Si x2[i] es menor o igual que x1[j], se guarda en Fx y se marca como usada
        if (x2[i] <= x1[j]) {
            if (x2[i] != x1[j]) { // Se verifica que no sean la misma coordenada
                Fx[j] = x2[i];
                used[i] = true;
                j++;
            }
        }
        else {
            // Se busca la coordenada no usada más cercana a x1[j] y se guarda en Fx
            int k = i;
            while (k < n && (used[k] || x2[k] == x1[j])) {
                k++;
            }
            if (k < n) {
                Fx[j] = x2[k];
                used[k] = true;
                j++;
            }
        }
        if (j == n) {
            break; // Se han guardado todas las coordenadas en Fx
        }
    }

    std::cout << "Coordenadas ordenadas1: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "(" << Fx[i] << ", " << ")" << std::endl;
    }

    std::cout << "Coordenadas ordenadas2: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "(" << x2[i] << ", " << ")" << std::endl;
    }
}*/;

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

void Clista::ordenarCoordenadas(int* x1,int* x2,int* y1, int* y2, int* Fx,int* Fy,int n)
{
    std::sort(x1, x1 + n);


   for(int i = 0;i<n;i++)
   {
       int j = 0;
       for(j=0;j<n;j++)
       {
           if(x1[i]<x2[j])
           {
               float dist = std::sqrt(std::pow(x1[i] - x2[j], 2) + std::pow(y1[i] - y2[j], 2));
               //int res = x1[i]-x2[j];
               cout<<i<<" "<<x1[i]<<" "<<dist<<" "<<x2[j]<<" "<<j<<"menor"<<endl;
               if(dist<=200)
               {
                   Fx[i] = x2[j];
                   Fy[i] = y2[j];
                   i++;
               }
               else if(dist<300)
               {
                   Fx[i] = x2[j];
                   Fy[i] = y2[j];
                   i++;
               }
           }
           if(x1[i]>x2[j])
           {
               float dist = std::sqrt(std::pow(x1[i] - x2[j], 2) + std::pow(y1[i] - y2[j], 2));
               //int res = x2[j]-x1[i];
               cout<<i<<" "<<x1[i]<<" "<<dist<<" "<<x2[j]<<" "<<j<<"mayor"<<endl;
               int max = 300;
               if(dist>max)
               {
                   Fx[i] = x2[j];
                   Fy[i] = y2[j];
                   i++;
               }
               else if(dist>max+100)
               {
                   Fx[i] = x2[j];
                   Fy[i] = y2[j];
                   i++;
               }
           }
           if(x1[i]==x2[j])
           {
               float dist = std::sqrt(std::pow(x1[i] - x2[j], 2) + std::pow(y1[i] - y2[j], 2));
               cout<<i<<" "<<x1[i]<<" "<<dist<<" "<<x2[j]<<" "<<j<<"igual"<<endl;

               if(dist<300)
               {
               if(y1[i]!=y2[j])
               {
                   Fx[i] = x2[j];
                   Fy[i] = y2[j];
                   i++;
               }
               }
               else
               {
                   Fx[i] = x2[j];
                   Fy[i] = y2[j];
                   i++;
               }
               std::cout<<"nel prro"<<x2[j]<<std::endl;
           }
       }

   }

}








