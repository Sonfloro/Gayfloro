#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H
#include <QString>

class MessageParser
{
public:
    MessageParser(QString msg = "");

    QString sender();
    QString channel();
    QString message();

    QString getMessage();

private:
    QString m_message;
};

#endif // MESSAGEPARSER_H
