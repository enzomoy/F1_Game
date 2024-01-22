#include "../include/circuit_info.h"

CircuitInfo::CircuitInfo(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    backButtonCircuitInfo = createButton("Back", this);
    backButtonCircuitInfo->setProperty("class", "backButtonCircuitInfo");
    layout->addWidget(backButtonCircuitInfo);

    connect(backButtonCircuitInfo, &QPushButton::clicked, this, &CircuitInfo::buttonCoursesInfoBackClick);
}

void CircuitInfo::onBackButtonCircuitInfoClick() {
    emit buttonCoursesInfoBackClick();
}

QPushButton* CircuitInfo::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}