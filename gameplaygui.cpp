#include "gameplaygui.h"
#include "characterfactory.h"

using namespace game1;

GameplayGui::GameplayGui(EventHandler& handler)
    : AbstractGameGui(),
      handler(handler)
{
    rootWindow->show();
    CharacterFactory::getCharacter(Stickman::kStickman);
}

GameplayGui::GameplayGui(GameplayGui& toCopy )
    : AbstractGameGui(),
      handler(toCopy.handler)
{
   // this->levelIMG = toCopy.levelIMG;
    this->canvas = toCopy.canvas;
    this->rootWindow = toCopy.rootWindow;
}

GameplayGui::~GameplayGui()
{
    delete this;
}

void GameplayGui::buildGui()
{

    //scene->addPixmap(QBitmap::fromImage(levelIMG));
}
