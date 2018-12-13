#include "coin.h"

Coin::Coin()
{
}

Coin::Coin(const QString &name, const QString &shortName, const QString &rate)
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

QString Coin::rate() const
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
}

void Coin::setShortName(QString shortName)
{
    if(mShortName == shortName)
    {
        return;
    }
    mShortName = shortName;
}

void Coin::setRate(QString rate)
{
    if(mRate == rate)
    {
        return;
    }
    mRate = rate;
}

void Coin::setRateDifference(QString rateDifference)
{
    if(mRateDifference != rateDifference)
    {
        return;
    }
    mRateDifference = rateDifference;
}
