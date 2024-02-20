#include "dbusservice.h"


DbusService::DbusService(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    QDBusConnection dbus = QDBusConnection::sessionBus();
    if(!dbus.interface()->isServiceRegistered(QStringLiteral("ru.example.SDbusService"))){
            dbus.registerObject(QStringLiteral("/ru/example/ODbusService"),parent);
            dbus.registerService(QStringLiteral("ru.example.SDbusService"));
}
    else {qDebug("not registed");}
}

void DbusService::regFormat(const QString &format ,const QString &launchMethod){
    m_formats[format]=launchMethod;
}

QString DbusService::getLaunch(const QString &fileName)
{
    return m_formats[QFileInfo(fileName).suffix()];
}

void DbusService::launchApp(const QString &fileName){
    QProcess *process = new QProcess(this);
    QStringList arguments;
    arguments<< fileName;
    process ->start(m_formats[QFileInfo(fileName).suffix()],arguments);
}
