#include "../include/start.h"

Start::Start(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    label = new QLabel("Select your driver", this);
    label->setProperty("class", "selectDrivers");
    backButton = createButton("Back", this);
    backButton->setProperty("class", "backButton");

    int x = 37;
    int y = 100;
    char **pilots = getAllPilots();
    for (int i = 0; i < 20; i++) {
        printf("%s \n", pilots[i]);
        driversButton = createButton(pilots[i], this);
        driversButton->setProperty("class", "driversButton");
        driversButton->setGeometry(x, y, 99 , 30);
        x += 100;
        if (x > 500) {
            x = 37;
            y += 50;
        }
        connect(driversButton, &QPushButton::clicked, this, &Start::onDriverButtonClicked);
    }

    // Initialisation de la bdd
    if (dbConnect(&globalDbConnection) == 1) {
        printf("Erreur de connexion à la base de données");
        exit(1);
    }
    selectPilot(0);

    layout->addWidget(label);
    layout->addWidget(backButton);
    if (&QPushButton::clicked) {
        connect(backButton, &QPushButton::clicked, this, &Start::buttonBackClick);
    }
}

void Start::buttonBackClick() {
    emit backClicked();
}

QPushButton* Start::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

void Start::onDriverButtonClicked() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton) {
        int driverIndex = senderButton->text().toInt();
        emit driverSelected(driverIndex);
    }
}