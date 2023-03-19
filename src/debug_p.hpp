#pragma once

#include "../include/debug.hpp"

class DebugPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Debug)
public:
    DebugPrivate(Debug* parent);
    virtual ~DebugPrivate() = default;

    signals:
    void appendSignal(const QString& text);

private:
    Debug* q_ptr;
};
