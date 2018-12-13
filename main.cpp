#include "downloader.h"
#include "mylistmodel.h"
#include "coin.h"
#include "myproxymodel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    auto myListModel = new MyListModel();
    Downloader myDownloader;
    myDownloader.setModelName(myListModel);

    qDebug() << "listModel->rowCount" << myListModel->rowCount();


    app.setWindowIcon(QIcon("qrc:/dolar.png"));

    auto myProxyModel = new MyProxyModel(myListModel);

    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty(QStringLiteral("myDownloader"), &myDownloader);
    engine.rootContext()->setContextProperty(QStringLiteral("myListModel"), myListModel);
    engine.rootContext()->setContextProperty("MyProxyModel", myProxyModel );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
