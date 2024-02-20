#include <QCoreApplication>
#include "dbusservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Create the D-Bus service
    DbusService service;
    service.regFormat("txt","gedit");
    // Start the event loop
    return app.exec();
}
