#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>
#include "downloader.h"
#include "qlistmodel.h"
#include "coin.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Downloader currencies;

    app.setWindowIcon(QIcon("F:/QtProjects/CurrencyRate/dolar.png"));

    QQmlApplicationEngine engine;

    qmlRegisterType<QListModel>("QListModel", 1, 0, "QListModel");
    qmlRegisterType<Coin>("Coin", 1, 0, "Coin");

    engine.rootContext()->setContextProperty(QStringLiteral("MyCurrencies"), &currencies);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
