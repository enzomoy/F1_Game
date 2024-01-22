#include "../include/courses.h"
#include "../include/circuit_info.h"
#include <QFrame>


Courses::Courses(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainlayout = new QVBoxLayout(this);

    CircuitData circuits[CIRCUITS_NUMBER];
    if (initAllCircuits(circuits) != 0) {
        printf("Erreur lors de la récupération des circuits\n");
    }

    int lenx = globalConfig.width / 10;
    int x = lenx;

    int leny = globalConfig.height / 6;
    int y = leny;

    for (int i = 0; i < 20; i++) {
        coursesButton = createButton(circuits[i].nom, this);
        coursesButton->setProperty("class", "coursesButton");
        coursesButton->setGeometry(x, y, globalConfig.width/7 , globalConfig.height / 15);
        x += globalConfig.width / 6;
        mainlayout->addWidget(coursesButton);
        if (x > globalConfig.width - globalConfig.width/6) {
            x = lenx;
            y += leny;
        }

        connect(coursesButton, &QPushButton::clicked, [this, i]() {
            saveCirsuit(i);
            onCoursesInfoButtonClick();
        });
    }

    QVBoxLayout *backBoutton = new QVBoxLayout(this);
    backButtonCourses = createButton("Back", this);
    backButtonCourses->setProperty("class", "buttonCoursesBackClick");
    backBoutton->addWidget(backButtonCourses);
    mainlayout->addLayout(backBoutton);

    connect(backButtonCourses, &QPushButton::clicked, this, &Courses::buttonCoursesBackClick);

}

QPushButton* Courses::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

void Courses::onCoursesInfoButtonClick() {
    emit coursesInfoButtonClicked();
}
