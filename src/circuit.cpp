#include "../include/circuit.h"

Circuit::Circuit(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    circuit1 = createButton("Circuit 1", this);
    circuit1->setProperty("class", "circuit1");

    circuit2 = createButton("Circuit 2", this);
    circuit2->setProperty("class", "circuit2");

    circuit3 = createButton("Circuit 3", this);
    circuit3->setProperty("class", "circuit3");

    backButtonCircuit = createButton("Back", this);
    backButtonCircuit->setProperty("class", "buttonCircuitBackClick");

    connect(backButtonCircuit, &QPushButton::clicked, this, &Circuit::buttonCircuitBackClick);
}

QPushButton* Circuit::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}
