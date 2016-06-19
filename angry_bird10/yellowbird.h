#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define YELLOWBIRD_DENSITY 10.0f
#define YELLOWBIRD_FRICTION 0.2f
#define YELLOWBIRD_RESTITUTION 0.5f

class yellowBird : public GameItem
{
public:
    yellowBird(float x, float y, float radius,QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    virtual void birdFunction();
};

#endif // YELLOWBIRD_H
