#include "debug_p.hpp"
#include <qqml.h>

Debug::Debug(QObject* parent)
    : QObject{parent}
    , d_ptr(new DebugPrivate(this))
{

}

void Debug::append(const QString& message)
{
    Q_D(Debug);
    emit (d->appendSignal(message));
}

/****************************************************************************************************************************************************************
███████████████████████████          🔒 PRIVATE IMPLEMENTATION 🔒          ███████████████████████████████──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────f
*****************************************************************************************************************************************************************/

DebugPrivate::DebugPrivate(Debug* parent)
    : QObject{parent}
    , q_ptr(parent)
{
    qmlRegisterSingletonInstance("DebugConsoleImpl", 1, 0, "Impl", this);
}
