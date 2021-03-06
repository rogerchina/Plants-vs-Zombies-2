#ifndef ZOMBIE_H
#define ZOMBIE_H
#pragma once

#include "pvz.h"

#include <QTimer>
#include <QList>

class Zombie : public PvZ
{
public:
    Zombie();
    virtual void onSpawn(myView *rMV) = 0;

    QTimer *eatTimer;

    QList<int>* instanceLife;

    int zombieLife;
    int equipmentLife;
    int attack;
    double rate;
    double speed;
    bool isEating;
    int moveSpeed;
};

#endif // ZOMBIE_H
