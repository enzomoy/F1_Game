#include "../include/menu.h"
#include <QFile>
#include "../include/circuit.h"

Menu::Menu(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    stackedWidget = new QStackedWidget(this);
    startWidget = new Start(stackedWidget);
    circuitWidget = new Circuit(stackedWidget);

    if (dbConnect(&globalDbConnection) == 1) {
        printf("Erreur de connexion à la base de données");
        exit(1);
    }

    QWidget *menuWidget = new QWidget(this);
    QVBoxLayout *menuLayout = new QVBoxLayout(menuWidget);

    startButton = createButton("Start", menuWidget);
    startButton->setProperty("class", "startButton");
    connect(startButton, &QPushButton::clicked, this, &Menu::buttonStartClick);

    exitButton = createButton("Exit", menuWidget);
    exitButton->setProperty("class", "exitButton");
    connect(exitButton, &QPushButton::clicked, this, &Menu::buttonExitClick);

    menuLayout->addWidget(startButton);
    menuLayout->addWidget(exitButton);

    stackedWidget->addWidget(menuWidget);
    stackedWidget->addWidget(startWidget);
    stackedWidget->addWidget(circuitWidget);

    layout->addWidget(stackedWidget);

    setFixedSize(600, 400);
    setWindowTitle("F1 manager");
    applyStylesheet("../src/css/menu.css");

    connect(startWidget, &Start::backClicked, this, &Menu::buttonBackClick);
    connect(startWidget, &Start::driverSelected, this, &Menu::onDriverSelected);

    connect(circuitWidget, &Circuit::buttonCircuitBackClick, this, &Menu::buttonCircuitBackClick);
}

void Menu::createPage(const QString &title, int width, int height) {
    QWidget *page = startWidget;
    page->setFixedSize(width, height);
    setWindowTitle(title);
}

void Menu::buttonStartClick() {
    stackedWidget->setCurrentIndex(1);
}

void Menu::buttonExitClick() {
    qApp->quit();
}

void Menu::buttonBackClick() {
    stackedWidget->setCurrentIndex(0);
}

void Menu::onDriverSelected(int driverIndex) {
    selectPilot(driverIndex);
    stackedWidget->setCurrentIndex(2);
}

void Menu::buttonCircuitBackClick() {
    stackedWidget->setCurrentIndex(1);
}

QPushButton* Menu::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

void Menu::applyStylesheet(const QString &path) {
    QFile styleFile(path);
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&styleFile);
        QString styleSheet = stream.readAll();
        setStyleSheet(styleSheet);
        styleFile.close();
    }
}
