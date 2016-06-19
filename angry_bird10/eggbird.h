#ifndef EGGBIRD_H
#define EGGBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define EGGBIRD_DENSITY 10.0f
#define EGGBIRD_FRICTION 0.2f
#define EGGBIRD_RESTITUTION 0.5f

class eggBird : public GameItem
{
public:
    eggBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    b2Vec2 getPosition();
    virtual void birdFunction();
};

#endif // EGGBIRD_H
