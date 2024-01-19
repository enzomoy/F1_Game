#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class Statistiques : public QWidget {
Q_OBJECT
public:
    explicit Statistiques(QWidget *parent = nullptr);

signals:
    void backButtonModeClicked();

private:
    QVBoxLayout *layout;

private slots:
    void backModeSelect();
};

#endif
