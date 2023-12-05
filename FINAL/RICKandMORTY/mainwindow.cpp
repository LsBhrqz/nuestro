#include "mainwindow.h"

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
    hepatitisB = new personaje();
    hepatitisB->constructor(775.0, 400.0, 0.0, 0.0, false, 405.0, 350.0, 1280.0, 722.0);
    hepatitisB->setPos(hepatitisB->xIn, hepatitisB->yIn);
    scene->addItem(hepatitisB);


    QTimer * cronometro = new QTimer(this);
    connect(cronometro, &QTimer::timeout, [=](){
        if(hepatitisB->cara == 0){
            hepatitisB->setPixmap(QPixmap(":/img/hepatitisb1.png"));
        }else if (hepatitisB->cara == 1){
            hepatitisB->setPixmap(QPixmap(":/img/hepatitisb2.png"));
        }else{
            hepatitisB->setPixmap(QPixmap(":/img/hepatitisb3.png"));
            arma* bola = new arma;
            bola->ubicarMorty(300,700, 890, 460);//aquí va el morty->posiciones en equiz y lle, en los dos primeros parámetros
            bola->constructor(890, 460, bola->angTiro, 20, false, 30, 30, 1280, 722);

            yoeralabola();
            disparar(bola);
}
        hepatitisB->cambiarCara();
    });
    cronometro->start(500);
}

void MainWindow::yoeralabola(){
    particle = new QGraphicsEllipseItem(0, 0, 30, 30);
    particle->setBrush(Qt::yellow);
    particle->setPos(750,400);
    scene->addItem(particle);
    particle->show();

}
void MainWindow::disparar(arma *bola){

    tiempoTiro = new QTimer(this);
    connect(tiempoTiro, &QTimer::timeout, [=](){

        bola->jump();
        bola->impacto();

        if(bola->movimiento){

            tiempoTiro->stop();
            particle->hide();

        }
        else{
            particle->setPos(bola->coordX, bola->coordY);
            bola->tiempo +=0.5;
        }
    });

    tiempoTiro->start(10);
}

void MainWindow::on_Nivel2_Clicked()
{
    //scene->setBackgroundBrush(QPixmap(":/img/fondotuberculosis.jpg").scaled(ancho_pantalla, alto_pantalla));
    nivel1->hide();
    nivel2->hide();
}

MainWindow::~MainWindow()
{
    delete scene;
    scene = nullptr;
    delete ui;
    delete JUGAR;
    delete nivel1;
    delete nivel2;
    delete hepatitisB;
    delete tiempoTiro;
    delete particle;
}
