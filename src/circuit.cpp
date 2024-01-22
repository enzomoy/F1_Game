// circuit.cpp
#include "../include/circuit.h"
#include <QFrame>

Circuit::Circuit(QWidget *parent) : QWidget(parent) {

    layout = new QVBoxLayout(this);

    int id = getPilot();
    Pilots selectedPilot = getDriverData(id);

    PilotsName = new QLabel(selectedPilot.nom, this);
    PilotsName->setProperty("class", "PilotsName");
    layout->addWidget(PilotsName);

    buttonStatistiques = createButton("Statistiques", this);
    buttonStatistiques->setProperty("class", "buttonStatistiques");
    layout->addWidget(buttonStatistiques);

    buttonCourses = createButton("Courses", this);
    buttonCourses->setProperty("class", "buttonCourses");
    layout->addWidget(buttonCourses);

    backButtonCircuit = createButton("Back", this);
    backButtonCircuit->setProperty("class", "buttonCircuitBackClick");
    layout->addWidget(backButtonCircuit);

    connect(backButtonCircuit, &QPushButton::clicked, this, &Circuit::buttonCircuitBackClick);
    connect(buttonStatistiques, &QPushButton::clicked, this, &Circuit::buttonStatistiquesClick);

    connect(buttonCourses, &QPushButton::clicked, this, &Circuit::buttonCoursesClick);
}

QPushButton* Circuit::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

void Circuit::setSelectedDriverId(int driverId) {
    selectedDriverId = driverId;
}
