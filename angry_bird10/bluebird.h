#ifndef BLUEBIRD_H
#define BLUEBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BLUEBIRD_DENSITY 8.0f
#define BLUEBIRD_FRICTION 0.2f
#define BLUEBIRD_RESTITUTION 0.5f

class blueBird : public GameItem
{
public:
    blueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    b2Vec2 getPosition();
    virtual void birdFunction();
};

#endif // BLUEBIRD_H
