#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class Menu;

class Circuit : public QWidget {
Q_OBJECT
public:
    explicit Circuit(QWidget *parent = nullptr);

signals:
    void buttonCircuitBackClick();

private slots:

private:
    QVBoxLayout *layout;
    QPushButton *circuit1;
    QPushButton *circuit2;
    QPushButton *circuit3;
    QPushButton *backButtonCircuit;
    QPushButton* createButton(const QString &text, QWidget *parent);
};

#endif // CIRCUIT_H
