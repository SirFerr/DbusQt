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
#include <QFileInfo>


class DbusService : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.example.IDbusService")

public:
    explicit DbusService(QObject *parent);

public slots:
    void regFormat(const QString &format ,const QString &launchMethod);
    QString getLaunch(const QString &fileName);
    void launchApp(const QString &fileName);

private:
    QMap<QString, QString> m_formats;
};

#endif // DBUSSERVICE_H
