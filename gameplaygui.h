#pragma once

#include "abstractgamegui.h"
#include "dialog.h"

namespace game1
{

class GameplayGui : public AbstractGameGui
{
    Q_OBJECT


public:
    const EventHandler& handler;
    QPalette canvas = *new QPalette;
    Dialog* rootWindow = new Dialog;

    // Constructors, Copy, Destructors.
    GameplayGui(EventHandler& handler);
    GameplayGui(GameplayGui& toCopy);
    virtual ~GameplayGui();

    virtual void buildGui();

};

}	// Project namespace.
