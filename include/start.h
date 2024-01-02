#ifndef START_H
#define START_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

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

    QPushButton* createButton(const QString &text, QWidget *parent);  // Ajout de la déclaration
};

#endif // START_H
