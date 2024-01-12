#ifndef START_H
#define START_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "pilots_fonctions.h"
#include "circuits_fonctions.h"

class Start : public QWidget {
Q_OBJECT
public:
    explicit Start(QWidget *parent = nullptr);

signals:
    void backClicked();
    void driverSelected(int driverIndex);

private slots:
    void buttonBackClick();
    void onDriverButtonClicked(int driverIndex);

private:
    QVBoxLayout *layout;
    QLabel *label;
    QPushButton *backButton;
    QPushButton *driversButton;

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // START_H
