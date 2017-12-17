#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

signals:
    void changeSettings();

private slots:
    void buttonClicked(QAbstractButton*);

private:
    Ui::SettingsDialog *ui;
    bool radiobuttonState = false;
};

#endif // SETTINGSDIALOG_H
