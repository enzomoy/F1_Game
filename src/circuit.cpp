#include "../include/circuit.h"

Circuit::Circuit(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    circuit1 = createButton(" ", this);
    circuit1->setProperty("class", "circuit1");
    circuit1->setGeometry(10, 50, 180 , 300);

    circuit2 = createButton(" ", this);
    circuit2->setProperty("class", "circuit2");
    circuit2->setGeometry(200, 50, 180 , 300);

    circuit3 = createButton(" ", this);
    circuit3->setProperty("class", "circuit3");
    circuit3->setGeometry(390, 50, 180 , 300);

    backButtonCircuit = createButton("Back", this);
    backButtonCircuit->setProperty("class", "buttonCircuitBackClick");

    connect(backButtonCircuit, &QPushButton::clicked, this, &Circuit::buttonCircuitBackClick);
}

QPushButton* Circuit::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}
