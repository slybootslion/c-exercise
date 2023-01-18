#include "signalslot.h"
#include <QtDebug>

SignalSlot::SignalSlot(QObject *parent) : QObject(parent)
{

}

void SignalSlot::testSlot()
{
    qDebug() << "signal slot testSlot()";
}
