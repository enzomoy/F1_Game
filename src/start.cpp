#include "../include/start.h"

Start::Start(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    label = new QLabel("Select your driver", this);
    label->setProperty("class", "selectDrivers");


    backButton = createButton("Back", this);
    backButton->setProperty("class", "backButton");

    layout->addWidget(label);
    layout->addWidget(backButton);

    connect(backButton, &QPushButton::clicked, this, &Start::buttonBackClick);
}

void Start::buttonBackClick() {
    emit backClicked(); //
}

QPushButton* Start::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}
