#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include "NIVEL1.h"
#include "morty.h"
#include "personaje.h"
#include "arma.h"

int ancho_pantalla= 1280;
int alto_pantalla=722;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene),
    JUGAR(nullptr),
    nivel1(nullptr),
    nivel2(nullptr)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, ancho_pantalla, alto_pantalla);
    setFixedSize(ancho_pantalla+20, alto_pantalla+20);


    ui->graphicsView->resize(ancho_pantalla, alto_pantalla);
    //ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    //ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/img/presentacion.png").scaled(ancho_pantalla, alto_pantalla));


    JUGAR = new QPushButton(QIcon(":/img/logo.png"), " JUGAR", ui->centralwidget);

    // Establecer la posición y el tamaño del botón en el widget
    JUGAR->setGeometry(1055, 645, 150, 50);

    JUGAR->setStyleSheet("QPushButton { background-color: red; border: 2px solid darkred; border-radius: 5px; padding: 5px; color: white; font-size: 16px; } QPushButton:hover { background-color: darkred; }");

    // Conectar la señal clicked() del botón a una función
    connect(JUGAR, &QPushButton::clicked, this, &MainWindow::on_JUGAR_Clicked);


    nivel1 = new QPushButton("NIVEL 1", ui->centralwidget);
    nivel1->setObjectName("nivel1");
    nivel1->hide();

    // Establecer la posición y el tamaño del botón en el widget
    nivel1->setGeometry(100, 100, 350, 194);

    nivel1->setStyleSheet("QPushButton { background-image: url(:/img/nivel1.png); background-color: red; border: 2px solid darkred; border-radius: 5px; padding: 5px; color: white; font-size: 40px; } QPushButton:hover { background-color: darkred; }");

    // Conectar la señal clicked() del botón a una función
    connect(nivel1, &QPushButton::clicked, this, &MainWindow::on_Nivel1_Clicked);

    nivel2 = new QPushButton("NIVEL 2", ui->centralwidget);
    nivel2->setObjectName("nivel2");
    nivel2->hide();

    // Establecer la posición y el tamaño del botón en el widget
    nivel2->setGeometry(900, 100, 350, 194);

    nivel2->setStyleSheet("QPushButton { background-image: url(:/img/nivel2.jpg); background-color: blue; border: 2px solid darkblue; border-radius: 5px; padding: 5px; color: white; font-size: 40px; } QPushButton:hover { background-color: darkblue; }");

    // Conectar la señal clicked() del botón a una función
    connect(nivel2, &QPushButton::clicked, this, &MainWindow::on_Nivel2_Clicked);
}

MainWindow::~MainWindow()
{
    delete scene;
    scene = nullptr;
    delete ui;
    delete JUGAR;
    delete nivel1;
    delete nivel2;
}


void MainWindow::on_JUGAR_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondoniveles.jpg").scaled(ancho_pantalla, alto_pantalla));
    JUGAR->hide();
    nivel1->show();
    nivel2->show();
}

void MainWindow::on_Nivel1_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondohepatitisB.png").scaled(ancho_pantalla, alto_pantalla));
    nivel1->hide();
    nivel2->hide();

    personaje* hepatitisB = new personaje();
    string cara1 = ":/img/hepatitisb1.png";
    string cara2 = ":/img/hepatitisb2.png";
    string cara3 = ":/img/hepatitisb3.png";
    hepatitisB->constructor(775.0, 400.0, 0.0, 0.0, false, 405.0, 350.0, 1280.0, 722.0);
    hepatitisB->setPixmap(QPixmap(":/img/hepatitisb1.png"));
    //hepatitisB->caras[1] = cara1; hepatitisB->caras[2] = cara2; hepatitisB->caras[3] = cara3;
    hepatitisB->setPos(hepatitisB->xIn, hepatitisB->yIn);
    scene->addItem(hepatitisB);
    //int vidaMorty = morty.getVida();
    while(true){
        int vidaHepa = hepatitisB->getSalud();
        while(vidaHepa >= 0){
            double ang = hepatitisB->angAleatorio();
            QTimer * cronometro = new QTimer(this);
            connect(cronometro, &QTimer::timeout, [&](){
                arma bola;
                // Crear la partícula y dibujarla
                QGraphicsEllipseItem particle(0, 0, 20, 20);
                particle.setBrush(Qt::yellow);
                scene->addItem(&particle);
                QTimer * timerBola = new QTimer(this);
                connect(cronometro, &QTimer::timeout, [&](){
                    bool boot = true;
                    bola.constructor(775.0, 400.0, ang, 50, false, 20, 20, 1280, 722);
                    bola.jump();
                    bola.collide(boot);
                    particle.setPos(bola.coordX, bola.coordY);
                });
                timerBola->start(10);
            });
            cronometro->start(3000);

            break;
        }
        break;
    }

}

void MainWindow::on_Nivel2_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondotuberculosis.jpg").scaled(ancho_pantalla, alto_pantalla));
    nivel1->hide();
    nivel2->hide();
}
