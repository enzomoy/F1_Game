#include "../include/circuit.h"
#include <QFrame>
#include "../include/mysql.h"

Circuit::Circuit(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    QFrame *horizontalLine = new QFrame();
    horizontalLine->setFrameShape(QFrame::HLine);
    horizontalLine->setFrameShadow(QFrame::Plain);
    horizontalLine->setLineWidth(50);
    layout->addWidget(horizontalLine);

    buttonStatistiques = createButton("Statistiques", this);
    buttonStatistiques->setProperty("class", "buttonStatistiques");
    buttonStatistiques->move(2*globalConfig.width/7 , 2*globalConfig.height / 3);
    buttonStatistiques->resize(2*globalConfig.width/7 , globalConfig.height / 10);
    layout->addWidget(buttonStatistiques);

    buttonCourses = createButton("Courses", this);
    buttonCourses->setProperty("class", "buttonCourses");
    layout->addWidget(buttonCourses);

    backButtonCircuit = createButton("Back", this);
    backButtonCircuit->setProperty("class", "buttonCircuitBackClick");
    layout->addWidget(backButtonCircuit);

    connect(backButtonCircuit, &QPushButton::clicked, this, &Circuit::buttonCircuitBackClick);

    connect(buttonStatistiques, &QPushButton::clicked, this, &Circuit::buttonStatistiquesClick);
}

QPushButton* Circuit::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}
