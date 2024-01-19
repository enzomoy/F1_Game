#include "../include/circuit.h"

Circuit::Circuit(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    buttonStatistiques = createButton("Statistiques", this);
    buttonStatistiques->setProperty("class", "buttonStatistiques");
    layout->addWidget(buttonStatistiques);

    buttonCourses = createButton("Courses", this);
    buttonCourses->setProperty("class", "buttonCourses");
    layout->addWidget(buttonCourses);

    backButtonCircuit = createButton("Back", this);
    backButtonCircuit->setProperty("class", "buttonCircuitBackClick");

    connect(backButtonCircuit, &QPushButton::clicked, this, &Circuit::buttonCircuitBackClick);

    connect(buttonStatistiques, &QPushButton::clicked, this, &Circuit::buttonStatistiquesClick);
}

QPushButton* Circuit::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}
