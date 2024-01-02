#include "../include/menu.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>

Menu::Menu(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *label = new QLabel(this);
    label->setFixedSize(600, 800);

    mainLayout->addWidget(label);
    mainLayout->addStretch();
    setLayout(mainLayout);

    QFile styleFile("../src/css/menu.css");

    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream textStream(&styleFile);
        QString styleSheet = textStream.readAll();
        setStyleSheet(styleSheet);
        styleFile.close();
    }
}


void Menu::createPage(const QString &nomFenetre, int hauteur, int largeur) {
    QLabel *label = qobject_cast<QLabel*>(layout()->itemAt(0)->widget());
    if (label) {
        label->setFixedSize(largeur, hauteur);
        setWindowTitle(nomFenetre);
        ShowMenu();
    }
}

void Menu::ShowMenu() {
    createBoutonStart();
    createBoutonSettings();
    createBoutonExit();
}

void Menu::createBoutonExit() {
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());

    QHBoxLayout *exitLayout = new QHBoxLayout;
    exitLayout->addStretch();
    QPushButton *exitButton = new QPushButton("Exit", this);
    exitButton->setObjectName("exitButton");
    exitLayout->addWidget(exitButton);

    mainLayout->addLayout(exitLayout);

    connect(exitButton, &QPushButton::clicked, this, &Menu::close);
}

void Menu::createBoutonStart() {
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());

    QHBoxLayout *startLayout = new QHBoxLayout;
    startLayout->addStretch();
    QPushButton *startButton = new QPushButton("Start", this);
    startButton->setObjectName("startButton");
    startLayout->addWidget(startButton);

    mainLayout->addLayout(startLayout);

    connect(startButton, &QPushButton::clicked, this, &Menu::close);
}

void Menu::createBoutonSettings() {
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());

    QHBoxLayout *settingsLayout = new QHBoxLayout;
    settingsLayout->addStretch();
    QPushButton *settingsButton = new QPushButton("Settings", this);
    settingsButton->setObjectName("settingsButton");
    settingsLayout->addWidget(settingsButton);

    mainLayout->addLayout(settingsLayout);

    connect(settingsButton, &QPushButton::clicked, this, &Menu::close);
}
