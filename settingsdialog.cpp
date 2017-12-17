#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::clicked, this, &SettingsDialog::buttonClicked);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::buttonClicked(QAbstractButton* button)
{
    if (button->text() == "OK"){
        if (radiobuttonState != ui->radioButton->isChecked()){
            radiobuttonState = !radiobuttonState;
            emit changeSettings();
        }
    }
}
