#include "block.h"

Block::Block(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene): GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);

    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);

    b2FixtureDef fixturedef;//create a fixture def(4)
    fixturedef.shape = &bodyBox;
    fixturedef.density = BLOCK_DENSITY;
    fixturedef.friction = BLOCK_FRICTION;
    fixturedef.restitution = BLOCK_RESTITUTION;
    //g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    paint();

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}
