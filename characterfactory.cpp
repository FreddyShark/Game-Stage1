#include "characterfactory.h"

using namespace game1;

AbstractCharacter* CharacterFactory::getCharacter(AbstractCharacter::characterType type,
                                                  QString size,
                                                  QString position,
                                                  QString colour = "")
{
    switch (type)
    {
    case AbstractCharacter::kStickman:
        return new Stickman(position.toInt(), setSizeAttribute(size), setColourAttribute(colour));

    // TODO : Add more character types as switch cases and extend constructor with
    // needed attributes.

    } throw "Character type does not exist.";
}

// Helper function.
AbstractCharacter::size CharacterFactory::setSizeAttribute(QString size)
{
    if (size == "tiny") { return AbstractCharacter::size::kTiny; }

    else if (size == "normal") { return AbstractCharacter::size::kNormal; }

    else if (size == "large") { return AbstractCharacter::size::kLarge; }

    else if (size == "giant") { return AbstractCharacter::size::kGiant; }

    else throw "invalid size for character type.";
}

Stickman::colour CharacterFactory::setColourAttribute(QString colour)
{
    if (colour == "black") { return Stickman::colour::kBlack; }

    else if (colour == "blue") { return Stickman::colour::kBlue; }

    else if (colour == "pink") { return Stickman::colour::kPink; }

    else if (colour == "green") { return Stickman::colour::kGreen; }

    else if (colour == "orange") { return Stickman::colour::kOrange; }

    else throw "invalid colour for type.";
}
