#include "downloader.h"
#include "mylistmodel.h"
#include "coin.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    MyListModel myListModel;
    Downloader myDownloader;
    myDownloader.setModelName(&myListModel);

//    Coin coin("name", "sname", "rate");
    myListModel.addCoin(Coin("name", "sname", "rate"));
//    myListModel.addCoin(Coin("1name", "1sname", "1rate"));
//    Coin coin = new Coin("qq", "ww", "ee");
//    myListModel(coin);

    app.setWindowIcon(QIcon("F:/QtProjects/CurrencyRate/dolar.png"));

    QQmlApplicationEngine engine;

//    qmlRegisterType<QListModel>("QListModel", 1, 0, "QListModel");
//    qmlRegisterType<Downloader>("Downloader", 1, 0, "Downloader");


    engine.rootContext()->setContextProperty(QStringLiteral("MyDownloader"), &myDownloader);
    engine.rootContext()->setContextProperty(QStringLiteral("myListModel"), &myListModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
