#pragma once

#include <QWidget>
#include <QPainter>

/*
 *  Abstract Base class for creation of game characters
*/

namespace game1
{

class AbstractCharacter : public QWidget
{
public:

    enum size
    {
        kTiny ,
        kNormal,
        kLarge,
        kGiant
    };

    enum characterType
    {
        kStickman
    };

    // Contructor to be called by child classes
    AbstractCharacter(int xStartPositon, size characterSize);
    virtual ~AbstractCharacter() = default;

    // Getter methods.
    int getxStartPosition();
    size getSize();

    virtual void createCharacter(QPainter& painter) = 0;

protected:
    int xStartPosition;
    size characterSize;
};

}	// Project namespace.
