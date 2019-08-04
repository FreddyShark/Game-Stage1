#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    character =  dynamic_cast<game1::AbstractCharacter*>
                (game1::CharacterFactory::getCharacter(game1::AbstractCharacter::kStickman));

    character->hide();
    ui->setupUi(this);
    this->setGeometry(0, 0, WIN_W, WIN_H);
    this->setStyleSheet("background-color: #00F;");
    this->show();
}

Dialog::~Dialog() { delete ui; }

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter& painter = *new QPainter;

    character->hide();

    character->setParent(this);
    character->move(character->getxStartPosition(), WIN_H/2);
    character->createCharacter(painter);

    painter.begin(this);
    BuildGui(painter);

    character->show();

}

void Dialog::nextFrame()
{
    this->update();
}

void Dialog::runGame()
{
    this->update();
    character->show();
    connect(&timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer.start(25);
    *counter = 0;
}

void Dialog::pausePressed(QKeyEvent* event)
{
    if (event->key() == Qt::Key_P)  { emit pause(); }
}

void Dialog::BuildGui(QPainter& painter)
{
    levelIMG = QImage("://resources/Images/IMGlevel0.jpg");
    brush.setTextureImage(levelIMG.scaled(Qt::KeepAspectRatioByExpanding,
                                          Qt::FastTransformation));

    if ( *counter >= WIN_W ) { *counter = 0; }
    frameA.setRect(0, 0, WIN_W, WIN_H);
    frameB.setRect(WIN_W-1, 0, WIN_W, WIN_H);
    painter.translate(-(*counter), 0);
    painter.drawImage(frameA, levelIMG);
    painter.drawImage(frameB, levelIMG);
    (*counter)++;
///*
//    // Connect pause event to event handler
//    QObject::connect(this, SIGNAL(pause()),
//                     (const QObject*)&handler, SLOT(onGameplayPause(*/)));
}
