/*
 * Fichier : circuit.cpp
 * Description: Fichier source de circuit.h
 */

#include "../include/circuit.h"
#include <QFrame>

Circuit::Circuit(QWidget *parent) : QWidget(parent) {

    layout = new QVBoxLayout(this);

    int id = getPilot();
    Pilots selectedPilot = getDriverData(id);

    PilotsName = new QLabel(selectedPilot.nom, this);
    PilotsName->setProperty("class", "PilotsName");
    PilotsName->setStyleSheet("    font-size: 30px;\n"
                                 "    margin-left: 280%;\n"
                                 "    margin-bottom: 200%;");
    layout->addWidget(PilotsName);

    buttonStatistiques = createButton("Statistiques", this);
    buttonStatistiques->setProperty("class", "buttonStatistiques");
    buttonStatistiques->setStyleSheet("    padding: 15px 32px;\n"
                                      "    text-align: center;\n"
                                      "    font-size: 16px;\n"
                                      "    margin: 4px 2px;\n"
                                      "    margin-left: 80%;\n"
                                      "    margin-right: 80%;\n"
                                      "    margin-bottom: 100%;");
    layout->addWidget(buttonStatistiques);

    buttonCourses = createButton("Courses", this);
    buttonCourses->setProperty("class", "buttonCourses");
    buttonCourses->setStyleSheet("    padding: 15px 32px;\n"
                                 "    text-align: center;\n"
                                 "    font-size: 16px;\n"
                                 "    margin: 4px 2px;\n"
                                 "    margin-left: 80%;\n"
                                 "    margin-right: 80%;");
    layout->addWidget(buttonCourses);

    backButtonCircuit = createButton("Back", this);
    backButtonCircuit->setProperty("class", "buttonCircuitBackClick");
    backButtonCircuit->setStyleSheet("    padding: 15px 32px;\n"
                                     "    text-align: center;\n"
                                     "    font-size: 16px;\n"
                                     "    margin: 4px 2px;\n"
                                     "    margin-left: 20%;\n"
                                     "    margin-right: 20%;\n"
                                     "    background-color: lightcoral;");
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
