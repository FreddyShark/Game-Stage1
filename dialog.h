#pragma once

#include <QDialog>
#include <QTimer>
#include <QKeyEvent>
#include "guiglobals.h"
#include "stickman.h"
#include "characterfactory.h"


namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QRect frameA = *new QRect;
    QRect frameB = *new QRect;
    QBrush brush = *new QBrush;
    QPen pen = *new QPen;
    QImage levelIMG = *new QImage;
    QTimer& timer = *new QTimer(this);
    game1::AbstractCharacter* character;

    void BuildGui(QPainter& painter);
    void runGame();

protected:
    void paintEvent(QPaintEvent *event);


private:
    Ui::Dialog* ui;
    int* counter = new int;

    void pausePressed(QKeyEvent* event);

signals:
    void pause();

private slots:
    void nextFrame();
};

