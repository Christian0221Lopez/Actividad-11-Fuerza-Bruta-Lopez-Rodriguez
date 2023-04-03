#ifndef CLISTA_H
#define CLISTA_H
#include "neurona.h"


class Clista
{
private:
    Neurona* Inicio = nullptr;
    Neurona* Final = nullptr;
    int cont;
    friend class Neurona;
public:
    Clista();
        ~Clista() {
            // Liberar la memoria asignada a las neuronas
            delete Inicio;
            delete Final;
        }
    void InsertarInicio(int,float,int,int,int,int,int);
    void InsertarFinal(int,float,int,int,int,int,int);
    float EliminarInicio();
    float EliminarFinal();
    int Tamanio();
    void Vaciar();
    QString Set();
    void BusquedaL(QString,int&,float&,int&,int&,int&,int&,int&);
    void BusquedaX(int*,int*,int*);
    void Busqueda(int*,int*,float*,int*,int*,int*,int*,int*);
    void Save(QString);
    void Recover(QString);
    void Sort(int*,int,int);
    void FuerzaBruta(int*,int*,int*,int*,int);
    void setID(int*);
    void setV(float*);
    void setX(int*);
    void setY(int*);
    void setR(int*);
    void setG(int*);
    void setB(int*);
};


#endif // CLISTA_H
