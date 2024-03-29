#-------------------------------------------------
#
# Project created by QtCreator 2019-04-06T10:47:16
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
#        dialog.cpp \
    abstractgamegui.cpp \
    characterfactory.cpp \
    configgui.cpp \
    configurer.cpp \
    eventhandler.cpp \
#    gameplaygui.cpp \
    optionsgui.cpp \
    stickman.cpp \
    abstractgamegui.cpp \
    characterfactory.cpp \
    configgui.cpp \
    configurer.cpp \
    eventhandler.cpp \
#    gameplaygui.cpp \
    main.cpp \
    optionsgui.cpp \
    stickman.cpp \
    gameplayinggui.cpp \
    abstractcharacter.cpp

HEADERS += \
#        dialog.h \
    guiglobals.h \
    abstractcharacter.h \
    abstractgamegui.h \
    characterfactory.h \
    configgui.h \
    configurer.h \
    eventhandler.h \
#    gameplaygui.h \
    optionsgui.h \
    stickman.h \
    abstractcharacter.h \
    abstractgamegui.h \
    characterfactory.h \
    configgui.h \
    configurer.h \
    eventhandler.h \
#    gameplaygui.h \
    optionsgui.h \
    stickman.h \
    characters.h \
    gameplayinggui.h \
    characters.h

FORMS += \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    unembedded_rsc/.config.xml
