#include <QMessageBox>
#include "configgui.h"

using namespace game1;

ConfigGui::ConfigGui(EventHandler& handler)
    : AbstractGameGui (),
      handler(handler)
{
    this->setWindowFlag(Qt::Popup);
    this->setWindowTitle("Configuration");
    this->setGeometry(0, 100, WIN_W, 800);
    this->setStyle(new QCommonStyle);
    this->setForegroundRole(QPalette::Mid);
    this->setBackgroundRole(QPalette::Window);
    this->setAutoFillBackground(true);
    buildGui();
}

ConfigGui::ConfigGui(ConfigGui& toCopy)
    : AbstractGameGui(),
      handler(toCopy.handler)
{
}

// Getter methods.
QString ConfigGui::getSize() { return size; }

QString ConfigGui::getColour() { return colour; }

QString ConfigGui::getSpeed() { return speed; }

QString ConfigGui::getLevel() { return level; }

QString ConfigGui::getxPosition() { return xPosition; }

void ConfigGui::buildGui()
{
    // Size selection table.
    QTableWidget* sizeOptions = new QTableWidget(this);
    sizeOptions->verticalHeader()->setVisible(false);
    sizeOptions->horizontalHeader()->setStretchLastSection(true);
    sizeOptions->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    sizeOptions->setBackgroundRole(QPalette::Mid);
    sizeOptions->setForegroundRole(QPalette::Mid);
    sizeOptions->setGeometry(100, 200, 250, 250);
    sizeOptions->setRowCount(4);
    sizeOptions->setColumnCount(1);
    sizeOptions->setHorizontalHeaderItem(0, new QTableWidgetItem("SIZE"));
    sizeOptions->setItem(0, 0, new QTableWidgetItem("Tiny"));
    sizeOptions->setItem(1, 0, new QTableWidgetItem("Normal"));
    sizeOptions->setItem(2, 0, new QTableWidgetItem("Large"));
    sizeOptions->setItem(3, 0, new QTableWidgetItem("Giant"));


    // Colour selection table.
    QTableWidget* colourOptions = new QTableWidget(this);
    colourOptions->verticalHeader()->setVisible(false);
    colourOptions->horizontalHeader()->setStretchLastSection(true);
    colourOptions->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    colourOptions->setGeometry(300, 200, 250, 250);
    colourOptions->setRowCount(5);
    colourOptions->setColumnCount(1);
    colourOptions->setHorizontalHeaderItem(0, new QTableWidgetItem("COLOUR"));
    colourOptions->setItem(0, 0, new QTableWidgetItem("Black"));
    colourOptions->setItem(1, 0, new QTableWidgetItem("Blue"));
    colourOptions->setItem(2, 0, new QTableWidgetItem("Pink"));
    colourOptions->setItem(3, 0, new QTableWidgetItem("Orange"));
    colourOptions->setItem(4, 0, new QTableWidgetItem("Green"));


    // Speed selection table.
    QTableWidget* speedOptions = new QTableWidget(this);
    speedOptions->verticalHeader()->setVisible(false);
    speedOptions->horizontalHeader()->setStretchLastSection(true);
    speedOptions->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    speedOptions->setGeometry(500, 200, 250, 250);
    speedOptions->setRowCount(5);
    speedOptions->setColumnCount(1);
    speedOptions->setHorizontalHeaderItem(0, new QTableWidgetItem("SPEED"));
    speedOptions->setItem(0, 0, new QTableWidgetItem("1x"));
    speedOptions->setItem(1, 0, new QTableWidgetItem("2x"));
    speedOptions->setItem(2, 0, new QTableWidgetItem("3x"));
    speedOptions->setItem(3, 0, new QTableWidgetItem("4x"));
    speedOptions->setItem(4, 0, new QTableWidgetItem("5x"));


    // Level selection table.
    QTableWidget* levelOptions = new QTableWidget();
    levelOptions->verticalHeader()->setVisible(false);
    levelOptions->horizontalHeader()->setStretchLastSection(true);
    levelOptions->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    levelOptions->setGeometry(700, 200, 250, 250);
    levelOptions->setRowCount(3);
    levelOptions->setColumnCount(1);
    levelOptions->setHorizontalHeaderItem(0, new QTableWidgetItem("LEVEL"));
    levelOptions->setItem(0, 0, new QTableWidgetItem("zero"));
    levelOptions->setItem(1, 0, new QTableWidgetItem("one"));
    levelOptions->setItem(2, 0, new QTableWidgetItem("two"));

    // Insert all tables horizontally adjacent.
    QHBoxLayout* tables = new QHBoxLayout();
    tables->setSpacing(0);
    tables->addWidget(sizeOptions);
    tables->addWidget(speedOptions);
    tables->addWidget(colourOptions);
    tables->addWidget(levelOptions);


    // Starting position selector (slider).
    QSlider* positionSlider = new QSlider(Qt::Horizontal);
    positionSlider->setWindowFlag(Qt::Tool, Qt::FramelessWindowHint);
    positionSlider->setMinimum(100);
    positionSlider->setMaximum(WIN_W - 100);
    positionSlider->setFixedWidth(WIN_W - 100);
    positionSlider->setFixedHeight(75);
    positionSlider->setTickInterval(QSlider::TicksAbove);
    positionSlider->setParent(this);
    QLabel* sliderTitle = new QLabel("Move the slider to your starting position");
    sliderTitle->setFont(QFont( "Block", 14, QFont::Bold));

    // Insert slider into vertical layout with title.
    QVBoxLayout* slider = new QVBoxLayout();
    slider->addWidget(sliderTitle);
    slider->addWidget(positionSlider);


    // Button to save selections.
    QPushButton* saveButton = new QPushButton("SAVE");
    saveButton->setFixedSize(200, 75);
    // Button  to use default settings.
    QPushButton* defaultButton = new QPushButton("DEFAULT");
    defaultButton->setFixedSize(200, 75);

    // Insert buttons into horizontal layout.
    QHBoxLayout* buttons = new QHBoxLayout();
    buttons->addWidget(saveButton);
    buttons->addWidget(defaultButton);


    // Insert everything stacked. Ensure ownership to configgui for destruction.
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(tables);
    layout->addLayout(slider);
    layout->addLayout(buttons);


    // Connect item signals to slots. //
    // Size table.
    QObject::connect(sizeOptions, SIGNAL(cellClicked(int, int)),
                     this, SLOT(onSizeSelect(int, int)));
    // Colour table.
    QObject::connect(colourOptions, SIGNAL(cellClicked(int, int)),
                     this, SLOT(onColourSelect(int, int)));
    // Level table.
    QObject::connect(levelOptions, SIGNAL(cellClicked(int, int)),
                     this, SLOT(onLevelSelect(int, int)));
    // Speed table.
    QObject::connect(speedOptions, SIGNAL(cellClicked(int, int)),
                     this, SLOT(onSpeedSelect(int, int)));

    // Position slider.
    QObject::connect(positionSlider, SIGNAL(valueChanged(int)),
                     this, SLOT(onPositionSelect(int)));

    // Save button.
   QObject::connect(saveButton, SIGNAL(clicked()),
                    (const QObject*)&handler, SLOT(onConfigSave()));
    // Default button.
   QObject::connect(defaultButton, SIGNAL(clicked()),
                    (const QObject*)&handler, SLOT(onConfigDefault()));
}


// Slot methods //
void ConfigGui::onPositionSelect(int xPosition)
{
    this->xPosition = QString::number(xPosition);
}

void ConfigGui::onSizeSelect(int row, int col)
{
    if (row == 0) { this->size = "tiny"; }

    else if (row == 1) { this->size = "normal"; }

    else if (row == 2) { this->size = "large"; }

    else if (row == 3) { this->size = "giant"; }
}

void ConfigGui::onColourSelect(int row, int col)
{
    if (row == 0) { this->colour = "black"; }

    else if (row == 1) { this->colour = "blue"; }

    else if (row == 2) { this->colour = "pink"; }

    else if (row == 3) { this->colour = "orange"; }

    else if (row == 4) { this->colour = "green"; }
}

void ConfigGui::onSpeedSelect(int row, int col)
{
    if (row == 0) { this->speed = "1x"; }

    else if (row == 1) { this->speed = "2x"; }

    else if (row == 2) { this->speed = "3x"; }

    else if (row == 3) { this->speed = "4x"; }

    else if (row == 4) { this->speed = "5x"; }
}

void ConfigGui::onLevelSelect(int row, int col)
{
    if (row == 0) { this->level = "zero"; }

    else if (row == 1) { this->level = "one"; }

    else if (row == 2) { this->level = "two"; }
}
