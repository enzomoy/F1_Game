#ifndef COURSES_H
#define COURSES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "circuits_fonctions.h"
#include "config.h"

class Courses : public QWidget {
Q_OBJECT

public:
    Courses(QWidget *parent = nullptr);

signals:
    void buttonCoursesBackClick();

private:
    QVBoxLayout *mainlayout;
    QVBoxLayout *backBoutton;
    QPushButton *backButtonCourses;
    QPushButton *coursesButton;

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // COURSES_H