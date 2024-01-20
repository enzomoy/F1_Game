#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "config.h"

class Menu;

class Circuit : public QWidget {
Q_OBJECT
public:
    explicit Circuit(QWidget *parent = nullptr);

signals:
    void buttonCircuitBackClick();
    void buttonStatistiquesClick();

private slots:

private:
    QVBoxLayout *layout;
    QPushButton *backButtonCircuit;
    QPushButton *buttonCourses;
    QPushButton *buttonStatistiques;
    QLabel *pilotsName;
    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // CIRCUIT_H
