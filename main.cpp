#include <QCoreApplication>
#include "dbusservice.h"

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    DbusService service(&app);
    service.regFormat("txt","clion");
    qDebug()<<service.getLaunch("hello.txt");
//    service.launchApp("/home/ferr/dbusService/hello.txt");

    return app.exec();
}

