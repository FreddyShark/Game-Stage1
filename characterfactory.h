#pragma once

#include "characters.h"

/*
 * An Abstract factory class to encapsulate the process of character creation away from requester.
 */

namespace game1
{

class CharacterFactory
{
public:
    static AbstractCharacter* getCharacter(AbstractCharacter::characterType type,
                                           QString size,
                                           QString positon,
                                           QString colour);

private:
    // Helper functions.
    static AbstractCharacter::size setSizeAttribute(QString size);
    static Stickman::colour setColourAttribute(QString size);

    CharacterFactory() = default;
    ~CharacterFactory() = default;
};

}   // Project namepsace.
