/*
 * Fichier : courses.h
 * Description: Fichier d'en-tête de courses.cpp
 */

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
    void coursesInfoButtonClicked();

private:
    QVBoxLayout *mainlayout;
    QVBoxLayout *backBoutton;
    QPushButton *backButtonCourses;
    QPushButton *coursesButton;

private slots:
    void onCoursesInfoButtonClick();

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // COURSES_H
