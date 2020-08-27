#include <QString>
#include <QDebug>
#include <vector>
#include <fstream>

#if defined(_WIN32)
    static QString dictionary = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\dictionary.txt";
#endif
#if defined(__unix__)
    static QString dictionary = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/dictionary.txt";
#endif

//static std::vector<QString> wordsUsed;

/*
static QString getNextUnusedWord(std::vector<QString> words)
{
    bool wordUsed = false;
    for (unsigned int i = 0; i < words.size(); i++)
    {
        for (unsigned int j = 0; j < wordsUsed.size(); j++)
        {
            if (QString::compare(words.at(i), wordsUsed.at(j), Qt::CaseInsensitive) == 0)
            {
                wordUsed = true;
                break;
            }
        }
        if (wordUsed)
        {
            wordUsed = false;
            continue;
        }
        wordsUsed.push_back(words.at(i));
        return words.at(i);
    }
    return "";
}
*/
static void sortWords(std::vector<QString> *words, int maxLength)
{
    for (int startIndex = 0; startIndex < maxLength; startIndex++)
    {
        int largestWordIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < maxLength; currentIndex++)
        {
            if (words->at(currentIndex).length() > words->at(largestWordIndex).length())
                largestWordIndex = currentIndex;
        }
        std::swap(words->at(startIndex), words->at(largestWordIndex));
    }
}

std::vector<QString> getBombPartyWord(QString prompt, int length, int results)
{
    bool checkLength = true;
    std::fstream rDictionary;
    rDictionary.open(dictionary.toStdString().c_str(), std::fstream::in);
    std::vector<QString> usableWords;
    std::vector<QString> returnWords;
    if (length == -1)
        checkLength = false;
    if (rDictionary.is_open())
    {
        std::string line;
        while (std::getline(rDictionary, line))
        {
            QString lazyTempString = line.c_str();
            if (checkLength)
            {
                if (lazyTempString.contains(prompt, Qt::CaseInsensitive) && lazyTempString.length() <= length)
                    usableWords.push_back(lazyTempString);
            }
            else
            {
                if (lazyTempString.contains(prompt, Qt::CaseInsensitive))
                    usableWords.push_back(lazyTempString);
            }
        }
    }
    if (usableWords.size() == 0)
    {
        returnWords.push_back("No words found with that prompt.");
        return returnWords;
    }
    sortWords(&usableWords, usableWords.size());

    for (unsigned int i = 0; i < (unsigned int)results; i++)
    {
        if (i < usableWords.size())
            returnWords.push_back(usableWords.at(i));
    }
    return returnWords;
}



