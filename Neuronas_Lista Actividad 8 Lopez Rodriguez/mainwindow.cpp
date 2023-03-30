#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "clista.h"
#include<QFileDialog>
#include<QMessageBox>
#include <QStringList>
#include <QtCore/QString>
#include <QColor>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QBrush>
#include <QtGui>
#include<iostream>
#include<fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList Titulos;
    setWindowTitle("Seminario de Algoritmia");
    ui->tableWidget->setColumnCount(7);
    Titulos << "ID" << "Voltaje" << "X" << "Y" << "R" << "G" << "B";
    ui->tableWidget->setHorizontalHeaderLabels(Titulos);

    ui->tableWidget_2->setColumnCount(7);
    Titulos << "ID" << "Voltaje" << "X" << "Y" << "R" << "G" << "B";
    ui->tableWidget_2->setHorizontalHeaderLabels(Titulos);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Clista* neurona = new Clista;

void MainWindow::on_pushButton_clicked()
{
    int ID = 0;
    float Volt = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int v = 0;
    int a = 0;

    QString id = ui->datoN->text();
     ID = id.toInt();
     QString voltaje = ui->datoN_2->text();
     Volt = voltaje.toFloat();
     QString pos_X = ui->datoN_3->text();
     x = pos_X.toInt();
     QString pos_Y = ui->datoN_4->text();
     y = pos_Y.toInt();
     QString rojo = ui->datoN_5->text();
     r = rojo.toInt();
     QString verde = ui->datoN_6->text();
     v = verde.toInt();
     QString azul = ui->datoN_7->text();
     a = azul.toInt();

     neurona->InsertarInicio(ID,Volt,x,y,r,v,a);


}


void MainWindow::on_pushButton_7_clicked()
{

    ui->TextEdit->insertPlainText(neurona->Set());

}


void MainWindow::on_pushButton_2_clicked()
{
    int ID = 0;
    float Volt = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int v = 0;
    int a = 0;

    QString id = ui->datoN->text();
     ID = id.toInt();
     QString voltaje = ui->datoN_2->text();
     Volt = voltaje.toFloat();
     QString pos_X = ui->datoN_3->text();
     x = pos_X.toInt();
     QString pos_Y = ui->datoN_4->text();
     y = pos_Y.toInt();
     QString rojo = ui->datoN_5->text();
     r = rojo.toInt();
     QString verde = ui->datoN_6->text();
     v = verde.toInt();
     QString azul = ui->datoN_7->text();
     a = azul.toInt();


     neurona->InsertarFinal(ID,Volt,x,y,r,v,a);


}


void MainWindow::on_Open_File_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"C:/Users/USER/Documents/UdeG/Seminario de Algoritmia/ACT_4/Neuronas_Lista","All files (*.*);;Text File (*.txt)");

    ui->TextoD->insertPlainText(filename);

   neurona->Save(filename);

}

void MainWindow::on_Open_File_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"C:/Users/USER/Documents/UdeG/Seminario de Algoritmia/ACT_4/Neuronas_Lista","All files (*.*);;Text File (*.txt)");

    ui->TextoD->insertPlainText(filename);

    neurona->Recover(filename);
}


void MainWindow::on_EliminarInicioB_clicked()
{
    neurona->EliminarInicio();
}


void MainWindow::on_EliminarFinalB_clicked()
{
    neurona->EliminarFinal();
}



void MainWindow::on_pushButton_8_clicked()
{
    int fila;
    QString label;
    int ID = 0;
    float Volt = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int g = 0;
    int b = 0;

    fila = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    label = ui->datoN_8->text();

    neurona->BusquedaL(label,ID,Volt,x,y,r,g,b);


    ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(QString::number(ID)));
    ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(QString::number(Volt)));
    ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(QString::number(x)));
    ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(QString::number(y)));
    ui->tableWidget->setItem(fila, 4, new QTableWidgetItem(QString::number(r)));
    ui->tableWidget->setItem(fila, 5, new QTableWidgetItem(QString::number(g)));
    ui->tableWidget->setItem(fila, 6, new QTableWidgetItem(QString::number(b)));

}

void MainWindow::on_pushButton_9_clicked()
{

    int x[20];
    int y[20];
    int r[20];
    int g[20];
    int b[20];
    int a = 255;

    neurona->setX(x);
    neurona->setY(y);
    neurona->setR(r);
    neurona->setG(g);
    neurona->setB(b);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setWindowTitle("Diagrama de neuronas");
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // mejora la calidad visual

    for(int i=0; i<neurona->Tamanio(); i++)
    {
        QColor color(r[i], g[i], b[i], a);
        QGraphicsEllipseItem* punto = new QGraphicsEllipseItem(x[i], y[i], 20, 20);
        punto->setPen(QPen(Qt::black));
        punto->setBrush(QBrush(color));
        scene->addItem(punto);
    }

    ui->graphicsView->setSceneRect(50, 50, 500, 500);
    // Establecer la vista de la escena y su rectángulo
    //ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    //ui->graphicsView->setSceneRect(scene->itemsBoundingRect());
}



void MainWindow::on_pushButton_10_clicked()
{
    int i=0;
    int fila;
    int Orden[50];
    int ID[30];
    float Volt[20];
    int x[20];
    int y[20];
    int r[20];
    int g[20];
    int b[20];
    int primero = 0;
    int ultimo = neurona->Tamanio() -1;

    fila = ui->tableWidget_2->rowCount();

    ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());

    neurona->setID(Orden);

    neurona->Sort(Orden,primero,ultimo);

    neurona->Busqueda(Orden,ID,Volt,x,y,r,g,b);

    while(i<neurona->Tamanio())
    {
    ui->tableWidget_2->insertRow(fila);
    ui->tableWidget_2->setItem(fila, 0, new QTableWidgetItem(QString::number(ID[i])));
    ui->tableWidget_2->setItem(fila, 1, new QTableWidgetItem(QString::number(Volt[i])));
    ui->tableWidget_2->setItem(fila, 2, new QTableWidgetItem(QString::number(x[i])));
    ui->tableWidget_2->setItem(fila, 3, new QTableWidgetItem(QString::number(y[i])));
    ui->tableWidget_2->setItem(fila, 4, new QTableWidgetItem(QString::number(r[i])));
    ui->tableWidget_2->setItem(fila, 5, new QTableWidgetItem(QString::number(g[i])));
    ui->tableWidget_2->setItem(fila, 6, new QTableWidgetItem(QString::number(b[i])));
    i++;
    fila++;
    }


}

/*void MainWindow::on_pushButton_11_clicked()
{

    int id = 0;
    int x[20];
    int y[20];
    float V[20];
    int r[20];
    int g[20];
    int b[20];
    int a = 255;
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsEllipseItem* punto = new QGraphicsEllipseItem(0, 0, 20, 20);

    neurona->setX(x);
    neurona->setY(y);
    neurona->setR(r);
    neurona->setG(g);
    neurona->setB(b);







        for(int i=0;i<=neurona->Tamanio();i++)
        {
        QColor setRgb(r[i], g[i], b[i], a);
        std::cout<<i<<x[i]<<"y "<<i<<y[i]<<std::endl;
        // Establecer la posición del punto en la escena
        punto->setPos(x[i], y[i]);
        scene->addEllipse(x[i], y[i], 15, 10, QPen(Qt::black), QBrush(setRgb));
        // Añadir el punto a la escena
        scene->addItem(punto);
        }
        ui->graphicsView->setSceneRect(50, 50, 500, 500);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setWindowTitle("Diagrama de neuronas");


}*/;


/*void MainWindow::on_pushButton_11_clicked()
{
    int x[20];
    int y[20];
    int r[20];
    int g[20];
    int b[20];
    int a = 255;

    neurona->setX(x);
    neurona->setY(y);
    neurona->setR(r);
    neurona->setG(g);
    neurona->setB(b);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setWindowTitle("Diagrama de neuronas");
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // mejora la calidad visual

    for(int i=0; i<neurona->Tamanio(); i++)
    {
        QColor color(r[i], g[i], b[i], a);
        QGraphicsEllipseItem* punto = new QGraphicsEllipseItem(x[i], y[i], 20, 20);
        punto->setPen(QPen(Qt::black));
        punto->setBrush(QBrush(color));
        scene->addItem(punto);
    }

    ui->graphicsView->setSceneRect(50, 50, 500, 500);
    // Establecer la vista de la escena y su rectángulo
    //ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    //ui->graphicsView->setSceneRect(scene->itemsBoundingRect());
}*/;

void MainWindow::on_pushButton_11_clicked()
{
    int id = 0;
    int x[20];
    int y[20];
    float V[20];
    int r[20];
    int g[20];
    int b[20];
    int a = 255;
    QGraphicsScene* scene = new QGraphicsScene(this);

    neurona->setX(x);
    neurona->setY(y);
    neurona->setR(r);
    neurona->setG(g);
    neurona->setB(b);

    for(int i=0;i<=neurona->Tamanio();i++)
    {
        QColor setRgb(r[i], g[i], b[i], a);
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x[i], y[i], 20, 20);
        ellipse->setBrush(QBrush(setRgb));
        ellipse->setPen(QPen(Qt::black));
        scene->addItem(ellipse);

        // calcular el punto central de la elipse
        QPointF center = ellipse->boundingRect().center();
        QGraphicsEllipseItem* point = new QGraphicsEllipseItem(center.x() - 2, center.y() - 2, 4, 4);
        point->setBrush(QBrush(Qt::black));
        point->setPen(QPen(Qt::black));
        scene->addItem(point);
    }

    ui->graphicsView->setSceneRect(50, 50, 500, 500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setWindowTitle("Diagrama de neuronas");
}

/*
void MainWindow::on_pushButton_12_clicked()
{

    int tam = neurona->Tamanio();
    int posx[20];
    int posX[20];
    int posy[20];
    int id = 0;
    int x[20];
    int x2[20];
    int y[20];
    int y2[20];
    float V[20];
    int r[20];
    int g[20];
    int b[20];
    int a = 255;
    int contL = 0;
    int primero = 0;
    int ultimo = neurona->Tamanio() -1;
    QGraphicsScene* scene = new QGraphicsScene(this);

    neurona->setX(x);
    neurona->setY(y);
    neurona->setY(y2);
    neurona->setX(x2);
    neurona->setR(r);
    neurona->setG(g);
    neurona->setB(b);

    neurona->ordenarCoordenadas(x,x2,y,y2,posx,posy,tam);

     std::cout << "Fuerza Bruta: " << std::endl;

        // Imprimir los arreglos ordenados
        std::cout << "Coordenadas ordenadas: " << std::endl;
        for (int i = 0; i < tam; i++)
        {
            std::cout << "(" << posx[i] << ", " << posy[i] << ")" << std::endl;
            std::cout << "(" << x[i] << ", " << y[i] << ")" << std::endl;
            std::cout<<"Pareja: "<<std::endl;
        }

    for(int i=0;i<=neurona->Tamanio();i++)
    {
        QColor setRgb(r[i], g[i], b[i], a);
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x[i], y[i], 20, 20);
        ellipse->setBrush(QBrush(setRgb));
        ellipse->setPen(QPen(Qt::black));
        scene->addItem(ellipse);
        // calcular el punto central de la elipse
        QPointF center = ellipse->boundingRect().center();
        QGraphicsEllipseItem* point = new QGraphicsEllipseItem(center.x() - 2, center.y() - 2, 4, 4);
        point->setBrush(QBrush(Qt::black));
        point->setPen(QPen(Qt::black));
        QPen pen(Qt::blue);

        //scene->addLine(55,444,222,111, pen);

        scene->addLine(x[i]-2,y[i]-2,posx[i],posy[i], pen);



        scene->addItem(point);
    }

    ui->graphicsView->setSceneRect(50, 50, 500, 500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setWindowTitle("Diagrama de neuronas");

}*/;


void MainWindow::on_pushButton_12_clicked()
{
    int tam = neurona->Tamanio();
    int posx[20];
    int posX[20];
    int posy[20];
    int id = 0;
    int x[20];
    int x2[20];
    int y[20];
    int y2[20];
    float V[20];
    int r[20];
    int g[20];
    int b[20];
    int a = 255;
    int contL = 0;
    int primero = 0;
    int ultimo = neurona->Tamanio() -1;
    QGraphicsScene* scene = new QGraphicsScene(this);

    neurona->setX(x);
    neurona->setY(y);
    neurona->setY(y2);
    neurona->setX(x2);
    neurona->setR(r);
    neurona->setG(g);
    neurona->setB(b);

    neurona->ordenarCoordenadas(x,x2,y,y2,posx,posy,tam);

    std::cout << "Fuerza Bruta: " << std::endl;

    // Imprimir los arreglos ordenados
    std::cout << "Coordenadas ordenadas: " << std::endl;
    for (int i = 0; i < tam; i++)
    {
        std::cout << "(" << posx[i] << ", " << posy[i] << ")" << std::endl;
        std::cout << "(" << x[i] << ", " << y[i] << ")" << std::endl;
        std::cout<<"Pareja: "<<std::endl;
    }

    for(int i = 0; i < neurona->Tamanio(); i++)
    {
        QColor setRgb(r[i], g[i], b[i], a);
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x2[i], y2[i], 20, 20);
        ellipse->setBrush(QBrush(setRgb));
        ellipse->setPen(QPen(Qt::black));
        scene->addItem(ellipse);

        // calcular el punto central de la elipse
        QPointF center = ellipse->boundingRect().center();
        QGraphicsEllipseItem* point = new QGraphicsEllipseItem(center.x() - 2, center.y() - 2, 4, 4);
        point->setBrush(QBrush(Qt::black));
        point->setPen(QPen(Qt::black));
        scene->addItem(point);

        if(i > 0) // dibujar la línea a la neurona anterior
        {
            QGraphicsEllipseItem* prevEllipse = dynamic_cast<QGraphicsEllipseItem*>(scene->items()[i-1]);
            //QPointF prevCenter = prevEllipse->boundingRect().center();
            QPointF prev(posx[i],posy[i]);
            QPen pen(Qt::blue);
            //scene->addLine(center.x(), center.y(), posx[i],posy[i], pen);
            scene->addLine(center.x()-2, center.y()-2, prev.x()+4,prev.y()+4, pen);

        }
    }

    ui->graphicsView->setSceneRect(50, 50, 500, 500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setWindowTitle("Diagrama de neuronas");
}






















