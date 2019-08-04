#include <QApplication>
#include "eventhandler.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication guiApp(argc, argv);
    const game1::EventHandler handler(guiApp);

    return guiApp.exec();
}

