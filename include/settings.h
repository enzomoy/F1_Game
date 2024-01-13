#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>

class Settings : public QWidget {
Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    bool isCheckBoxChecked() const;
    QString getXlen() const;
    QString getYlen() const;

public slots:
    void buttonBackClick();

signals:
    void backClicked();

private:
    QVBoxLayout *layout;
    QPushButton* createButton(const QString &text, QWidget *parent);
    QCheckBox* createCheckBox(const QString &labelText);
    QPushButton *apply;
    QLineEdit* Xlen;
    QLineEdit* Ylen;
};

#endif
