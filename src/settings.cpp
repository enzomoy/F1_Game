#include "../include/settings.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

Settings::Settings(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    QCheckBox *checkBox = createCheckBox("Fullscreen");
    layout->addWidget(checkBox);

    label1 = new QLabel("X : ", this);
    label1->setProperty("class", "printX");
    layout->addWidget(label1);

    Xlen = new QLineEdit(this);
    Xlen->setProperty("class","Xinput");
    layout->addWidget(Xlen);

    label2 = new QLabel("Y : ", this);
    label2->setProperty("class", "printY");
    layout->addWidget(label2);

    Ylen = new QLineEdit(this);
    Ylen->setProperty("class","Yinput");
    layout->addWidget(Ylen);

    bool isChecked = isCheckBoxChecked();

    apply = createButton("Appliquer", this);
    apply->setProperty("class", "Appliquer");
    layout->addWidget(apply);

    QPushButton *backButtonSettings = createButton("Back", this);
    backButtonSettings->setProperty("class", "backButtonSettings");
    layout->addWidget(backButtonSettings);

    connect(apply, &QPushButton::clicked, this, &Settings::buttonApplyClick);
    connect(backButtonSettings, &QPushButton::clicked, this, &Settings::buttonBackClick);

}

////////////////////////////////////////////////////////////////////////////
QPushButton* Settings::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

QCheckBox* Settings::createCheckBox(const QString &labelText) {
    QCheckBox *checkBox = new QCheckBox(labelText);
    return checkBox;
}

bool Settings::isCheckBoxChecked() const {
    QCheckBox *checkBox = findChild<QCheckBox*>();
    if (checkBox) {
        return checkBox->isChecked();
    }
    return false;
}

QString Settings::getXlen() const {
    return Xlen->text();
}

QString Settings::getYlen() const {
    return Ylen->text();
}

void Settings::buttonApplyClick() {
    emit applied();
}

void Settings::buttonBackClick() {
    emit backClicked();
}