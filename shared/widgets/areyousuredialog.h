#ifndef AREYOUSUREDIALOG_H
#define AREYOUSUREDIALOG_H

#include <QDialog>

class QLabel;
class QVBoxLayout;
class QDialogButtonBox;

class AreYouSureDialog : public QDialog
{
    Q_OBJECT
public:
    AreYouSureDialog(QWidget *parent = nullptr);
    virtual ~AreYouSureDialog() {}
private:
    QVBoxLayout *m_vbox;
    QLabel *m_messageLabel;
    QDialogButtonBox *m_buttonBox;
};

#endif // AREYOUSUREDIALOG_H
