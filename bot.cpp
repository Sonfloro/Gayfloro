#include "bot.h"
#include "messageparser.h"

// TODO: Program will crash if you try to diconnect too quickly after connecting (need about a second of delay)
//       Figure out how to get user lists and mod lists
//       Add a custom delay for if the same command is being spammed
//
Bot::Bot(QObject *parent) : QObject(parent)
{
    m_Delay = 1500; // ms
    m_ManuallyDisconnected = false;
}


void Bot::sendMessage(QString channel, QString message)
{
	/*
    if (m_WaitForDelay)
    {
        while(m_WaitForDelay);
        
    }
	*/
    QString msg = "PRIVMSG " + channel + " :" + message + " \r\n";
    m_socket->write(msg.toStdString().c_str());
	QThread::msleep(m_Delay);
}


void Bot::readyRead()
{
    // :sonfloro!sonfloro@sonfloro.tmi.twitch.tv PRIVMSG #sonfloro :asdflkj
    // :petaliee!petaliee@petaliee.tmi.twitch.tv PRIVMSG #sonfloro :follow twitch.tv/petaliee for free bitcoin

    MessageParser mp_ReadLine(m_socket->readLine());
    QString sender = mp_ReadLine.sender();
    QString message = mp_ReadLine.message();
    QString channel = mp_ReadLine.channel();
    QString readline = mp_ReadLine.getMessage();
    readline.resize(readline.length() - 2);

    // Parse readline into the correct console
    emit updateConsoles(readline, channel, sender, message);

    if (readline.contains("PING"))
    {
        m_socket->write("PONG :irc.twitch.tv \r\n");
        emit writePong();
    }

    emit onMessage(channel, sender, message);

    if (m_socket->canReadLine())
        readyRead();
}

void Bot::start()
{
    this->connectBot();
}

void Bot::connectBot()
{
    m_socket = new QTcpSocket();
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));
    m_socket->connectToHost("irc.chat.twitch.tv", 6667);
    m_socket->waitForConnected(5000);
    if (m_socket->state() == QTcpSocket::ConnectedState)
    {
        emit writeStatusMessage("Connected!");
        m_socket->write("CAP REQ :twitch.tv/membership \r\n");
        {
            m_socket->write("PASS oauth:15mkh5pk7lnfdoit762ekybp5frg8p \r\n");
        }
        m_socket->write("NICK Gayfloro \r\n");
        m_socket->write("USER Gayfloro Gayfloro Gayfloro :Gayfloro \r\n");
        m_socket->write("JOIN #sonfloro \r\n");
        m_socket->write("JOIN #itzmisszoey \r\n");
        m_socket->write("JOIN #lumiriss \r\n");
        m_socket->write("JOIN #whatthehellshappened \r\n");
        m_socket->write("JOIN #armorysons \r\n");
        m_socket->write("JOIN #realmcopier \r\n");

    }
    else
        emit writeStatusMessage("Error: Couldn't connected to twitch irc.");
    // TODO: Deal with the chance that the socket fails to connect the first time.
}

void Bot::disconnect()
{
    m_ManuallyDisconnected = true;
    m_socket->disconnectFromHost();
    m_socket->deleteLater();
    emit deleteBotThread();
}


void Bot::disconnected()
{
    if (!m_ManuallyDisconnected)
    {
        emit writeStatusMessage("Error: Lost connection to twitch irc.");
        while (m_socket->state() == QTcpSocket::UnconnectedState)
        {
            m_socket->connectToHost("irc.chat.twitch.tv", 6667);
            if (m_socket->waitForConnected(2500))
            {
                m_socket->deleteLater();
                this->connectBot();
                break;
            }
            QThread::msleep(2500);
        }
    }
    else
        m_ManuallyDisconnected = false;
}

void Bot::updateDelay(int delay)
{
    m_Delay = delay;
}
/*
void Bot::commandTimerDelayFinished()
{
    this->m_WaitForDelay = false;
}
*/
void Bot::error()
{
    qDebug() << m_socket->errorString();
}
