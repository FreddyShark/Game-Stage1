#include "abstractcharacter.h"

using namespace game1;

AbstractCharacter::AbstractCharacter(int xStartPostion,  size characterSize)
    : xStartPosition(xStartPostion),
      characterSize(characterSize) { }

int AbstractCharacter::getxStartPosition() { return xStartPosition; }

AbstractCharacter::size AbstractCharacter::getSize() { return characterSize; }
