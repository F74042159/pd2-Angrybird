#ifndef ENEMY_H
#define ENEMY_H

#include <gameitem.h>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QObject>

#define ENEMY_DENSITY 10.0f
#define ENEMY_FRICTION 0.2f
#define ENEMY_RESTITUTION 0.5f

class Enemy : public GameItem
{
    Q_OBJECT

public:
    Enemy(float x, float y,float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    int eliminate;//可以在這裡初始化?
public slots:
    void detectPig();

};

#endif // ENEMY_H
