#include <QFileInfo>
#include "Configurer.h"

using namespace game1;

// Getter methods.
QString Configurer::getSize() { return size; }

QString Configurer::getLevel() { return level; }

QString Configurer::getColour() { return colour; }

QString Configurer::getSpeed() { return speed; }

QString Configurer::getPosition() { return xPosition; }

// Setter methods.
void Configurer::setSize(QString size)
{
    if (size != "") { this->size = size; }
}

void Configurer::setLevel(QString level)
{
    if (level != "") { this->level = level; }
}

void Configurer::setColour(QString colour)
{
    if (colour != "") { this->colour = colour; }
}

void Configurer::setSpeed(QString speed)
{
    if (speed != "") { this->speed = speed; }
}

void Configurer::setPosition(QString xPosition)
{
    if (xPosition != "") { this->xPosition = xPosition; }
}

/*
 Please note that implementation of XML reading used
 https://www.bogotobogo.com/Qt/Qt5_QtXML_QDomDocument_QDomElement.php
 and https://www.youtube.com/watch?v=NzQwJdcdRKE (VoidRealms)
 as a guide
*/
void Configurer::readConfig()
{
    QDomDocument configParsed;
    QFile configFile(filePath);

    QFileInfo check_file(filePath);
        // If file does not exist create one with default values.
    if (!check_file.exists() || !check_file.isFile()) { writeToConfig(); }

    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw "Unable to open configuration file for reading.";
    }

    configParsed.setContent(&configFile);
    configFile.close();

   QDomElement root = configParsed.firstChildElement();
   QDomNodeList nodes = root.elementsByTagName("variable");

   for (int i = 0; i < nodes.count(); i++ )
  {
       QDomElement item = nodes.at(i).toElement();
       QString variable = item.attribute("ID");
       QString value = item.attribute("value");

       if (variable == "size") { size = value; }

       if (variable == "level") { level = value; }

       if (variable == "colour") { colour = value; }

       if (variable == "speed") { speed = value; }

       if (variable == "position") { xPosition = value; }
   }
}

void Configurer::writeToConfig()
{
    QFile configFile(filePath);
    QDomDocument configParsed;

    // Extract data to QDomDocument objec
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw "Unable to open configuration file for reading.";
    }

    configParsed.setContent(&configFile);
    configFile.close();

    QDomElement root = configParsed.firstChildElement();
    QDomNodeList nodes = root.elementsByTagName("variable");

    // Set variable values in QDomDocument.
   for (int i = 0; i < nodes.count(); i++ )
    {
       QDomElement item = nodes.at(i).toElement();
       QDomAttr variable = item.attributeNode("ID");
       QDomAttr value = item.attributeNode("value");

       if (variable.value() == "size") { value.setValue(size); }

       if (variable.value() == "level") { value.setValue(level); }

       if (variable.value() == "colour") { value.setValue(colour); }

       if (variable.value() == "speed") { value.setValue(speed); }

       if (variable.value() == "position") { value.setValue(xPosition); }
    }

    // Write out edited QDomDocument to config file.
    if (!configFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
            throw "Unable to open configuration file for writing";
    }

    QTextStream newText(&configFile);
    newText << configParsed.toString();
    configFile.close();
}

