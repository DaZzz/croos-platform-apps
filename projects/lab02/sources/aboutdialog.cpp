#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent)
{
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));

    QString string = "<h3>О программе</h3>";
    string.append("<p>Рисователь кружков 0.2.1</p>");

    QLabel *label = new QLabel();
    label->setTextFormat(Qt::RichText);
    label->setText(string);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    layout()->setSizeConstraint( QLayout::SetFixedSize );
}

void AboutDialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox();
    QFormLayout *layout = new QFormLayout;
    QSpinBox *spinBox = new QSpinBox;
    spinBox->setMinimum(1);
    layout->addRow(new QLabel("Количество точек:"), spinBox);
    formGroupBox->setLayout(layout);
}
