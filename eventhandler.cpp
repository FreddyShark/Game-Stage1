#include "eventhandler.h"

using namespace game1;


EventHandler::EventHandler(QApplication& guiApp)
    :guiApp(guiApp)
{
    options->buildGui();
    options->resumeButton->hide();
    options->show();
}

void EventHandler::onOptionsStart()
{
    preferenceManager.readConfig();
    QString size = preferenceManager.getSize();
    QString colour = preferenceManager.getColour();
    QString position = preferenceManager.getPosition();

    // call character factory and dynamically cast base class to desired character subclass.
    Stickman* player = static_cast<Stickman*>
           (CharacterFactory::getCharacter(AbstractCharacter::kStickman, size, position, colour));

    gameplay->setCharacter(player, "stickman");
    gameplay->level = preferenceManager.getLevel();
    gameplay->speed = preferenceManager.getSpeed();
    gameplay->buildGui();
    options->resumeButton->show();
    options->hide();
}

void EventHandler::onOptionsConfigure()
{
    options->hide();
    config->show();
}

void EventHandler::onOptionsResume()
{
    options->hide();
    gameplay->showSplash = false;
    gameplay->timer.start();
}

void EventHandler::onOptionsQuit()
{
    options->hide();
    gameplay->hide();
    delete gameplay;
    delete config;
    delete options;
    guiApp.exit();
}

void EventHandler::onGamePlayPause()
{
    gameplay->timer.stop();
    options->show();
}

void EventHandler::onConfigSave()
{
    preferenceManager.setSize(config->getSize());
    preferenceManager.setColour(config->getColour());
    preferenceManager.setLevel(config->getLevel());
    preferenceManager.setSpeed(config->getSpeed());
    preferenceManager.setPosition(config->getxPosition());
    preferenceManager.writeToConfig();
    config->hide();
    options->show();
}

void EventHandler::onConfigDefault()
{
    // Write default values in configurer class to file.
    preferenceManager.writeToConfig();
    config->hide();
    options->show();
}
