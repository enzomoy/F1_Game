#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QApplication>
#include "start.h"
#include "circuit.h"
#include "settings.h"

class Menu : public QWidget {
Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    void createPage(const QString &title, int width, int height);

private slots:
    void buttonStartClick();
    void buttonSettingsClick();
    void buttonExitClick();
    void buttonBackClick();
    void onDriverSelected(int driverIndex);
    void buttonCircuitBackClick();

private:
    QVBoxLayout *layout;
    QStackedWidget *stackedWidget;
    QPushButton *startButton;
    QPushButton *settingsButton;
    QPushButton *exitButton;
    Start *startWidget;
    Circuit *circuitWidget;
    Settings *settingsWidget;

    QPushButton* createButton(const QString &text, QWidget *parent);
    void applyStylesheet(const QString &path);
};

#endif
