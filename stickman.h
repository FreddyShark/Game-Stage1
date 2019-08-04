#pragma once

#include "abstractcharacter.h"
#include "guiglobals.h"

/*
 * Concrete implementation of AbstractCharacter class. Creates a basic sitckman, with changeable
 * size and colour.
*/

namespace game1
{

class Stickman : public AbstractCharacter
{
    Q_OBJECT

public:
    enum colour
    {
        kBlack,
        kBlue,
        kGreen,
        kPink,
        kOrange
    };

    // Constructors and destructors.
    Stickman(int xStartPosition = 100, size characterSize = kNormal,
             colour characterColour = kBlack);

    Stickman(Stickman* toCopy);
    ~Stickman() override = default;

    // Getter methods.
    colour getColour();
    int getStartPosition();

    // Setter methods.
    void setColour(colour characterColour);
    void setSize(size characterSize);

    void createCharacter(QPainter& painter) override;

protected:

    colour characterColour;
    QPen pen = QPen(Qt::black);
    QBrush brush = QBrush(Qt::transparent);
    QRect frame = QRect();
    float xfactor = 0.0;

    // Overrides from QWidget Superbase
    void paintEvent(QPaintEvent *event) override;
};

}	// Project namespace.
