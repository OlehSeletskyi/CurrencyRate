#include "coin.h"

Coin::Coin()
{
}

Coin::Coin(const QString &name, const QString &shortName, const double &rate)
    : mNama(name), mShortName(shortName), mRate(rate)
{
}

QString Coin::name() const
{
    return mNama;
}

QString Coin::shortName() const
{
    return mShortName;
}

double Coin::rate() const
{
    return mRate;
}
QString Coin::rateDifference() const
{
    return mRateDifference;
}

void Coin::setName(QString name)
{
    if(mNama == name)
    {
        return;
    }
    mNama = name;
//    emit nameChanged(mNama);
}

void Coin::setShortName(QString shortName)
{
    if(mShortName == shortName)
    {
        return;
    }
    mShortName = shortName;
//    emit shortNameChanged(mShortName);
}

void Coin::setRate(double rate)
{
    if(mRate == rate)
    {
        return;
    }
    mRate = rate;
//    emit rateChanged(mRate);
}

void Coin::setRateDifference(QString rateDifference)
{
    if(mRateDifference == rateDifference)
    {
        return;
    }
    mRateDifference = rateDifference;
}
