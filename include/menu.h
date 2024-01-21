#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QFile>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QApplication>
#include "start.h"
#include "circuit.h"
#include "settings.h"
#include "statistiques.h"
#include "config.h"
#include "courses.h"
#include "circuit_info.h"

class Menu : public QWidget {
Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);

private slots:
    void buttonStartClick();
    void buttonSettingsClick();
    void buttonExitClick();
    void buttonBackClick();
    void onDriverSelected(int driverIndex);
    void buttonCircuitBackClick();
    void onSettingsApplied();
    void buttonStatistiquesClick();
    void buttonStatistiquesBackClick();
    void onDriverButtonClickedInStart(int driverIndex);
    void buttonCoursesClick();
    void buttonCoursesBackClick();
    void buttonCoursesInfoClick();
    void buttonCoursesInfoBackClick();

private:
    QVBoxLayout *layout;
    QStackedWidget *stackedWidget;
    QPushButton *startButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
    Start *startWidget;
    Circuit *circuitWidget;
    Statistiques *statistiquesWidget;
    Settings *settingsWidget;
    Courses *coursesWidget;
    CircuitInfo *circuitInfoWidget;

    QPushButton* createButton(const QString &text, QWidget *parent);
    void applyStylesheet(const QString &path);
    void connectSignals();

signals:
    void onDriverButtonClicked(int driverIndex);
};

#endif // MENU_H
