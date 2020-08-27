#ifndef BOT_H
#define BOT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QThread>


class Bot : public QObject
{
    Q_OBJECT
public:
    explicit Bot(QObject *parent = nullptr);

signals:
    void onMessage(QString channle, QString sender, QString message); // connected
    void deleteBotThread(); //connect deleteThread to QThread's quit slot DONE
    void writePong(); //connect writePong to MainWindow's writePong slot DONE
    void updateConsoles(QString readLine, QString channel, QString sender, QString message); // connected
    void writeStatusMessage(QString message);
public slots:
    void readyRead();
    void start();
    void sendMessage(QString channel, QString message);
    void updateDelay(int delay);
    void disconnect();
    void disconnected();
    void error();
private:
    void connectBot();
    QTcpSocket *m_socket;
    int m_Delay;
    bool m_ManuallyDisconnected;
};

#endif // BOT_H
