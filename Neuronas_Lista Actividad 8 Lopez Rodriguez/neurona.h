#ifndef NEURONA_H
#define NEURONA_H
#include "neurona.h"
#include <QString>

class Neurona
{
private:
    Neurona* pAnt = nullptr;
    Neurona* pSig = nullptr;
    int Id = 0;
    float Voltaje = 0;
    int Pos_x = 0;
    int Pos_y = 0;
    int Red = 0;
    int Green = 0;
    int Blue = 0;
    int cont = 0;
    friend class Clista;
public:
    void InsertarAdelantefloat(int,float,int,int,int,int,int);
    float EliminarSiguiente();
    QString Set();
    void BusquedaL(QString,int&,float&,int&,int&,int&,int&,int&);
    void setID(int&);
    void setV(float&);
    void setX(int&)const;
    void setY(int&)const;
    void setR(int&);
    void setG(int&);
    void setB(int&);
};




#endif // NEURONA_H
