#ifndef TEXTFILEPARSER_H
#define TEXTFILEPARSER_H

#include <fstream>
#include <vector>
#include <QString>
#include <QDateTime>
#define TFP_READ 1
#define TFP_WRITE_VALUE 2
#define TFP_WRITE_MODS 3
#define TFP_WRITE_LOG 4


class TextFileParser
{
public:
    TextFileParser(const char *filename, int flag);
    void readMods(std::vector<std::string> &modsArray);
    void appendMod(std::string mod);
    void readValue(int &value);
    void writeValue(int value);
    void writeLog(QString sender, QString message, QString channel);
    ~TextFileParser();
private:
    const char *m_fileName;
    const int m_flag;
    std::fstream m_fstream;
};

#endif // TEXTFILEPARSER_H
