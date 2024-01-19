#include "../include/statistiques.h"
#include <QPushButton>

Statistiques::Statistiques(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    QPushButton *backButtonStatistiques = new QPushButton("Back", this);
    backButtonStatistiques->setProperty("class", "backButtonStatistiques");
    layout->addWidget(backButtonStatistiques);

    connect(backButtonStatistiques, &QPushButton::clicked, this, &Statistiques::backModeSelect);
}

void Statistiques::backModeSelect() {
    emit backButtonModeClicked();
}
