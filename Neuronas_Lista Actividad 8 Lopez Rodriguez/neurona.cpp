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


/*void Neurona::Busqueda(int* id,int* idEncontrados, float* voltajes, int* posicionesX, int* posicionesY, int* coloresR, int* coloresG, int* coloresB) {
    // Inicializar los arreglos de salida en cero
    memset(idEncontrados, 0, cont * sizeof(int));
    memset(voltajes, 0, cont * sizeof(float));
    memset(posicionesX, 0, cont * sizeof(int));
    memset(posicionesY, 0, cont * sizeof(int));
    memset(coloresR, 0, cont * sizeof(int));
    memset(coloresG, 0, cont * sizeof(int));
    memset(coloresB, 0, cont * sizeof(int));

    // Buscar las neuronas en la lista
    int numEncontrados = 0;
    Neurona* ptr = this->pSig;
    int inicio = 0;
    int fin = cont - 1;
    while (ptr != nullptr && inicio <= fin && numEncontrados < cont) {
        int medio = (inicio + fin) / 2;
        if (id[medio] == ptr->Id) {
            idEncontrados[numEncontrados] = ptr->Id;
            voltajes[numEncontrados] = ptr->Voltaje;
            posicionesX[numEncontrados] = ptr->Pos_x;
            posicionesY[numEncontrados] = ptr->Pos_y;
            coloresR[numEncontrados] = ptr->Red;
            coloresG[numEncontrados] = ptr->Green;
            coloresB[numEncontrados] = ptr->Blue;
            numEncontrados++;
            ptr = ptr->pSig;
        }
        else if (id[medio] < ptr->Id) {
            fin = medio - 1;
        }
        else {
            inicio = medio + 1;
        }
    }

    // Comprobar si se encontraron todas las neuronas solicitadas
    if (numEncontrados < cont) {
        cout << "No se encontraron todas las neuronas solicitadas" << endl;
    }
}*/;
