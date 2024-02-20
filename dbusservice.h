#ifndef DBUSSERVICE_H
#define DBUSSERVICE_H

#include <QtDBus/QDBusAbstractAdaptor>
#include <QtCore/QCoreApplication>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>
#include <QProcess>
#include<QDebug>

class DbusService : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.DbusService")

public:
    explicit DbusService(QObject *parent = nullptr);

public slots:
    void regFormat(const QString &format ,const QString &launchMethod);
    void openFile(const QString &fileName);

private:
    QMap<QString, QString> m_formats;
};

#endif // DBUSSERVICE_H
