#pragma once

#include <QEventLoop>
#include "gameplayinggui.h"
#include "optionsgui.h"
#include "configgui.h"
#include "configurer.h"
#include "characterfactory.h"

/*
 * Class is responsible for communication between GUIs and conrols navigation
 * between them. It also has access to the configurer, forwarding changes to and from it.
 * Additionally it calls the character factory, to recieve characters based on
 * configuration values and passes them to a requesting GUI.
*/

namespace game1
{

class EventHandler : public QObject
{
    Q_OBJECT

public:
    EventHandler(QApplication& guiApp);
    ~EventHandler() = default;

    QApplication& guiApp;

public slots:
    // on<Calling gui><Selection/Event>
    void onOptionsStart();
    void onOptionsConfigure();
    void onOptionsQuit();
    void onOptionsResume();

    void onConfigSave();
    void onConfigDefault();

    void onGamePlayPause();

private:
    Configurer preferenceManager = Configurer();
    // GUIs being handled.
    GamePlayingGui* gameplay = new GamePlayingGui(*this);
    ConfigGui* config = new ConfigGui(*this);
    OptionsGui* options = new OptionsGui(*this);
};

}	// Project namespace.
