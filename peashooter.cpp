#include "ref.h"

Peashooter::Peashooter(myView *rMV)
{
    //Set up the peashooter stats.
    this->cost = 100;
    this->life = 4;
    this->range = 9999;
    this->damage = 1;
    this->rate = 1.5;
    this->seeding = 7.5;
    this->slow = false;
    mV = rMV;
    rateTimer = new QTimer(mV);
    inRange = false;

    name = "Peashooter";
    setPixmap(QPixmap(":/Plants/PeaShooter.gif"));
}

QString Peashooter::getImagePath()
{
    return ":/Plants/PeaShooter.gif";
}

void Peashooter::onPlant()
{

    //rangeRect = new QRectF(this->getPlantLocation().x() * mV->gameBlockHeight,this->getPlantLocation().y()* mV->gameBlockWidth,100,100);
    //rangeRect = new QRectF(mV->grid[(this->getPlantLocation().x())][this->getPlantLocation().y()]);
    //rangeRect = new QRectF(mV->grid[(int)this->plantLocation.x()][(int)this->plantLocation.y()]);
    //rangeRect->setRight(mV->WIDTH);
    //mV->scene->addRect(*rangeRect);
    //qDebug() << "Width : " << rangeRect->width() << endl;
    //qDebug() << "X : " << this->getPlantLocation().x() << " Y : " << this->getPlantLocation().y() << " Range : " << this->range <<  " Height : " << mV->gameBlockHeight << endl;
    //    mV->connect(rateTimer, SIGNAL(timeout()), mV->mapper, SLOT(map()));
    //    mV->mapper->setMapping(rateTimer,);
    //    mV->connect(mapper,SIGNAL(mapped(Plant*)),mV,SLOT(checkZombie(Plant*)));
    //    rateTimer->start(this->getRate() * 10000);
}

void Peashooter::advance(int phase)
{
    if(!phase) return;

    if(inRange){
        return;
    }

    for (int i = 0; i < ((myView*)mV)->scene->items().size(); i++){
        if((rangeRect->contains(mV->scene->items().at(i)->pos()) && ((PvZ*)mV->scene->items().at(i))->gametype == 'Z')){
            qDebug() << "Enemy in range" << endl;
            inRange = true;
        }
    }
}
