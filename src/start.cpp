// start.cpp
#include "../include/start.h"

Start::Start(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    label = new QLabel("Select your driver", this);
    label->setProperty("class", "selectDrivers");

    backButton = createButton("Back", this);
    backButton->setProperty("class", "backButton");

    int lenx = globalConfig.width / 10;
    int x = lenx;

    int leny = globalConfig.height / 6;
    int y = leny;

    char **pilots = getAllPilots();
    for (int i = 0; i < 20; i++) {
        driversButton = createButton(pilots[i], this);
        driversButton->setProperty("class", "driversButton");
        driversButton->setGeometry(x, y, globalConfig.width/7 , globalConfig.height / 15);
        x += globalConfig.width / 6;
        if (x > globalConfig.width - globalConfig.width/6) {
            x = lenx;
            y += leny;
        }
        connect(driversButton, &QPushButton::clicked, this, [this, i]() {
            onDriverButtonClicked(i);
        });
    }

    layout->addWidget(label);
    layout->addWidget(backButton);
    if (&QPushButton::clicked) {
        connect(backButton, &QPushButton::clicked, this, &Start::buttonBackClick);
    }
}

void Start::buttonBackClick() {
    emit backClicked();
}

QPushButton* Start::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

void Start::onDriverButtonClicked(int driverIndex) {
    emit driverButtonClicked(driverIndex);
    emit driverSelected(driverIndex);
}
