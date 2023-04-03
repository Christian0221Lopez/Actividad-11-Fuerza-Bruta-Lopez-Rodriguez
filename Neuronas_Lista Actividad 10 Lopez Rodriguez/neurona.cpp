#include "neurona.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include <string>
#include <sstream>
#include <QApplication>

using namespace std;

void Neurona::InsertarAdelantefloat(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{
    Neurona* Pnn = new Neurona;

      Pnn->Id = id;
      Pnn->Voltaje = voltaje;
      Pnn->Pos_x = pos_x;
      Pnn->Pos_y = pos_y;
      Pnn->Red = red;
      Pnn->Green = green;
      Pnn->Blue = blue;

      Pnn->pAnt = this;
      if (this->pSig == NULL) {
          // La lista está vacía, añadir el nuevo nodo al final
          Pnn->pSig = NULL;
          this->pSig = Pnn;
      } else {
          // La lista tiene al menos un nodo
          this->pSig->pAnt = Pnn;
          Pnn->pSig = this->pSig;
          this->pSig = Pnn;
      }

      cont++;
      cout <<cont<<"agregar "<<endl;
}

float Neurona::EliminarSiguiente()
{
    Neurona* Pnn = this->pAnt->pAnt;

    delete this->pAnt;

    this->pAnt = Pnn;
    Pnn->pSig = this;

    return 0;

}

void Neurona::BusquedaL(QString label, int& ID, float& Volt, int& x, int& y, int& r, int& g, int& b)
{
    Neurona* Pnn = this->pSig;

    int bandera = 0;
    bool ok = 0;

    int num = label.toInt(&ok);
    if (!ok) {
      cout << "Conversion failed. Repeat conversion" <<endl;
    }
        if(cont > 0)
        {
            while(Pnn != nullptr)
            {
                 //cout<<num<<"Primero "<<endl;
                if(Pnn->Id == num)
                {
                    ID = Pnn->Id;
                    Volt = Pnn->Voltaje;
                    x = Pnn->Pos_x;
                    y = Pnn->Pos_y;
                    r = Pnn->Red;
                    g = Pnn->Green;
                    b = Pnn->Blue;
                    return;
                }

                Pnn = Pnn->pSig;
            }
        }

        else
        {
            cout<<"\n\tRegistro vacio..!";
        }

        if(bandera==0)
        {
            cout<<"\n\n\tEl Disco no fue encontrado..! :S"<<endl;

        }
}
