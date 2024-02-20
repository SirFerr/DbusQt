#include "dbusservice.h"

DbusService::DbusService(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    QDBusConnection dbusConnection = QDBusConnection::sessionBus();
    if(!dbusConnection.interface()->isServiceRegistered(QStringLiteral("org.example.DbusService"))){
            dbusConnection.registerObject(QStringLiteral("/org/example/DbusService"),parent);
            dbusConnection.registerService(QStringLiteral("org.example.DbusService"));
}
}

void DbusService::regFormat(const QString &format ,const QString &launchMethod){
    m_formats[format]=launchMethod;
    qDebug()<<m_formats[format];

}

void DbusService::openFile(const QString &fileName)
{
    qDebug()<<fileName;
}
