#ifndef SIGNALSLOT_H
#define SIGNALSLOT_H

#include <QObject>

class SignalSlot : public QObject
{
    Q_OBJECT
public:
    explicit SignalSlot(QObject *parent = nullptr);

signals:
    void testSignal();
public slots:
    void testSlot();
};

#endif // SIGNALSLOT_H
