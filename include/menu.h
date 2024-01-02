#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QApplication>
#include "start.h"
#include <QFile>
#include <QTextStream>

class Menu : public QWidget {
Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    void createPage(const QString &title, int width, int height);

private slots:
    void buttonStartClick();
    void buttonExitClick();
    void buttonBackClick();

private:
    QVBoxLayout *layout;
    QStackedWidget *stackedWidget;
    QPushButton *startButton;
    QPushButton *exitButton;
    Start *startWidget;

    QPushButton* createButton(const QString &text, QWidget *parent);
    void applyStylesheet(const QString &path);
};

#endif // MENU_H