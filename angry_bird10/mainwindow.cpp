#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    //Setting the background
    ui->graphicsView->setObjectName("background");
    ui->graphicsView->setStyleSheet("#background{border-image:url(:/image/background.png);}");
    start();

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}
void MainWindow::start(){
    //play music
    backmusic = new QMediaPlayer();
    backmusic->setMedia(QUrl("qrc:/sound/sound/background.mp3"));
    backmusic->play();
    //initialize
    birdtype=1;

    // Create ground (You can edit here)
    itemList.push_back(land=new Land(16,1.0,32,3,QPixmap().scaled(width(),height()/6),world,scene));

    //Create slingshot
    slingshot = new SlingShot();
    scene->addItem(slingshot);

    //Create enemy
    pig1 = new Enemy(23.5f,5.0f,1.0f,&timer,QPixmap(":/image/pig.png").scaled(60,60),world,scene);
    pig2 = new Enemy(23.5f,10.0f,1.0f,&timer,QPixmap(":/image/pig.png").scaled(60,60),world,scene);
    pig3 = new Enemy(23.5f,14.0f,1.0f,&timer,QPixmap(":/image/pig.png").scaled(60,60),world,scene);

    //Create block
    block1 = new Block(21.5f,6.0f,1.0f,4.0f,&timer,QPixmap(":/image/block_short_col.png").scaled(30,120),world,scene);
    block2 = new Block(26.0f,6.0f,1.0f,4.0f,&timer,QPixmap(":/image/block_short_col.png").scaled(30,120),world,scene);
    block3 = new Block(23.8f,8.0f,6.0f,1.0f,&timer,QPixmap(":/image/block_long_row.png").scaled(180,30),world,scene);
    block4 = new Block(22.5f,10.0f,1.0f,4.0f,&timer,QPixmap(":/image/block_short_col.png").scaled(30,120),world,scene);
    block5 = new Block(25.5f,10.0f,1.0f,4.0f,&timer,QPixmap(":/image/block_short_col.png").scaled(30,120),world,scene);
    block6 = new Block(23.8f,12.0f,4.0f,1.0f,&timer,QPixmap(":/image/block_short_row.png").scaled(120,30),world,scene);

    itemList.push_back(pig1);
    itemList.push_back(pig2);
    itemList.push_back(pig3);
    itemList.push_back(block1);
    itemList.push_back(block2);
    itemList.push_back(block3);
    itemList.push_back(block4);
    itemList.push_back(block5);
    itemList.push_back(block6);

}

int MainWindow::birdtype=1;

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(birdtype==1){
            eggbirdie = new eggBird(4.0f,7.0f,1.0f,&timer,QPixmap(":/image/eggBird.png").scaled(60,60),world,scene);
            ++birdtype;
            return true;
        }
        if(birdtype==2){
            bluebirdie = new blueBird(4.0f,7.0f,1.0f,&timer,QPixmap(":/image/blueBird.png").scaled(60,60),world,scene);
            ++birdtype;
            return true;
        }
        if(birdtype==3){
            yellowbirdie = new yellowBird(4.0f,7.0f,1.0f,&timer,QPixmap(":/image/yellowBird.png").scaled(60,60),world,scene);
            ++birdtype;
            return true;
        }
        if(birdtype==4){
            birdie = new Bird(4.0f,7.0f,1.0f,&timer,QPixmap(":/bird.png").scaled(60,60),world,scene);
            ++birdtype;
            return true;
        }
        //std::cout << "Press !" << std::endl ;
        return false;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        if(birdtype==2){
            eggbirdie->setLinearVelocity(b2Vec2(10,15));
            itemList.push_back(eggbirdie);
            //play music
            QMediaPlayer*music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sound/sound/bird.mp3"));
            music->play();
            return true;
        }
        if(birdtype==3){
            bluebirdie->setLinearVelocity(b2Vec2(10,10));
            itemList.push_back(bluebirdie);
            //play music
            QMediaPlayer*music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sound/sound/bird.mp3"));
            music->play();
            return true;
        }
        if(birdtype==4){
            yellowbirdie->setLinearVelocity(b2Vec2(10,10));
            itemList.push_back(yellowbirdie);
            //play music
            QMediaPlayer*music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sound/sound/bird.mp3"));
            music->play();
            return true;
        }
        if(birdtype==5){
            birdie->setLinearVelocity(b2Vec2(10,10));
            itemList.push_back(birdie);
            //play music
            QMediaPlayer*music = new QMediaPlayer();
            music->setMedia(QUrl("qrc:/sound/sound/bird.mp3"));
            music->play();

            birdtype=0;
            displayGameOverWindow();
            return true;
        }
        //std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //std::cout<<"press"<<std::endl;
    if(event->key() == Qt::Key_Space){
        if(birdtype==2){
            egg = new eggBird(eggbirdie->getPosition().x,eggbirdie->getPosition().y,1.0f,&timer,QPixmap(":/image/egg.png").scaled(60,60),world,scene);
            egg->birdFunction();
            itemList.push_back(egg);
        }
        if(birdtype==3)
        {
            bluebirdie_1 = new blueBird(bluebirdie->getPosition().x,bluebirdie->getPosition().y,1.0f,&timer,QPixmap(":/image/blueBird.png").scaled(60,60),world,scene);
            bluebirdie_2 = new blueBird(bluebirdie->getPosition().x,bluebirdie->getPosition().y,1.0f,&timer,QPixmap(":/image/blueBird.png").scaled(60,60),world,scene);
            bluebirdie_3 = new blueBird(bluebirdie->getPosition().x,bluebirdie->getPosition().y,1.0f,&timer,QPixmap(":/image/blueBird.png").scaled(60,60),world,scene);

            bluebirdie_1->setLinearVelocity(b2Vec2(20,5));
            bluebirdie_2->setLinearVelocity(b2Vec2(20,0));
            bluebirdie_3->setLinearVelocity(b2Vec2(20,-5));

            itemList.push_back(bluebirdie_1);
            itemList.push_back(bluebirdie_2);
            itemList.push_back(bluebirdie_3);

            bluebirdie->birdFunction();
        }
        if(birdtype==4)yellowbirdie->birdFunction();
    }

}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::displayGameOverWindow(){

    //pop up semi transparent panel
    drawPanel(0,0,1000,600,Qt::black,0.5);
    //draw panel
    drawPanel(300,100,300,300,Qt::lightGray,1.0);

    //create playAgain button
    Button* playAgain2 = new Button(QString("restart"));
    playAgain2->setPos(350,175);
    scene->addItem(playAgain2);
    connect(playAgain2,SIGNAL(clicked()),this,SLOT(restartGame()));

    //create exit button
    Button* exit = new Button(QString("quit"));
    exit->setPos(350,275);
    scene->addItem(exit);
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}

void MainWindow::drawPanel(int x, int y, int width,int height, QColor color, double opacity)
{
    //draw a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void MainWindow::restartGame()
{
    //stop backmusic
    backmusic->stop();

    for(int i=0;i<itemList.size();i++)
    {
        delete itemList[i];
    }
    delete slingshot;
    itemList.clear();
    scene->clear();
    start();
}
