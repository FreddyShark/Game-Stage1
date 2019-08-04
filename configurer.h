#pragma once

#include <QtXml>
#include <QString>

/*
 * Class is responsible for accessing configuration file, making changes to values, and forwarding
 * them upon request.
 */

namespace game1
{

class Configurer
{
public:
    Configurer() = default;
    ~Configurer() = default;

    // Getter methods.
    QString getSize();
    QString getLevel();
    QString getColour();
    QString getSpeed();
    QString getPosition();

    // Setter methods.
    void setSize(QString size);
    void setLevel(QString level);
    void setColour(QString colour);
    void setSpeed(QString speed);
    void setPosition(QString xPosition);

    void readConfig();
    void writeToConfig();

private:
    const QString filePath = "unembedded_rsc/.config.xml";
    QString size = "normal";
    QString level = "zero";
    QString colour = "black";
    QString speed = "1x";
    QString xPosition = "100";
};

}   // Project namespace.

