#include "ref.h"

Bullet::Bullet(myView *rMV)
{
    gametype = 'B';
    name = "Bullet";

    speed = 5;

    mV = rMV;
    //Load sun image, and make it WxW
    setPixmap(QPixmap(":/Plants/Bullet.PNG").scaled(W,W));

}

void Bullet::advance(int phase)
{
    if(!phase) return;

TOP:    for(int i =0; i < instances->size(); i++)
    {
        //If the bullet goes off the screen, destroy it.
        if(instances->at(i)->pos().x() + pixmap().width() >= mV->WIDTH){
            delete instances->at(i);
            instances->removeAt(i--);
            continue;
        }

        //Move the bullet across the screen at its speed
        instances->at(i)->setX(instances->at(i)->x() + speed);
        //For each of the zombies in the bullets row...
        for(int j = 0; j < mV->zombieGridList->at(instances->at(i)->data(PvZ::rowIndex).toInt())->size(); j++)
        {
            if(mV->zombieGridList->at(instances->at(i)->data(PvZ::rowIndex).toInt())->at(j)->data(PvZ::instanceLife) == -1) continue;
            //If the bullet hits one of them
            //CRASHES HERE AFTER A ZOMBIE DIES!!.
            if(instances->at(i)->collidesWithItem(mV->zombieGridList->at(instances->at(i)->data(PvZ::rowIndex).toInt())->at(j)))
            {
                //Save the plant Object and instance that shot this bullet.
                int plantObject = instances->at(i)->data(PvZ::plantType).toInt();
                int plantInstance = instances->at(i)->data(PvZ::instanceIndex).toInt();

                int zombieInstance = mV->zombieGridList->at(instances->at(i)->data(PvZ::rowIndex).toInt())->at(j)->data(PvZ::instanceIndex).toInt();
                mV->damageZombie(mV->zombieGridList->at(instances->at(i)->data(PvZ::rowIndex).toInt())->at(j)->data(PvZ::zombieType).toInt() , zombieInstance , plantObject, plantInstance, instances->at(i)->data(PvZ::damage).toInt());
                //Delete the bullet.
                delete instances->at(i);
                instances->removeAt(i--);
                goto TOP;
            }
        }
    }
}
