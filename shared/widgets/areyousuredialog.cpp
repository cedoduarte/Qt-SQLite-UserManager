#include "areyousuredialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>

AreYouSureDialog::AreYouSureDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Continue");
    m_vbox = new QVBoxLayout;
    m_messageLabel = new QLabel("Are you sure to continue?", this);
    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    m_vbox->addWidget(m_messageLabel);
    m_vbox->addWidget(m_buttonBox);
    setLayout(m_vbox);
    connect(m_buttonBox, &QDialogButtonBox::accepted, this, &AreYouSureDialog::accept);
    connect(m_buttonBox, &QDialogButtonBox::rejected, this, &AreYouSureDialog::reject);
}

