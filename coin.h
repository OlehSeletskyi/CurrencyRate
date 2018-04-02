#ifndef COIN_H
#define COIN_H

#include <QString>

class Coin
{
public:
    Coin();
    Coin(const QString &name, const QString &shortName, const QString &rate);

    QString name() const;
    QString shortName() const;
    QString rate() const;
    void setName(QString name);
    void setShortName(QString shortName);
    void setRate(QString rate);

private:
    QString mNama;
    QString mShortName;
    QString mRate;

//public slots:
};

#endif // COIN_H
