#include "../include/statistiques.h"

Statistiques::Statistiques(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QVBoxLayout *nameLayout = new QVBoxLayout();


    int id = getPilot();
    Pilots selectedPilot = getDriverData(id);

    PilotsName = new QLabel(selectedPilot.nom, this);
    PilotsName->setProperty("class", "PilotsName");
    nameLayout->addWidget(PilotsName);
    mainLayout->addLayout(nameLayout);

    //////////////////////////////

    QVBoxLayout *infoLayout = new QVBoxLayout();
    infoLayout->addSpacerItem(new QSpacerItem(40, 80, QSizePolicy::Minimum, QSizePolicy::Expanding));

    PilotsRaces = new QLabel(" Nombre de course :" + QString::number(selectedPilot.courses), this);
    PilotsRaces->setProperty("class", "PilotsRaces");
    PilotsRaces->setStyleSheet("font-size: 32px; margin-left : 200%;");
    infoLayout->addWidget(PilotsRaces);

    PilotsWin = new QLabel(" Nombre de victoire :" + QString::number(selectedPilot.victoires), this);
    PilotsWin->setProperty("class", "PilotsWin");
    PilotsWin->setStyleSheet("font-size: 32px; margin-left : 200%;");
    infoLayout->addWidget(PilotsWin);

    PilotsLaps = new QLabel( " Nombre de tour :" + QString::number(selectedPilot.laps), this);
    PilotsLaps->setProperty("class", "PilotsLaps");
    PilotsLaps->setStyleSheet("font-size: 32px; margin-left : 200%;");
    infoLayout->addWidget(PilotsLaps);

    PilotsPoints = new QLabel( " Nombre de point :" +QString::number(selectedPilot.points), this);
    PilotsPoints->setProperty("class", "PilotsPoints");
    PilotsPoints->setStyleSheet("font-size: 32px; margin-left : 200%;");
    infoLayout->addWidget(PilotsPoints);

    PilotsPodiums = new QLabel( " Nombre de podium :" +QString::number(selectedPilot.podiums), this);
    PilotsPodiums->setProperty("class", "PilotsPodiums");
    PilotsPodiums->setStyleSheet("font-size: 32px; margin-left : 200%;");
    infoLayout->addWidget(PilotsPodiums);


    PilotsPoles = new QLabel( " Nombre de pole :" +QString::number(selectedPilot.poles), this);
    PilotsPoles->setProperty("class", "PilotsPoles");
    PilotsPoles->setStyleSheet("font-size: 32px; margin-left : 200%;");
    infoLayout->addWidget(PilotsPoles);
    infoLayout->addSpacerItem(new QSpacerItem(40, 80, QSizePolicy::Minimum, QSizePolicy::Expanding));

    mainLayout->addLayout(infoLayout, Qt::AlignCenter);


    ///////////////////////
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    QPushButton *backButtonStatistiques = new QPushButton("Back", this);
    backButtonStatistiques->setProperty("class", "backButtonStatistiques");
    buttonLayout->addWidget(backButtonStatistiques);
    mainLayout->addLayout(buttonLayout);

    connect(backButtonStatistiques, &QPushButton::clicked, this, &Statistiques::backModeSelect);
}

void Statistiques::backModeSelect() {
    emit backButtonModeClicked();
}

