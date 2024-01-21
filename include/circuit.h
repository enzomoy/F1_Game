#ifndef CIRCUIT_H
#define CIRCUIT_H

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

class Circuit : public QWidget {
Q_OBJECT
public:
    explicit Circuit(QWidget *parent = nullptr);

signals:
    void buttonCircuitBackClick();
    void buttonStatistiquesClick();
    void buttonCoursesClick();

public slots:
    void setSelectedDriverId(int driverId);

private:
    QVBoxLayout *layout;
    QVBoxLayout *PilotsInfo;
    QPushButton *backButtonCircuit;
    QPushButton *buttonCourses;
    QPushButton *buttonStatistiques;
    QLabel *PilotsName;
    int selectedDriverId;

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // CIRCUIT_H
