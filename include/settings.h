#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>

class Settings : public QWidget {
Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    bool isCheckBoxChecked() const;
    QString getXlen() const;
    QString getYlen() const;

public slots:
    void buttonApplyClick();
    void buttonBackClick();

signals:
    void backClicked();
    void applied();

private:
    QVBoxLayout *layout;
    QPushButton* createButton(const QString &text, QWidget *parent);
    QCheckBox* createCheckBox(const QString &labelText);
    QPushButton *apply;
    QLineEdit* Xlen;
    QLineEdit* Ylen;
    QLabel *label1;
    QLabel *label2;
};

#endif
