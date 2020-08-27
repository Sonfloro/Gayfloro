#include "messageparser.h"
#include <QDebug>
#include "textfileparser.h"
MessageParser::MessageParser(QString msg):
    m_message(msg)
{
}

// :petaliee!petaliee@petaliee.tmi.twitch.tv PRIVMSG #sonfloro :follow twitch.tv/petaliee for free bitcoin
QString MessageParser::sender()
{
    QString tempMessage = m_message;
    tempMessage.remove(0, 1);
    for (int i = 0; i < tempMessage.length(); i++)
    {
        if (tempMessage.at(i) == '!')
        {
            return tempMessage.left(i);
        }
    }
    return "";
}

QString MessageParser::channel()
{
    QString tempMessage = m_message;
    bool findLength = false;
    int position, length;
    for (int i = 0; i < tempMessage.length(); i++)
    {
        if (tempMessage.at(i) == '#')
        {
            position = i;
            findLength = true;
        }
        else if ((tempMessage.at(i) == ' ' || i == (tempMessage.length() - 1)) && findLength)
        {
            length = (i - position);
            return tempMessage.mid(position, length);
        }
    }
    return "";
}

QString MessageParser::message()
{
    QString tempMessage = m_message;
    tempMessage.remove(0, 1);
    for (int i = 0; i < tempMessage.length(); i++)
    {
        if (tempMessage.at(i) == ':')
        {
            return tempMessage.mid(i + 1);
        }
    }
    return "";
}

QString MessageParser::getMessage()
{
    return m_message;
}
