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
    QSpinBox         *spinBox;

signals:
    void pointsNumberChanged(int);

public slots:
    void onAccept();
};

#endif // INPUTDIALOG_H
