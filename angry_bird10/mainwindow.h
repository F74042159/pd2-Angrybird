#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QKeyEvent>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <bluebird.h>
#include <yellowbird.h>
#include <eggbird.h>
#include <slingshot.h>
#include <enemy.h>
#include <block.h>
#include <button.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void start();
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void displayGameOverWindow();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void keyPressEvent(QKeyEvent *event);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void restartGame();
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    static int birdtype;
    Land *land;
    Bird *birdie;
    blueBird *bluebirdie;
    blueBird *bluebirdie_1;
    blueBird *bluebirdie_2;
    blueBird *bluebirdie_3;
    yellowBird *yellowbirdie;
    eggBird *eggbirdie;
    eggBird *egg;
    Enemy *pig1;
    Enemy *pig2;
    Enemy *pig3;
    Block *block1;
    Block *block2;
    Block *block3;
    Block *block4;
    Block *block5;
    Block *block6;
    SlingShot*slingshot;
    QMediaPlayer*backmusic;
};

#endif // MAINWINDOW_H
