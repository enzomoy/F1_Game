#include "../include/menu.h"
#include <QFile>

Menu::Menu(QWidget *parent) : QWidget(parent) {

    // Initialisation de la bdd
    if (dbConnect(&globalDbConnection) == 1) {
        printf("Erreur de connexion à la base de donnees");
        exit(1);
    }

    switch(createConfig()){
        case 1:
            printf("le fichier n'a pas pu être cree");
            exit(1);
        case 2:
            printf("les lignes par defaut n'ont pas pu etre ajoutees");
            exit(1);
        default:
            break;
    }

    if(readConfiguration(&globalConfig) == 1){
        printf("Erreur de lecture du fichier de configuration");
        exit(1);
    }

    if (globalConfig.fullscreen == 1){
        showFullScreen();
    }else{
        setFixedSize(globalConfig.width, globalConfig.height);
    }

    setWindowTitle("F1 manager");
    layout = new QVBoxLayout(this);
    stackedWidget = new QStackedWidget(this);
    startWidget = new Start(stackedWidget);
    circuitWidget = new Circuit(stackedWidget);
    statistiquesWidget = new Statistiques(stackedWidget);
    settingsWidget = new Settings(stackedWidget);

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
    stackedWidget->addWidget(statistiquesWidget);

    layout->addWidget(stackedWidget);
    applyStylesheet("../src/css/menu.css");

    connect(startWidget, &Start::backClicked, this, &Menu::buttonBackClick);
    connect(startWidget, &Start::driverSelected, this, &Menu::onDriverSelected);
    connect(settingsWidget, &Settings::backClicked, this, &Menu::buttonBackClick);
    connect(circuitWidget, &Circuit::buttonCircuitBackClick, this, &Menu::buttonCircuitBackClick);
    connect(circuitWidget, &Circuit::buttonStatistiquesClick, this, &Menu::buttonStatistiquesClick);
    connect(statistiquesWidget, &Statistiques::backButtonModeClicked, this, &Menu::buttonStatistiquesBackClick);

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

void Menu::buttonStatistiquesBackClick() {
    stackedWidget->setCurrentIndex(2);
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

void Menu::buttonStatistiquesClick(){
    stackedWidget->setCurrentIndex(4);
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
    Menu menu;
    if (globalConfig.fullscreen == 1){
        showFullScreen();
    }else{
        showNormal();
        setFixedSize(globalConfig.width, globalConfig.height);
    }
    show();
}

void Menu::connectSignals() {
    connect(settingsWidget, &Settings::applied, this, &Menu::onSettingsApplied);
}

