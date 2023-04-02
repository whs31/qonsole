#pragma once

#include <QObject>


/// @brief
#define QONSOLE_DECLARE QONSOLE_DECLARE_PRIVATE

/// @brief
#define QONSOLE_INIT QONSOLE_INIT_PRIVATE

class DebugPrivate;
class Debug : public QObject
{
    Q_OBJECT
public:
    explicit Debug(QObject* parent = nullptr);

    /// @brief
    void append(const QString& message);
protected:
    DebugPrivate* const d_ptr;
private:
    Q_DECLARE_PRIVATE(Debug)

};


















#define QONSOLE_DECLARE_PRIVATE QScopedPointer<Debug> console; \
                        bool _init_ = false; \
                        void consoleHandler(QtMsgType type, const QMessageLogContext&, const QString& msg) \
                        { \
                            QString txt; \
                            int msgt = 0; \
                            switch (type) { \
                            case QtDebugMsg: \
                                txt = QString("%1").arg("<font color=\"#ECEFF4\">" + msg + "</font>"); \
                                msgt = 0; \
                                break; \
                            case QtWarningMsg: \
                                txt = QString("%1").arg("<font color=\"#EBCB8B\">" + msg + "</font>"); \
                                msgt = 2; \
                                break; \
                            case QtInfoMsg: \
                                txt = QString("%1").arg("<font color=\"#8FBCBB\">" + msg + "</font>"); \
                                msgt = 1; \
                                break; \
                            case QtCriticalMsg: \
                                txt = QString("%1").arg("<font color=\"#BF616A\">" + msg + "</font>"); \
                                msgt = 3; \
                                break; \
                            case QtFatalMsg: \
                                txt = QString("%1").arg("<font color=\"#D08770\">" + msg + "</font>"); \
                                msgt = 4; \
                                break; \
                            } \
                            if(_init_) \
                            console->append(txt); }

#define QONSOLE_INIT_PRIVATE console.reset(new Debug()); \
                    _init_ = true; \
                    qInstallMessageHandler(consoleHandler);
