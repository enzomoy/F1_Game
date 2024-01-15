// menu.cpp
#include "../include/menu.h"
#include <QFile>

Menu::Menu(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    stackedWidget = new QStackedWidget(this);
    startWidget = new Start(stackedWidget);
    circuitWidget = new Circuit(stackedWidget);

    // Créez d'abord l'objet settingsWidget
    settingsWidget = new Settings(stackedWidget);

    // Connectez ensuite le signal applied
    connectSignals();

    QWidget *menuWidget = new QWidget(this);
    QVBoxLayout *menuLayout = new QVBoxLayout(menuWidget);

    startButton = createButton("Start", menuWidget);
    startButton->setProperty("class", "startButton");
    connect(startButton, &QPushButton::clicked, this, &Menu::buttonStartClick);

    settingsButton = createButton("Settings", menuWidget);
    settingsButton->setProperty("class", "settingsButton");
    connect(settingsButton, &QPushButton::clicked, this, &Menu::buttonSettingsClick);

    exitButton = createButton("Exit", menuWidget);
    exitButton->setProperty("class", "exitButton");
    connect(exitButton, &QPushButton::clicked, this, &Menu::buttonExitClick);

    menuLayout->addWidget(startButton);
    menuLayout->addWidget(exitButton);

    stackedWidget->addWidget(menuWidget);
    stackedWidget->addWidget(startWidget);
    stackedWidget->addWidget(circuitWidget);
    stackedWidget->addWidget(settingsWidget);

    layout->addWidget(stackedWidget);

    setFixedSize(600, 400);
    setWindowTitle("F1 manager");
    applyStylesheet("../src/css/menu.css");

    connect(startWidget, &Start::backClicked, this, &Menu::buttonBackClick);
    connect(startWidget, &Start::driverSelected, this, &Menu::onDriverSelected);
    connect(settingsWidget, &Settings::backClicked, this, &Menu::buttonBackClick);
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

void Menu::buttonSettingsClick() {
    stackedWidget->setCurrentIndex(3);
}

void Menu::buttonBackClick() {
    stackedWidget->setCurrentIndex(0);
}

void Menu::onDriverSelected(int driverIndex) {
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

void Menu::onSettingsApplied() {
    close();
    show();
}

void Menu::connectSignals() {
    connect(settingsWidget, &Settings::applied, this, &Menu::onSettingsApplied);
}
