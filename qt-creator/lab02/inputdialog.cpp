#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent)
{
    createFormGroupBox();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    layout()->setSizeConstraint( QLayout::SetFixedSize );

    setWindowTitle(tr("Входные параматры"));
}

void InputDialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox();
    QFormLayout *layout = new QFormLayout;
    QSpinBox *spinBox = new QSpinBox;
    spinBox->setMinimum(1);
    layout->addRow(new QLabel("Количество точек:"), spinBox);
    formGroupBox->setLayout(layout);
}
