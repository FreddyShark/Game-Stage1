#pragma once

#include "abstractgamegui.h"
#include "guiglobals.h"

/*
 * Concrete implementation of base class AbstractGameGui, dedicated as a ui for configurating
 * the game.
 */

namespace game1
{

class ConfigGui : public AbstractGameGui
{
    Q_OBJECT

public:
    const EventHandler& handler;

    // Constructors and destructors.
    ConfigGui(EventHandler& handler);
    ConfigGui(ConfigGui& toCopy);
    ~ConfigGui() override = default;

    // Getter methods
    QString getSize();
    QString getColour();
    QString getSpeed();
    QString getLevel();
    QString getxPosition();

protected:
    void buildGui() override;

   QString size;
   QString colour;
   QString speed;
   QString level;
   QString xPosition;

public slots:
    void onSizeSelect(int row, int col);
    void onColourSelect(int row, int col);
    void onLevelSelect(int row, int col);
    void onSpeedSelect(int row, int col);
    void onPositionSelect(int xPosition);
};

}
