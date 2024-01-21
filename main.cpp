#include "shared/constants.h"
#include "shared/databasehandler.h"
#include "views/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
    app.setApplicationName(APPLICATION_NAME);
    app.setApplicationVersion(APPLICATION_VERSION);
    app.setOrganizationName(ORGANIZATION_NAME);
    app.setOrganizationDomain(ORGANIZATION_DOMAIN);
    DatabaseHandler databaseHandler;
    databaseHandler.init();
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
