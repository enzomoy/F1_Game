#ifndef START_H
#define START_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "pilots_fonctions.h"

class Start : public QWidget {
Q_OBJECT
public:
    explicit Start(QWidget *parent = nullptr);

signals:
    void backClicked();

private slots:
    void buttonBackClick();

private:
    QVBoxLayout *layout;
    QLabel *label;
    QPushButton *backButton;
    QPushButton *driversButton;

    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // START_H
