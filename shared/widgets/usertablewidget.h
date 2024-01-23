#ifndef USERTABLEWIDGET_H
#define USERTABLEWIDGET_H

#include <QTableWidget>
#include <set>

class User;
class RemoveButton;

class UserTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    UserTableWidget(QWidget *parent = nullptr);
    virtual ~UserTableWidget() {}
    void populate();
    void appendUser(const User *newUser);
    void enableEdition(bool enabled);
    bool editionEnabled() const { return m_editionEnabled; }
    void saveUpdatedRows();
protected:
    bool event(QEvent *event) override;
private slots:
    void removeUser(RemoveButton *button);
private:
    void init();

    bool m_editionEnabled;
    std::set<int> m_updatedRowList;
};

#endif // USERTABLEWIDGET_H
