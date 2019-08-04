#include "stickman.h"

using namespace game1;

Stickman::Stickman(int xStartPostion,  size characterSize, colour characterColour)
    : AbstractCharacter(xStartPostion, characterSize),
      characterColour(colour(characterColour)) { }

Stickman::Stickman(Stickman* toCopy)
    : AbstractCharacter(toCopy->xStartPosition, toCopy->characterSize),
      characterColour(toCopy->characterColour) {  }

Stickman::colour Stickman::getColour() { return characterColour; }

int Stickman::getStartPosition() { return xStartPosition; }


void Stickman::setColour(colour characterColour)
{
    this->characterColour = characterColour;
    switch (characterColour)
    {
    case kBlack:
        pen.setColor(Qt::black);
        brush.setColor(Qt::black);
        break;
    case kBlue:
        pen.setColor(Qt::blue);
        brush.setColor(Qt::blue);
        break;
    case kGreen:
        pen.setColor(Qt::green);
        brush.setColor(Qt::green);
        break;
    case kPink:
        pen.setColor(Qt::magenta);
        brush.setColor(Qt::magenta);
        break;
    case kOrange:
        pen.setColor(QColor(175, 125, 0));
        brush.setColor(QColor(175,125,0));
        break;
    }
}

// Sets a factor to multiply paintings by.
void Stickman::setSize(size characterSize)
{
    switch (characterSize)
    {
    case kTiny:
        xfactor = 0.1;
        break;
    case kNormal:
        xfactor = 0.2;
        break;
    case kLarge:
        xfactor = 0.3;
        break;
    case kGiant:
        xfactor = 0.4;
        break;
    }
}

// Calls paint event after setting paramaters of character.
void Stickman::createCharacter(QPainter& painter)
{
    this->resize(0.5 * xfactor * WIN_W, xfactor * WIN_H);
    setColour(characterColour);
    setSize(characterSize);
    update();
}

// Inherited from superbase QWidget.
void Stickman::paintEvent(QPaintEvent *event)
{
   QPainter painter;
   float height = xfactor * WIN_H;
   float width = 0.5 * xfactor * WIN_W;
   frame.setHeight(height);
   frame.setWidth(width);
   pen.setWidth(xfactor * 30);

   painter.begin(this);
   painter.setWindow(frame);
   painter.setBrush(brush);
   painter.setPen(pen);

   // Begin drawing
   painter.drawEllipse(width/4, 0, width/2, height/4);   // Head
   painter.drawLine(width/2, height/4, width/2, 3*height/4);     // Body
   painter.drawLine(width/2, height/3, 3*width/4, 3*height/7);    // Right upper arm
   painter.drawLine(3*width/4, 3*height/7, width, 2*height/7);    // Right forearm
   painter.drawLine(width/2, height/3, width/4, 2*height/7);   // Left upper arm
   painter.drawLine(width/4, 2*height/7, 0, 3*height/7);       // Left forearm
   painter.drawLine(width/2, 3*height/4, 3*width/4, 5*height/8);     // Right upper leg
   painter.drawLine(3*width/4, 5*height/8, width, 3*height/4);     // Right lower leg
   painter.drawLine(width/2, 3*height/4, 3*width/8, 7*height/8);     // Left upper leg
   painter.drawLine(3*width/8, 7*height/8, width/8, height);     // Left lower leg

}

