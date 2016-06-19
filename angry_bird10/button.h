#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QObject>

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    //constructors
    Button(QString name, QGraphicsItem* parent=NULL);

    //public member function
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;

};

#endif // BUTTON_H

