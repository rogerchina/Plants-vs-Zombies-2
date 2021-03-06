#pragma once
#ifndef MYVIEW_H
#define MYVIEW_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QRect>
#include <QSignalMapper>
#include <QPushButton>
#include <QMouseEvent>

#include "maingame.h"
#include "mainwindow.h"

class QMouseEvent;
class mainGame;
class Sun;
class Bullet;
class Grass;
class Dirt;
class Zombie;
class Regular;
class QGraphicsScene;
class Plant;
class Lawnmower;
class myView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit myView(QWidget *parent = 0,mainGame *rMG = 0);

    //List for Plant Parent Classes
    QList <Plant*> *plantObj;
    void levelLost();

    //Lists for Zombies
    QList <Zombie*> *zombieObj; //Holds the "parent" class

     //Holds references to the children being drawn
    //Level Params ?


    int maxZombies; // Holds the max number of zombies for this level.
    int currentZombies; // Holds the number of zombies spawned so far.
    int zombieSequenceIndex;

    //Initilize Suns.
    Sun *sun;
    //Initilize bullets.
    Bullet *bullet;
    //Initilize lawnmowers
    Lawnmower *lawnmower;

    mainGame *mG; // mainGame forward declaration.
    QGraphicsScene *scene; // The graphics scene.

    enum {ROWS = 5, COLUMNS = 10};

    QRectF grid[ROWS][COLUMNS];
    QGraphicsPixmapItem *plantGrid [ROWS][COLUMNS];

    Grass *grass;
    Dirt *dirt;

    QSignalMapper* mapper; //For mapping signals -> let's us pass values to slots
    QSignalMapper* zombieMapper; //For mapping signals -> let's us pass values to slots
    //Variables to control the height and width of each grid block.
    int WIDTH, HEIGHT;
    int gameBlockHeight, gameBlockWidth;

    //Random number generator.
    int random(int x1, int x2);

    void zombieEat(int,int); // Called when the zombie eats plant brains.
    void plantShoot(int,int,bool);
    void damageZombie(int zombieObject,int zombieInstance, int zombieGridInstance, int damage, bool slow);
    void destroyPlant(int row, int column);


    QTimer *moveTimer;
    QTimer *sunTimer;
    QTimer *zombieSpawnTimer;
public slots:
    void sunSpawn(QObject*);
    void sunflowerSun();
    void zombieSpawner();
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // MYVIEW_H
