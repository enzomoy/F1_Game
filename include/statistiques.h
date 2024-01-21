#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include "../include/pilots_fonctions.h"

class Statistiques : public QWidget {
Q_OBJECT
public:
    explicit Statistiques(QWidget *parent = nullptr);

signals:
    void backButtonModeClicked();

private:
    QVBoxLayout *mainLayout;
    QVBoxLayout *nameLayout;
    QVBoxLayout *infoLayout;
    QVBoxLayout *buttonLayout;
    QLabel *PilotsName;
    QLabel *PilotsRaces;
    QLabel *PilotsWin;
    QLabel *PilotsLaps;
    QLabel *PilotsPoints;
    QLabel *PilotsPodiums;
    QLabel *PilotsPoles;


private slots:
    void backModeSelect();
};

#endif
