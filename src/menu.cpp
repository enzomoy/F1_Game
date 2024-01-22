#include "../include/menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent) {

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
    statistiquesWidget = new Statistiques(stackedWidget);
    settingsWidget = new Settings(stackedWidget);
    coursesWidget = new Courses(stackedWidget);
    circuitInfoWidget = new CircuitInfo(stackedWidget);
    circuitWidget = new Circuit(stackedWidget);

    connectSignals();

    QWidget *menuWidget = new QWidget(this);
    QVBoxLayout *menuLayout = new QVBoxLayout(menuWidget);

    startButton = createButton("Select Pilots", menuWidget);
    startButton->setProperty("class", "startButton");
    startButton->setStyleSheet("    padding: 15px 32px;\n"
                               "    text-align: center;\n"
                               "    font-size: 16px;\n"
                               "    margin: 4px 2px;\n"
                               "    margin-left: 20%;\n"
                               "    margin-right: 20%;");
    connect(startButton, &QPushButton::clicked, this, &Menu::buttonStartClick);

    settingsButton = createButton("Settings", menuWidget);
    settingsButton->setProperty("class", "settingsButton");
    connect(settingsButton, &QPushButton::clicked, this, &Menu::buttonSettingsClick);

    exitButton = createButton("Exit", menuWidget);
    exitButton->setProperty("class", "exitButton");
    exitButton->setStyleSheet("    padding: 15px 32px;\n"
                              "    text-align: center;\n"
                              "    font-size: 16px;\n"
                              "    margin: 4px 2px;\n"
                              "    margin-left: 20%;\n"
                              "    margin-right: 20%;\n"
                              "    background-color: lightcoral;");
    connect(exitButton, &QPushButton::clicked, this, &Menu::buttonExitClick);

    menuLayout->addWidget(startButton);
    menuLayout->addWidget(exitButton);

    stackedWidget->addWidget(menuWidget);
    stackedWidget->addWidget(startWidget);
    stackedWidget->addWidget(settingsWidget);


    layout->addWidget(stackedWidget);

    ////////////////////////////
    //applyStylesheet("../src/style.css");

    connect(startWidget, &Start::backClicked, this, &Menu::buttonBackClick);
    connect(startWidget, &Start::driverSelected, this, &Menu::onDriverSelected);
    connect(startWidget, &Start::driverButtonClicked, this, &Menu::onDriverButtonClicked);
    connect(startWidget, &Start::driverButtonClicked, circuitWidget, &Circuit::setSelectedDriverId);
    connect(settingsWidget, &Settings::backClicked, this, &Menu::buttonBackClick);
    connect(circuitInfoWidget, &CircuitInfo::buttonCoursesInfoBackClick, this, &Menu::buttonCoursesInfoBackClick);;
}

void Menu::buttonStartClick() {
    stackedWidget->setCurrentWidget(startWidget);
}

void Menu::buttonExitClick() {
    qApp->quit();
}

void Menu::buttonSettingsClick() {
    stackedWidget->setCurrentWidget(settingsWidget);
}

void Menu::buttonStatistiquesBackClick() {
    stackedWidget->removeWidget(statistiquesWidget);
    delete statistiquesWidget;
    stackedWidget->setCurrentWidget(circuitWidget);
}

void Menu::buttonBackClick() {
    stackedWidget->setCurrentIndex(0);
}

void Menu::onDriverSelected(int driverIndex) {
    circuitWidget = new Circuit(stackedWidget);
    stackedWidget->addWidget(circuitWidget);

    connect(circuitWidget, &Circuit::buttonCircuitBackClick, this, &Menu::buttonCircuitBackClick);
    connect(circuitWidget, &Circuit::buttonStatistiquesClick, this, &Menu::buttonStatistiquesClick);
    connect(circuitWidget, &Circuit::buttonCoursesClick, this, &Menu::buttonCoursesClick);
    stackedWidget->setCurrentWidget(circuitWidget);
}

void Menu::buttonCoursesBackClick() {
    stackedWidget->setCurrentWidget(circuitWidget);
}

void Menu::buttonCircuitBackClick() {
    if (removePlayer() == 1) {
        printf("Erreur lors de la suppression du joueur");
    }
    stackedWidget->setCurrentWidget(startWidget);
}

void Menu::buttonStatistiquesClick(){

    statistiquesWidget = new Statistiques(stackedWidget);
    stackedWidget->addWidget(statistiquesWidget);
    connect(statistiquesWidget, &Statistiques::backButtonModeClicked, this, &Menu::buttonStatistiquesBackClick);

    stackedWidget->setCurrentWidget(statistiquesWidget);
}

////////////
void Menu::buttonCoursesClick() {

    coursesWidget = new Courses(stackedWidget);
    stackedWidget->addWidget(coursesWidget);

    connect(coursesWidget, &Courses::coursesInfoButtonClicked, this, &Menu::buttonCoursesInfoClick);
    connect(coursesWidget, &Courses::buttonCoursesBackClick, this, &Menu::buttonCoursesBackClick);

    stackedWidget->setCurrentWidget(coursesWidget);
}
//////////////
void Menu::buttonCoursesInfoClick() {

    circuitInfoWidget = new CircuitInfo(stackedWidget);
    stackedWidget->addWidget(circuitInfoWidget);

    connect(circuitInfoWidget, &CircuitInfo::buttonCoursesInfoBackClick, this, &Menu::buttonCoursesInfoBackClick);

    stackedWidget->setCurrentWidget(circuitInfoWidget);
}

void Menu::buttonCoursesInfoBackClick() {

    stackedWidget->removeWidget(circuitInfoWidget);
    delete circuitInfoWidget;

    stackedWidget->setCurrentWidget(coursesWidget);
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
    connect(startWidget, &Start::driverButtonClicked, this, &Menu::onDriverButtonClickedInStart);
}

void Menu::onDriverButtonClickedInStart(int driverIndex) {
    circuitWidget->setSelectedDriverId(driverIndex);
}
