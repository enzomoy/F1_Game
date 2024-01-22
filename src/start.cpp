/*
 * Fichier : start.cpp
 * Description: Fichier source de start.h
 */

#include "../include/start.h"
#include "../include/pilots_fonctions.h"

Start::Start(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    label = new QLabel("Select your driver", this);
    label->setProperty("class", "selectDrivers");
    label->setStyleSheet("    text-align: center;\n"
                         "    margin-bottom: 400px;\n"
                         "    margin-left: 350%;");

    backButton = createButton("Back", this);
    backButton->setProperty("class", "backButton");
    backButton->setStyleSheet("    padding: 15px 32px;\n"
                               "    text-align: center;\n"
                               "    font-size: 16px;\n"
                               "    margin: 4px 2px;\n"
                               "    margin-left: 20%;\n"
                               "    margin-right: 20%;\n"
                               "    background-color: lightcoral;");

    int lenx = globalConfig.width / 10;
    int x = lenx;

    int leny = globalConfig.height / 6;
    int y = leny;

    Pilots driversData[DRIVERS_NUMBER];
    if (initAllDrivers(driversData) == 1) {
        printf("Erreur lors de la récupération des pilotes\n");
    }


    for (int i = 0; i < 20; i++) {
        driversButton = createButton(driversData[i].nom, this);
        driversButton->setProperty("class", "driversButton");
        driversButton->setGeometry(x, y, globalConfig.width/7 , globalConfig.height / 15);
        driversButton->setStyleSheet("    background-color: grey;\n"
                                     "    border-radius: 5%;");
        x += globalConfig.width / 6;
        if (x > globalConfig.width - globalConfig.width/6) {
            x = lenx;
            y += leny;
        }
        connect(driversButton, &QPushButton::clicked, this, [this, i, driversData]() {
            savePilot(i);
            if (addPlayer(driversData[i].nom, 0) == 1) {
                printf("Erreur lors de l'ajout du joueur\n");
            }
            onDriverButtonClicked(i);
        });
    }

    layout->addWidget(label);
    layout->addWidget(backButton);
    if (&QPushButton::clicked) {
        connect(backButton, &QPushButton::clicked, this, &Start::buttonBackClick);
    }

//    const char *url = "http://ergast.com/api/f1/2019/drivers.json";
//    if (perform_request(url) == 1) {
//        printf("Erreur lors de la requête CURL\n");
//    }

}
void Start::buttonBackClick() {
    emit backClicked();
}

QPushButton* Start::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

void Start::onDriverButtonClicked(int driverIndex) {
    emit driverButtonClicked(driverIndex);
    emit driverSelected(driverIndex);
}
