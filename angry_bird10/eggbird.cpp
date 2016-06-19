#include "eggbird.h"


eggBird::eggBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    // Create Body(4 steps)
    b2BodyDef bodydef;//create a body
    bodydef.type = b2_dynamicBody;//set the body type to b2_dynamicBody(1)
    bodydef.bullet = true;//?
    bodydef.position.Set(x,y);//set the starting position
    bodydef.userData = this;//?
    g_body = world->CreateBody(&bodydef);//pass body definition to the world pointer(2)

    b2CircleShape bodyshape;//create a circle(3)
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;//create a fixture def(4)
    fixturedef.shape = &bodyshape;
    fixturedef.density = EGGBIRD_DENSITY;
    fixturedef.friction = EGGBIRD_FRICTION;
    fixturedef.restitution = EGGBIRD_RESTITUTION;
    g_body->SetAngularDamping(3);//?
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void eggBird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

b2Vec2 eggBird::getPosition()
{
    return g_body->GetPosition();
}

void eggBird::birdFunction()
{
    this->setLinearVelocity(b2Vec2(0,-30));
}
