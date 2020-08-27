#include "textfileparser.h"

TextFileParser::TextFileParser(const char *filename, int flag) :
    m_fileName(filename),
    m_flag(flag)
{
    if (m_flag == TFP_READ)
        m_fstream.open(m_fileName, std::fstream::in);
    else if (m_flag == TFP_WRITE_VALUE)
        m_fstream.open(m_fileName, std::fstream::out);
    else if (m_flag == TFP_WRITE_LOG)
        m_fstream.open(m_fileName, std::fstream::out | std::fstream::ate | std::fstream::app);
    else if (m_flag == TFP_WRITE_MODS)
        m_fstream.open(m_fileName, std::fstream::out | std::fstream::ate | std::fstream::app);
}

// Reads the text file assuming theres multiple lines of strings into a vector
void TextFileParser::readMods(std::vector<std::string> &modsArray)
{
    std::string readline;
    if (m_fstream.is_open())
    {
        while (std::getline(m_fstream, readline))
        {
            if (readline.size() > 0)
                modsArray.push_back(readline);
        }
    }
}
// Reads the text file assuming theres only one line with a integer value into a variable
void TextFileParser::readValue(int &value)
{
    std::string readline;
    if (m_fstream.is_open())
    {
        while (std::getline(m_fstream, readline))
        {
            if (readline.size() > 0)
            {
                QString temp = readline.c_str();
                value = temp.toInt();
                break;
            }
        }
    }
}

void TextFileParser::writeValue(int value)
{
    m_fstream << value;
}

void TextFileParser::writeLog(QString sender, QString message, QString channel)
{
    m_fstream << QDateTime::currentDateTime().toString("ddd MMM d hh:mm:ss yyyy").toStdString() << " " << channel.toStdString() << " " << sender.toStdString() << ": " << message.toStdString() << std::endl;
}

void TextFileParser::appendMod(std::string mod)
{
    if (m_fstream.is_open())
        m_fstream << mod << std::endl;
}


TextFileParser::~TextFileParser()
{
    m_fstream.close();
}
