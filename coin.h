#ifndef COIN_H
#define COIN_H

#include <QString>

class Coin
{
public:
    Coin();
    Coin(const QString &name, const QString &shortName, const double &rate);

    QString name() const;
    QString shortName() const;
    double rate() const;
    QString rateDifference() const;
    void setName(QString name);
    void setShortName(QString shortName);
    void setRate(double rate);
    void setRateDifference(QString rateDifference);

private:
    QString mNama;
    QString mShortName;
    double mRate;
    QString mRateDifference;

//public slots:
};

#endif // COIN_H
