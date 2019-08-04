#pragma once

#include "guiglobals.h"
#include "abstractgamegui.h"

/*
 * Concrete implementation of base class AbstractGameGui, dedicated as an options menu ui.
 * It is the parent of all over GUIs and requested characters.
 */

namespace game1
{

class OptionsGui : public AbstractGameGui
{
    Q_OBJECT
    friend class EventHandler;

public:
    // Constructors and destructors.
    OptionsGui(const EventHandler& handler);
    OptionsGui(const OptionsGui& toCopy);
    ~OptionsGui() override = default;

    QPushButton* resumeButton;

protected:
    const EventHandler& handler;

    void buildGui() override;
};

}
