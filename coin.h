#ifndef COIN_H
#define COIN_H

#include <QObject>

class Coin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString shortName READ shortName WRITE setShortName NOTIFY shortNameChanged)
    Q_PROPERTY(QString rate READ rate WRITE setRate NOTIFY rateChanged)

public:
    explicit Coin(QObject *parent = nullptr);

    QString name() const;
    QString shortName() const;
    QString rate() const;
    void setName(QString name);
    void setShortName(QString shortName);
    void setRate(QString rate);

signals:
    void nameChanged(QString name);
    void shortNameChanged(QString shortName);
    void rateChanged(QString rate);

private:
    QString mNama;
    QString mShortName;
    QString mRate;

public slots:
};

#endif // COIN_H
