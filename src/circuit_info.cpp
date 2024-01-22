#include "../include/circuit_info.h"

CircuitInfo::CircuitInfo(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout(this);
    layout = new QVBoxLayout(this);

    int id = getCircuit();
    CircuitData circuits = getCircuitData(id);
    

CircuitName = new QLabel( circuits.nom);
CircuitName->setProperty("class", "CircuitName");
CircuitName->setStyleSheet("font-size: 32px; margin-left : 200%;");
layout->addWidget(CircuitName);
mainLayout->addLayout(layout);

//////////////////////////////

infoCircuit = new QVBoxLayout(this);

CircuitPays = new QLabel(QString("Pays : %1").arg(circuits.pays));
CircuitPays->setProperty("class", "CircuitPays");
CircuitPays->setStyleSheet("font-size: 32px; margin-left: 200%;");
infoCircuit->addWidget(CircuitPays);


CircuitTours = new QLabel( "Nombre de tour  : " + QString::number(circuits.nombre_de_tours), this );
CircuitTours->setProperty("class", "CircuitTours");
CircuitTours->setStyleSheet("font-size: 32px; margin-left : 200%;");
infoCircuit->addWidget(CircuitTours);

CircuitLen = new QLabel( "Longueur du circuit : " + QString::number(circuits.longueur_circuit), this );
CircuitLen->setProperty("class", "CircuitLen");
CircuitLen->setStyleSheet("font-size: 32px; margin-left : 200%;");
infoCircuit->addWidget(CircuitLen);

CircuitType = new QLabel(QString("Type : %1").arg(circuits.type_circuit));
CircuitType->setProperty("class", "CircuitType");
CircuitType->setStyleSheet("font-size: 32px; margin-left : 200%;");
infoCircuit->addWidget(CircuitType);

CircuitLeft = new QLabel(QString("Virages gauche : %1").arg(circuits.virages_gauche));
CircuitLeft->setProperty("class", "CircuitLeft");
CircuitLeft->setStyleSheet("font-size: 32px; margin-left : 200%;");
infoCircuit->addWidget(CircuitLeft);

CircuitRight = new QLabel(QString("Virages gauche : %1").arg(circuits.virages_droite));
CircuitRight->setProperty("class", "CircuitRight");
CircuitRight->setStyleSheet("font-size: 32px; margin-left : 200%;");
infoCircuit->addWidget(CircuitRight);

CircuitDrs = new QLabel( "Nombre de zone drs : " + QString::number( circuits.zones_drs), this  );
CircuitDrs->setProperty("class", "CircuitDrs");
CircuitDrs->setStyleSheet("font-size: 32px; margin-left : 200%;");
infoCircuit->addWidget(CircuitDrs);
mainLayout->addLayout(infoCircuit);

///////////////////

    backButton = new QVBoxLayout(this);

    backButtonCircuitInfo = createButton("Back", this);
    backButtonCircuitInfo->setProperty("class", "backButtonCircuitInfo");
    backButtonCircuitInfo->setStyleSheet("    padding: 15px 32px;\n"
                                          "    text-align: center;\n"
                                          "    font-size: 16px;\n"
                                          "    margin: 4px 2px;\n"
                                          "    margin-left: 20%;\n"
                                          "    margin-right: 20%;\n"
                                          "    background-color: lightcoral;");
    backButton->addWidget(backButtonCircuitInfo);
    mainLayout->addLayout(backButton);

    connect(backButtonCircuitInfo, &QPushButton::clicked, this, &CircuitInfo::buttonCoursesInfoBackClick);

}

void CircuitInfo::onBackButtonCircuitInfoClick() {
    emit buttonCoursesInfoBackClick();
}

QPushButton* CircuitInfo::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

