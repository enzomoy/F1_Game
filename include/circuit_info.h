/*
 * Fichier : circuit_info.h
 * Description: Fichier d'en-tête de circuit_info.cpp
 */

#ifndef CIRCUIT_INFO_H
#define CIRCUIT_INFO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "config.h"
#include "pilots_fonctions.h"
#include "circuit_info.h"
#include "start.h"
#include "settings.h"
#include "statistiques.h"
#include "courses.h"
#include "circuit.h"
#include "circuits_fonctions.h"

class CircuitInfo : public QWidget {
Q_OBJECT
public:
    explicit CircuitInfo(QWidget *parent = nullptr);

signals:
    void buttonCoursesInfoBackClick();

public slots:
    void onBackButtonCircuitInfoClick();

private:
    QVBoxLayout *layout;
    QVBoxLayout *mainLayout;
    QVBoxLayout *infoCircuit;
    QVBoxLayout *backButton;
    QPushButton *backButtonCircuitInfo;
    QLabel *CircuitName;
    QLabel *CircuitPays;
    QLabel *CircuitTours;
    QLabel *CircuitLen;
    QLabel *CircuitType;
    QLabel *CircuitLeft;
    QLabel *CircuitRight;
    QLabel *CircuitDrs;

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif