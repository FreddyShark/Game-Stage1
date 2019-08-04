#pragma once

#include "ui_dialog.h"
#include "stickman.h"
#include "abstractgamegui.h"
#include "guiglobals.h"

/*
 * Concrete implementation of base class AbstractGameGui, dedicated as a ui for game play.
 * It is the parent of all over GUIs and requested characters.
 */

namespace Ui
{

class Dialog;

}

namespace game1
{

class GamePlayingGui : public AbstractGameGui
{
    Q_OBJECT
    friend class EventHandler;

public:
    // Constrcutors and destructors.
    GamePlayingGui(EventHandler& handler);
    virtual ~GamePlayingGui() override;

    const EventHandler& handler;

    QString level = "zero";
    QString speed = "1x";
    bool showSplash = true;
    QImage levelIMG = QImage();
    QTimer& timer = *new QTimer(this);
    Stickman* character;

    void setCharacter(AbstractCharacter* character, QString type);

    void buildGui() override;

    void runGame(QPainter& painter);

protected:
    // Inherited from Superbase QDialog.
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::Dialog* ui;
    int* counter = new int;

    void keyPressEvent(QKeyEvent* event) override;

signals:
    void pause();

private slots:
    void nextFrame();
};

}   // Project namespace.
