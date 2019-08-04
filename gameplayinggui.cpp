#include "gameplayinggui.h"

using namespace game1;

GamePlayingGui::GamePlayingGui(game1::EventHandler& handler) :
    AbstractGameGui(),
    handler(handler),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, WIN_W, WIN_H);
    this->setFixedSize(WIN_W, WIN_H);
    // Blue splash screen.
    this->setStyleSheet("background-color: #00F;");
    this->show();
}

GamePlayingGui::~GamePlayingGui()
{
    delete &timer;
    delete counter;
    delete ui;
}

// Inhertied from Qdialog to draw scene.
void GamePlayingGui::paintEvent(QPaintEvent *event)
{
    QPainter& myPainter = *new QPainter;

    if (!showSplash)
    {
        character->setParent(this);
        character->move(character->getxStartPosition(), WIN_H/2);
        character->createCharacter(myPainter);

        myPainter.begin(this);
        runGame(myPainter);

        character->show();
    }
}

// Private slot.
void GamePlayingGui::nextFrame() { this->update(); }

// Factory method.
void GamePlayingGui::buildGui()
{
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();

    // Connect pause event to event handler.
    QObject::connect(this, SIGNAL(pause()),
                     (const QObject*)&handler, SLOT(onGamePlayPause()));

    // Connect timer to own slot.
    connect(&timer, SIGNAL(timeout()), this, SLOT(nextFrame()), Qt::UniqueConnection);
    timer.start(15);
    *counter = 0;

    // Set level.
    if (level == "zero") { levelIMG = QImage("://resources/Images/IMGlevel0.jpg"); }

    else if (level == "one") { levelIMG = QImage("://resources/Images/IMGlevel1.jpg"); }

    else if (level == "two") { levelIMG = QImage("://resources/Images/IMGlevel2.jpg"); }

    else throw "Level does not exist.";

    showSplash = false;
    character->show();
}

// Inhertied from QDialog and used to respond to <p> press for pause.
void GamePlayingGui::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_P)
    {
        this->setStyleSheet("background-color: #00F;");
        showSplash = true;
        character->hide();
        emit pause();
    }
}

// method called in paintEvent to paint dynamic scene.
void GamePlayingGui::runGame(QPainter& painter)
{
    if ( *counter >= WIN_W ) { *counter = 0; }
    QImage scaledIMG = levelIMG.copy(0, 0, levelIMG.width(), levelIMG.height()).scaled(WIN_W, WIN_H, Qt::IgnoreAspectRatio);
    QRect frameAsource;
    QRect frameAtarget;
    QRect frameBsource;
    QRect frameBtarget;
    // Left edge source.
    frameAsource.setRect(0, 0, *counter, WIN_H);
    // Right edge target.
    frameAtarget.setRect(WIN_W-(*counter), 0, *counter, WIN_H);
    // Middle source.
    frameBsource.setRect(*counter, 0, WIN_W-(*counter), WIN_H);
    // left edge target.
    frameBtarget.setRect(0, 0, WIN_W-(*counter), WIN_H);

    painter.drawImage(frameAtarget, scaledIMG, frameAsource);
    painter.drawImage(frameBtarget, scaledIMG, frameBsource);

    // Increase in counter relative to user selection of speed.
    (*counter)+= 2*speed.mid(0,1).toInt();
}

void GamePlayingGui::setCharacter(AbstractCharacter *character, QString type)
{
    if (type == "stickman")
    {
        this->character = new Stickman(dynamic_cast<Stickman*>(character));
    }
}
