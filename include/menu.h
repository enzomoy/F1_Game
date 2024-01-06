#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QApplication>
#include "start.h"


class Circuit;

class Menu : public QWidget {
Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    void createPage(const QString &title, int width, int height);

private slots:
    void buttonStartClick();
    void buttonExitClick();
    void buttonBackClick();
    void onDriverSelected(int driverIndex);
    void buttonCircuitBackClick();

private:
    QVBoxLayout *layout;
    QStackedWidget *stackedWidget;
    QPushButton *startButton;
    QPushButton *exitButton;
    Start *startWidget;
    Circuit *circuitWidget;

    QPushButton* createButton(const QString &text, QWidget *parent);
    void applyStylesheet(const QString &path);
};

#endif
