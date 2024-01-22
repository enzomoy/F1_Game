#ifndef CIRCUIT_INFO_H
#define CIRCUIT_INFO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "config.h"
#include "pilots_fonctions.h"
#include "start.h"
#include "settings.h"
#include "statistiques.h"
#include "courses.h"
#include "circuit.h"

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
    QPushButton *backButtonCircuitInfo;

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif