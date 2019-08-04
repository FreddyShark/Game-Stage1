#include "optionsgui.h"

using namespace game1;

OptionsGui::OptionsGui(const EventHandler& handler)
    : AbstractGameGui(), handler(handler)
{
    this->setWindowFlag(Qt::Popup);
    this->setWindowTitle("Options");
    this->setGeometry(WIN_W/4, WIN_H/3, WIN_W/2, WIN_H/2);
    this->setBackgroundRole(QPalette::Window);
    this->setForegroundRole(QPalette::Window);
    this->setAutoFillBackground(true);
}

OptionsGui::OptionsGui(const OptionsGui& toCopy)
    : AbstractGameGui(), handler(toCopy.handler) { }

void OptionsGui::buildGui()
{
    // Create buttons.
    QPushButton* startButton = new QPushButton("Start");
    QPushButton* configButton = new QPushButton("Configure");
    QPushButton* quitButton = new QPushButton("Quit");
    resumeButton = new QPushButton("Resume");
    QHBoxLayout* buttonLayout = new QHBoxLayout(this);

    // Connect them to Event handler.
    QObject::connect(resumeButton, SIGNAL(clicked()),
                     (const QObject*)&handler, SLOT(onOptionsResume()));

    QObject::connect(startButton, SIGNAL(clicked()),
                     (const QObject*)&handler, SLOT(onOptionsStart()));

    QObject::connect(configButton, SIGNAL(clicked()),
                     (const QObject*)&handler, SLOT(onOptionsConfigure()));

    QObject::connect(quitButton, SIGNAL(clicked()),
                     (const QObject*)&handler, SLOT(onOptionsQuit()));


    // Create layout.
    QRect buttonFrame = QRect(WIN_W/8, WIN_H/2, WIN_W/2, WIN_H/8);
    buttonLayout->setGeometry(buttonFrame);

    buttonLayout->addWidget(quitButton);
    buttonLayout->addWidget(resumeButton);
    buttonLayout->addWidget(configButton);
    buttonLayout->addWidget(startButton);

    this->setLayout(buttonLayout);
}
