#pragma once

#include <QDialog>
#include <QPainter>

/*
 * Abstract Base class for creation of game GUIs.
 */

namespace game1
{
// Forward declaration
class EventHandler;

/* Abstract base class for all GUI pages */
class AbstractGameGui : public QDialog
{
public:
    // Constructor to be called by child classes
    AbstractGameGui();
    virtual ~AbstractGameGui() = default;

    virtual void buildGui() = 0;

protected:

};

}	// Project namespace.
