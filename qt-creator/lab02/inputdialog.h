#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>

class InputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = 0);

private:
    void createFormGroupBox();

    QGroupBox        *formGroupBox;
    QDialogButtonBox *buttonBox;


signals:

public slots:

};

#endif // INPUTDIALOG_H
