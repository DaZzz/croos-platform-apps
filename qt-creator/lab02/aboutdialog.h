#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QtWidgets>

class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);

private:
    void createFormGroupBox();

    QGroupBox        *formGroupBox;
    QDialogButtonBox *buttonBox;

};

#endif // ABOUTDIALOG_H
