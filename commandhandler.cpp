#include <QDebug>
#include "commandhandler.h"
#include "bombpartycheat.h"

CommandHandler::CommandHandler(QObject *parent) :
    QObject(parent)
{
    // Create variable for time since last use in specific commands for cooldowns
    // Create a class that constantly checks if the last time a command has been used is within 1.5 seconds or not



#if defined(_WIN32)
    text_file_log = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\log.txt";
    text_file_lumirissEatHand = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\lumiEatHand.txt";
    text_file_lumirissMods = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\lumirissMods.txt";
    text_file_lumirissSorry = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\lumiSorry.txt";
    text_file_armorysonsMods = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\armorysonsMods.txt";
    text_file_gayfloroMods = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\gayfloroMods.txt";
    text_file_sonfloroMods = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\sonfloroMods.txt";
    text_file_whatthehellshappenedMods = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\whatthehellshappenedMods.txt";
    text_file_realmcopierMods = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\realmcopierMods.txt";
    text_file_quoteFile = "C:\\Users\\Sam\\Documents\\gayfloroCPP\\TextFiles\\quotes.txt";
#endif
#ifdef __unix__
    text_file_log = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/log.txt";
    text_file_lumirissEatHand = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/lumiEatHand.txt";
    text_file_lumirissMods = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/lumirissMods.txt";
    text_file_lumirissSorry = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/lumiSorry.txt";
    text_file_armorysonsMods = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/armorysonsMods.txt";
    text_file_gayfloroMods = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/gayfloroMods.txt";
    text_file_sonfloroMods = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/sonfloroMods.txt";
    text_file_whatthehellshappenedMods = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/whatthehellshappenedMods.txt";
    text_file_realmcopierModsMods = "/home/sonfloro/Documents/cppProjects/GayfloroCPP/TextFiles/realmcopierMods.txt";
#endif


    // Setup TFPers to store values into variables
    TextFileParser tfp_lumirissMods(text_file_lumirissMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_lumiEatHand(text_file_lumirissEatHand.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_lumiSorry(text_file_lumirissSorry.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_armorysonsMods(text_file_armorysonsMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_gayfloroMods(text_file_gayfloroMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_sonfloroMods(text_file_sonfloroMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_whatthehellshappenedMods(text_file_whatthehellshappenedMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_realmcopierMods(text_file_realmcopierMods.toStdString().c_str(), TFP_READ);
    tfp_lumiSorry.readValue(lumiriss_sorryCount);
    tfp_lumirissMods.readMods(mods_lumiriss);
    tfp_lumiEatHand.readValue(lumiriss_handCount);
    tfp_armorysonsMods.readMods(mods_armorysons);
    tfp_gayfloroMods.readMods(mods_gayfloro);
    tfp_sonfloroMods.readMods(mods_sonfloro);
    tfp_whatthehellshappenedMods.readMods(mods_whatthehellshappened);
    tfp_realmcopierMods.readMods(mods_realmcopier);

}



void CommandHandler::onMessage(QString channel, QString sender, QString message)
{
    // Remove the "\n\r" off the end of the messagae
    message = message.trimmed();



    // Write message to log file
    if (sender.length() > 0 && channel.length() > 0 && message.length() > 0)
    {
        TextFileParser tfp_logFile(text_file_log.toStdString().c_str(), TFP_WRITE_LOG);
        tfp_logFile.writeLog(sender, message, channel);
    }
    if (message == "!time")
        emit sendMessage(channel, QDateTime::currentDateTime().toString("ddd MMM d hh:mm:ss yyyy"));

    if (message.contains("!lumiEatHandTest"))
        emit sendMessage(channel, QString::number(lumiriss_handCount));

    if (message.contains("eat hand", Qt::CaseInsensitive) && channel == "#lumiriss")
    {

        lumiriss_handCount++;
        // Setup TFP to write the eat hand count to text file
        TextFileParser tfp_writeHand(text_file_lumirissEatHand.toStdString().c_str(), TFP_WRITE_VALUE);
        tfp_writeHand.writeValue(lumiriss_handCount);

        emit sendMessage(channel, "Hands to eat: " + QString::number(lumiriss_handCount));
    }
    if (message == "!sorry" && isMod(sender, channel) && channel == "#lumiriss")
    {
        lumiriss_sorryCount++;

        // Setup TFP to write the sorry count to text file
        TextFileParser tfp_writeSorry(text_file_lumirissSorry.toStdString().c_str(), TFP_WRITE_VALUE);
        tfp_writeSorry.writeValue(lumiriss_sorryCount);

        emit sendMessage(channel, "Lumi's \"Sorry\" count: " + QString::number(lumiriss_sorryCount));
    }
    if (message == "!sorryCount" && channel == "#lumiriss")
        emit sendMessage(channel, "Lumi has said \"Sorry\" "+ QString::number(lumiriss_sorryCount) + " times since: 2018-01-17.");

	if (message == "!discord")
	{
		if (channel == "#lumiriss")
		{
			emit sendMessage(channel, "You can join the discord by clicking the image below the stream or clicking this link: https://discordapp.com/invite/N4Xk8mQ");
		}
		else if (channel == "#itzmisszoey")
		{
			emit sendMessage(channel, "You can join the discord by clicking the image below the stream or clicking this link: https://discordapp.com/invite/mVNzaBv");
		}
	}
        

    if (message.startsWith("!randomlogmessage"))
    {
        const int startHere = 69701;
        std::vector<std::string> args = getMessageArgs(message);
        QString nonoPeople[4] = {"lumiriss", "yukimorgan", "petaliee", "axolotle_in_a_bottle"};
        int logLength = 0;
        std::ifstream stream;
        bool newMessage = false;
        if (args.size() == 1)
        {
            stream.open(text_file_log.toStdString().c_str());
            if (stream.is_open())
            {
                std::string temp;
                while (std::getline(stream, temp))
                    logLength++;
            }
            stream.close();

            std::uniform_int_distribution<int> dist(startHere, logLength);
            std::mt19937 mt(m_randomDevice());
            unsigned int randomNumber = dist(mt);
            stream.open(text_file_log.toStdString().c_str());
            if (stream.is_open())
            {
                std::string temp;
                unsigned int count = 0;
                while (std::getline(stream, temp))
                {
                    count++;
                    if (newMessage)
                    {
                        bool goodMessaage = true;
                        QString check = temp.c_str();
                        for (int i = 0; i < 4; i++)
                        {
                            if (check.contains(nonoPeople[i]))
                                goodMessaage = false;
                        }
                        if (goodMessaage)
                        {
                            emit sendMessage(channel, temp.c_str());
                            stream.close();
                        }
                    }

                    if (count > startHere && count == randomNumber)
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            QString check = temp.c_str();
                            if (check.contains(nonoPeople[i]))
                            {
                                newMessage = true;
                            }
                        }
                        if (!newMessage)
                        {
                            emit sendMessage(channel, temp.c_str());
                            stream.close();
                        }
                    }
                }
            }
        }
        /*
        else
        {
            for (unsigned int i = 0; i < args.size(); i++)
            {
                if (args.at(i) == "-u" || args.at(i) == "--user")
                {
                    QString userCheck;
                    QString user = args.at(i + 1).c_str();
                    std::vector<QString> usableLines;
                    int lengthCount = 0;
                    stream.open(text_file_log.toStdString().c_str());
                    if (stream.is_open())
                    {
                        std::string temp;
                        while (std::getline(stream, temp))
                        {
                            lengthCount++;
                            userCheck = temp.c_str();
                            if (userCheck.contains(user))
                            {
                                usableLines.push_back(temp.c_str());
                            }
                            else
                                continue;
                        }
                        stream.close();
                    }
                    std::uniform_int_distribution<int> dist(0, usableLines.size());
                    std::mt19937 mt(m_randomDevice());
                    unsigned int randomNumber = dist(mt);

                    for (unsigned int i = 0; i < usableLines.size(); i++)
                    {
                        if (i == randomNumber)
                            emit sendMessage(channel, usableLines.at(i));
                    }
                }
            }
        }
        */
    }

    if (message.startsWith("!quote"))
    {
        // Store log of who adds what quote for me
        std::vector<std::string> args = getMessageArgs(message);
        int fileLength = 0;
        std::ifstream file(text_file_quoteFile.toStdString().c_str());
        if (file.is_open())
        {
            std::string temp;
            while (std::getline(file, temp))
                   fileLength++;
        }
        file.close();
        if (args.size() == 1)
        {
            std::uniform_int_distribution<int> dist(0, fileLength);
            std::mt19937 mt(m_randomDevice());
            int randomNumber = dist(mt);

            file.open(text_file_quoteFile.toStdString().c_str());
            if (file.is_open())
            {
                int count = 0;
                std::string temp;
                while (std::getline(file, temp))
                {
                    count++;
                    if (count == randomNumber)
                        emit sendMessage(channel, temp.c_str());
                }
            }
            file.close();
        }
        else
        {
            bool intTest = false;
            int quoteNumber = QString(args.at(1).c_str()).toInt(&intTest, 10);
            if (intTest)
            {
                file.open(text_file_quoteFile.toStdString().c_str());
                if (file.is_open())
                {
                    int count = 0;
                    std::string temp;
                    while (std::getline(file, temp))
                    {
                        count++;
                        if (count == quoteNumber)
                            emit sendMessage(channel, temp.c_str());
                    }
                }
            }
        }


    }


    if (message.startsWith("!bpc", Qt::CaseInsensitive))
    {
        std::vector<std::string> args = getMessageArgs(message);
        std::vector<QString> returnedWords;
        int length = -1;
        int results = 1;
        const int maxResults = 5;
        const int maxLength = 35;
        QString prompt;
        for (unsigned int i = 0; i < args.size(); i++)
        {
            if (args.at(i) == "-h" || args.at(i) == "--help")
            {
                emit sendMessage(channel, "Command help can be found here: https://pastebin.com/EA8JsM7P");
                break;
            }
            if (args.at(i) == "-l" || args.at(i) == "--length")
            {
                if (i == args.size() - 1)
                    break;
                QString temp(args.at(i + 1).c_str());
                bool toIntSuccess = false;
                length = temp.toInt(&toIntSuccess, 10);
                if (length > maxLength || length < 1)
                    length = -1;
                if (!toIntSuccess)
                    length = -1;
                continue;
            }
            if (args.at(i) == "-r" || args.at(i) == "--results")
            {
                if (i == args.size() - 1)
                    break;
                QString temp(args.at(i + 1).c_str());
                bool toIntSuccess = false;
                results = temp.toInt(&toIntSuccess, 10);
                if (results > maxResults || results < 1)
                    results = 1;
                if (!toIntSuccess)
                    results = 1;
                continue;
            }
            if (args.at(i) == "-p" || args.at(i) == "--prompt")
            {
                if (i == args.size() - 1)
                    break;
                prompt = args.at(i + 1).c_str();
                continue;
            }
        }
        if (!prompt.isEmpty())
        {
            returnedWords = getBombPartyWord(prompt, length, results);
        }
        for (auto i : returnedWords)
        {
            emit sendMessage(channel, i);
            QThread::msleep(10);
        }
    }
    if (sender == "fellowdaydreamer" && channel == "#armorysons")
    {
        std::uniform_int_distribution<int> dist(0, 100);
        std::mt19937 mt(m_randomDevice());
        int randomNumber = dist(mt);
        if (randomNumber == 57)
            emit sendMessage(channel, "A bingo race involves a randomly generated, 5x5 bingo card like this. "
                                  "The objective is to make a \"bingo\" (5 in a row) by choosing a row, column, or diagonal on the card and completing each of the goals. "
                                  "The first person to complete 5 goals in a row wins.");
    }
    if (message == "!hundo" && channel == "#whatthehellshappened")
    {
        emit sendMessage(channel, "Streamer when is hundo?");
    }
    if (message.startsWith("!setDelay") && sender == "sonfloro")
    {
        int delay = message.mid(10, 1).toInt();
        emit updateDelay(delay);
        emit sendMessage(channel, "Set delay to " + QString::number(delay) + "ms.");
    }
    if (message == "!amimod")
    {
        if (isMod(sender, channel))
            emit sendMessage(channel, "Yeah sure whatever");
        else
            emit sendMessage(channel, "No, you pleb");
    }
    if (message == "!triggered" && channel == "#armorysons")
        emit sendMessage(channel, "As a semi-Professional bomb party player, your spelling of 'watter' is triggering me - Armory 7/9/16");

    if (message == "!water" && channel == "#armorysons")
        emit sendMessage(channel, "#RyansWatterBottle");

    if (message == "!armory" && channel == "#armorysons")
        emit sendMessage(channel, "Distant sounds of laughing, screaming, and controllers being smashed are heard");

    if (message == "!wthh" && channel == "whatthehellshappened")
        emit sendMessage(channel, "Wthh, telling grandmas to shut up since 2004.");

    if (message == "!drugs" && channel == "#sonfloro")
        emit sendMessage(channel, "✝ NO ✝ DRUGS ✝ IN ✝ THIS ✝ CHRISTIAN ✝ STREAM ✝");
    if (message == "!commands")
    {
        if (channel == "#sonfloro")
            emit sendMessage(channel, "The commands for this channel are: !time, !row, !amidisabled, !bpc, !title, !uptime, and !amimod.");
        if (channel == "#gayfloro")
            emit sendMessage(channel, "The commands for this channel are: !time, !row, !amidisabled, !bpc, !title, !uptime, and !amimod.");
        if (channel == "#lumiriss")
            emit sendMessage(channel, "The commands for this channel are: !time, !row, !amidisabled, !amimod, !discord, !sorry (mods only), !sorrycount, !handsToEat, !bpc,"
                                      " !title, !uptime, and \"eat hand\"");
        if (channel == "#whatthehellshappened")
            emit sendMessage(channel, "The commands for this channel are: !time, !row, !amidisabled, !amimod, !wthh, !bpc, !title, !uptime, and !hundo");
        if (channel == "#armorysons")
            emit sendMessage(channel, "The commands for this channel are: !time, !row, !amidisabled, !amimod, !triggered, !water, !bpc, !title, !uptime, and !armory");
        if (channel == "#realmcopier")
            emit sendMessage(channel, "The commands for this channel are: !time, !row, !amidisabled, !bpc, !title, !uptime, and !amimod.");
    }
    if (message == "!amidisabled")
    {
        if (QDateTime::currentDateTime().toMSecsSinceEpoch() % 2)
            sendMessage(channel, "https://i.imgur.com/3WaN1Wq.png");
        else
            sendMessage(channel, "https://i.imgur.com/Yb7T0Mj.png");
    }
    if (message.contains("www.youtube.com") || message.contains("youtu.be"))
    {
        bool isVideoIDValid = false;
        QString videoID;
        for (int i = 0; i < message.length(); i++)
        {
            if (message.toStdString().c_str()[i] == 'h' && message.toStdString().c_str()[i + 1] == 't' && message.toStdString().c_str()[i + 2] == 't' && message.toStdString().c_str()[i + 3] == 'p')
            {
                if (message.contains("youtube.com"))
                {
                    for (int j = 0; j < message.length() - i; j++)
                    {
                        if (message.toStdString().c_str()[j + i] == 'v' && message.toStdString().c_str()[j + i + 1] == '=')
                        {
                            videoID = message.mid(j + i + 2, 11);
                            isVideoIDValid = true;
                        }
                    }
                }
                else if (message.contains("youtu.be"))
                {
                    videoID = message.mid(i + 17);
                    isVideoIDValid = true;
                }
            }
        }
        if (isVideoIDValid)
        {
            QString url;
            {
                url = "https://www.googleapis.com/youtube/v3/videos?part=contentDetails%2C+snippet&id=" + videoID + "&key=AIzaSyDtb6zd8zTF9Fjgqa-gt6AK6AsHRX18TOc";
            }
			emit updateDebugConsole(url);
            m_YouTubeAPICurrentChannel = channel;
            QNetworkRequest request;
            request.setUrl(QUrl(url));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            m_YouTubeAPIManager = new QNetworkAccessManager();
            connect(m_YouTubeAPIManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onYouTubeAPIResponse(QNetworkReply*)));
            m_YouTubeAPIManager->get(request);
        }
    }
    if (message == "!title")
    {
        m_TwitchAPIRequestType = API_REQUEST_TYPE_TITLE;
        m_TwitchAPICurrentChannel = channel;
        qDebug() << channel.remove(0, 1);
        QString url = "https://api.twitch.tv/helix/streams?user_login=" + channel.remove('#');
        qDebug() << url;
        QNetworkRequest request;
        request.setUrl(url);
        {
        request.setRawHeader(QByteArray("Client-ID"), QByteArray("ldgivrytf4wit3ndnh46ni03osz6p4"));
        }
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        m_TwitchAPIManager = new QNetworkAccessManager();
        connect(m_TwitchAPIManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onTwitchAPIResponse(QNetworkReply*)));
        m_TwitchAPIManager->get(request);
    }
    if (message == "!uptime")
    {
        m_TwitchAPIRequestType = API_REQUEST_TYPE_UPTIME;
        m_TwitchAPICurrentChannel = channel;
        qDebug() << channel.remove(0, 1);
        QString url = "https://api.twitch.tv/helix/streams?user_login=" + channel.remove('#');
        qDebug() << url;
        QNetworkRequest request;
        request.setUrl(url);
        {
        request.setRawHeader(QByteArray("Client-ID"), QByteArray("ldgivrytf4wit3ndnh46ni03osz6p4"));
        }
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        m_TwitchAPIManager = new QNetworkAccessManager();
        connect(m_TwitchAPIManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onTwitchAPIResponse(QNetworkReply*)));
        m_TwitchAPIManager->get(request);
    }
    if (message == "!row")
    {
        srand(QDateTime::currentDateTime().toMSecsSinceEpoch());
		std::vector<std::string> rows = { "Row 1", "Row 2", "Row 3", "Row 4", "Row 5", "Col 1", "Col 2", "Col 3", "Col 4", "Col 5", "TL-BR", "BL-TR" };
        std::uniform_int_distribution<int> dist(0, 11);
        std::mt19937 mt(m_randomDevice());
        int randomNumber = dist(mt);
		for (unsigned int i = 0; i < rows.size(); i++)
		{
			if (randomNumber == i)
				emit sendMessage(channel, rows.at(i).c_str());
		}
    }
    if (message.startsWith("!addMod") && isOwner(sender, channel))
    {
        std::vector<std::string> args = getMessageArgs(message);
        QString mod = args.at(0).c_str();
        if (!isMod(mod, channel))
        {
            addMod(mod, channel);
            emit sendMessage(channel, "Successfully appended " + mod + " to the mod list");
        }
        else
            emit sendMessage(channel, "Error: " + mod + " is already a mod for this channel");
    }
    if (message.startsWith("!delMod") && isOwner(sender, channel))
    {

    }

    if (message.startsWith("!egg", Qt::CaseInsensitive))
    {
        emit sendMessage(channel, "/timeout " + sender + " 60");
    }

    if (message.startsWith("!nimpize", Qt::CaseInsensitive) && channel == "#sonfloro")
    {
        emit sendMessage(channel, "Nimpize Adventure is a whole new Ocarina of Time game created by Ostrealava02 for the 20th anniversary of OoT. "
                                  "You can find the trailer for it here: https://www.youtube.com/watch?v=sotmg3OiVfI");
    }

    if (message.startsWith("!zoey", Qt::CaseInsensitive))
    {
        emit sendMessage(channel, "The population of America is only 3 million people. - Zoey 01/27/19");
    }
	if (message == "!testDebug")
	{
		emit sendMessage(channel, "Appended Debug Console.");
		emit updateDebugConsole("Test debug message");
	}

	if (message.startsWith("!osrsstats"))
	{
		bool noError = true;
		m_JagexAPICurrentChannel = channel;
		if (!m_JagexAPISpecificSkill.isEmpty())
			m_JagexAPISpecificSkill.clear();
		std::vector<std::string> args = getMessageArgs(message);
		std::vector<std::string> skills = { "Total Level", "Attack", "Defense", "Strength", "Hitpoints", "Ranged", "Prayer", "Magic",
											"Cooking", "Woodcutting", "Fletching", "Fishing", "Firemaking", "Crafting", "Smithing",
											"Mining", "Herblore", "Agility", "Thieving", "Slayer", "Farming", "Runecraft", "Hunter",
											"Construction" };
		if (args.size() < 2 || args.size() > 3)
		{
			if (args.size() < 2)
				emit sendMessage(channel, "Error: No RSN provided.");
			else if (args.size() > 3)
				emit sendMessage(channel, "Error: Too many arguments.");
			noError = false;
		}
		else if (args.size() > 2)
		{
			for (unsigned int i = 0; i < skills.size(); i++)
			{
				if (args.at(2) == skills.at(i))
					m_JagexAPISpecificSkill = skills.at(i).c_str();
			}
			if (m_JagexAPISpecificSkill.isEmpty())
			{
				emit sendMessage(channel, "Error: " + QString(args.at(2).c_str()) + " is not a skill.");
				noError = false;
			}
		}
		if (noError)
		{
			QString RSN = args.at(1).c_str();
			m_JagexAPIrsn = RSN;
			QString url = "https://secure.runescape.com/m=hiscore_oldschool/index_lite.ws?player=" + RSN;
			emit updateDebugConsole(url);
			QNetworkRequest request;
			request.setUrl(QUrl(url));
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
			m_JagexAPIManager = new QNetworkAccessManager();
			connect(m_JagexAPIManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onJagexAPIResponse(QNetworkReply*)));
			m_JagexAPIManager->get(request);
		}
	}
	if ((message.startsWith("!chickenSay") || message.startsWith("!chSay")) && channel == "#lumiriss")
	{
		std::vector<std::string> args = getMessageArgs(message);
		QString fullMessage;
		for (unsigned int i = 1; i < args.size(); i++)
		{
			fullMessage.append(args.at(i).c_str() + QString(" "));
		}
		sendMessage(channel, QString("@lumiriss ") + fullMessage);
	}
	//url = "https://secure.runescape.com/m=hiscore_oldschool/index_lite.ws?player=ffffffffffffff";
	if ((message.startsWith("!chickenPickMe") || message.startsWith("!chPickMe")) && channel == "#lumiriss")
	{
		emit sendMessage(channel, "pickme");
	}
	if ((message.startsWith("!chickenHeal") || message.startsWith("!chHeal")) && channel == "#lumiriss")
	{
		emit sendMessage(channel, "heal");
	}
	if ((message.startsWith("!chickenHelp") || message.startsWith("!chHelp")) && channel == "#lumiriss")
	{
		emit sendMessage(channel, "The chicken commands are: !chickenPickMe, !chickenHeal, !chickenSay, !chPickMe, !chHeal, and !chSay");
	}
}

void CommandHandler::onJagexAPIResponse(QNetworkReply* reply)
{
	emit updateDebugConsole("Got into API response function");
	QString data = reply->readAll();
	std::vector<std::string> replyArgs = getOsrsArgs(data.toStdString().c_str());
	std::vector<std::string> skillList = { "Total Level", "Attack", "Defense", "Strength", "Hitpoints", "Ranged",
											"Prayer", "Magic", "Cooking", "Woodcutting", "Fletching", "Fishing",
											"Firemaking", "Crafting", "Smithing", "Mining", "Herblore",
											"Agility", "Thieving", "Slayer", "Farming", "Runecraft", "Hunter",
											"Construction" };
	QString channelMessage = "Stats for " + m_JagexAPIrsn + ": ";
	if (m_JagexAPISpecificSkill.isEmpty())
	{
		for (unsigned int i = 0; i < replyArgs.size(); i++)
		{
			if (i > skillList.size() - 1)
				break;
			channelMessage.append(skillList.at(i).c_str() + QString(": ") + getOsrsLevel(replyArgs.at(i).c_str()) + " - ");
		}
		emit sendMessage(m_JagexAPICurrentChannel, channelMessage);
	}
	else
	{
		for (unsigned int i = 0; i < replyArgs.size(); i++)
		{
			if (i > skillList.size() - 1)
				break;
			if (skillList.at(i).c_str() == m_JagexAPISpecificSkill)
			{
				channelMessage.append(skillList.at(i).c_str() + QString(" Level ") + getOsrsLevel(replyArgs.at(i).c_str()));
			}
		}
		emit sendMessage(m_JagexAPICurrentChannel, channelMessage);
	}
	m_JagexAPIManager->deleteLater();
}



void CommandHandler::onYouTubeAPIResponse(QNetworkReply *reply)
{
	emit updateDebugConsole("Got into API response function");
    // Grab response data
    QByteArray responseData = reply->readAll();
	emit updateDebugConsole("Reply Data: " + responseData.length());
    // Parse QByteArray into a jsonDoc
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    // Grab the root object
    QJsonObject root_obj = jsonDoc.object();
    // Create a VariantMap of the root object
    QVariantMap root_map = root_obj.toVariantMap();
    // Create a VariantList for the "items" array
    QVariantList itemsList = root_map["items"].toList();
    // Make sure the items list isn't empty
	emit updateDebugConsole("Before list size check");
    if (itemsList.size() == 0)
        return;
	emit updateDebugConsole("Got past list size check");
    // Create a VariantMap of the first object in the "items" array (this is the only object in the array that is useful to me)
    QVariantMap itemsMap = itemsList.at(0).toMap();
    // Create a map of the "snippet" object which contains our Title and Author
    QVariantMap snippetMap = itemsMap["snippet"].toMap();
    // Create a map of the "contentDetails" which contains the video length
    QVariantMap contentDetailsMap = itemsMap["contentDetails"].toMap();
    // Grab the data we need into local variables
    QString videoTitle = snippetMap["title"].toString();
    QString videoAuthor = snippetMap["channelTitle"].toString();
    QString videoLength = contentDetailsMap["duration"].toString();
    // Create a temporary QDateTime to help convert the ISO 8601 timestamp provided by Google
    QDateTime tempDate;
    // Do the conversions based on how long the video is.
    if (videoLength.contains("H"))
        tempDate = QDateTime::fromString(videoLength, "PTh\'H\'m\'M\'s\'S\'");
    else if (videoLength.contains("M"))
        tempDate = QDateTime::fromString(videoLength, "PTm\'M\'s\'S\'");
    else
        tempDate = QDateTime::fromString(videoLength, "PTs\'S\'");
    // Convert QDateTime back into a QString with our desired format
    QString convertedLength = tempDate.toString("hh:mm:ss");


    emit sendMessage(m_YouTubeAPICurrentChannel, "Video: " + videoTitle + " | Uploaded by: " + videoAuthor + " | Duration: " + convertedLength);
    // I have to delete the NetowrkAccessManager object myself
    m_YouTubeAPIManager->deleteLater();
}

void CommandHandler::onTwitchAPIResponse(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
    qDebug() << responseData;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    // Grab the root object
    QJsonObject root_obj = jsonDoc.object();
    QVariantMap root_map = root_obj.toVariantMap();
    QVariantList data_list = root_map["data"].toList();
    if (data_list.size() == 0)
    {
        emit sendMessage(m_TwitchAPICurrentChannel, "Error: Channel is not live.");
        return;
    }
    QVariantMap data_map = data_list.at(0).toMap();
    if (m_TwitchAPIRequestType == API_REQUEST_TYPE_TITLE)
    {
        QString title = data_map["title"].toString();
        emit sendMessage(m_TwitchAPICurrentChannel, "Stream title: " + title);
    }
    else if (m_TwitchAPIRequestType == API_REQUEST_TYPE_UPTIME)
    {
        QString channelUpTime = data_map["started_at"].toString();
        QDateTime currentTime = QDateTime::currentDateTime().toUTC();
        QDateTime streamStartDate = QDateTime::fromString(channelUpTime, "yyyy-MM-dd\'T\'hh:mm:ss\'Z\'");
        streamStartDate.setOffsetFromUtc(0);
        int secs = streamStartDate.secsTo(currentTime);
        long msecs = secs * 1000;
        QString streamUpTime = getFormattedTime(msecs);
        emit sendMessage(m_TwitchAPICurrentChannel, "Stream has been live for: " + streamUpTime);
    }
    m_TwitchAPIManager->deleteLater();
}


bool CommandHandler::isMod(QString sender, QString channel, bool *b)
{
    if (channel == "#lumiriss")
    {
        for (unsigned int i = 0; i < mods_lumiriss.size(); i++)
        {
            if (sender ==  mods_lumiriss.at(i).c_str())
            {
                if (b)
                    *b = true;
                return true;
            }
        }
        if (b)
            *b = false;
        return false;
    }
    if (channel == "#sonfloro")
    {
        for (unsigned int i = 0; i < mods_sonfloro.size(); i++)
        {
            if (sender ==  mods_sonfloro.at(i).c_str())
            {
                if (b)
                    *b = true;
                return true;
            }
        }
        if (b)
            *b = false;
        return false;
    }
    if (channel =="#gayfloro")
    {
        for (unsigned int i = 0; i < mods_gayfloro.size(); i++)
        {
            if (sender ==  mods_gayfloro.at(i).c_str())
            {
                if (b)
                    *b = true;
                return true;
            }
        }
        if (b)
            *b = false;
        return false;
    }
    if (channel == "#armorysons")
    {
        for (unsigned int i = 0; i < mods_armorysons.size(); i++)
        {
            if (sender ==  mods_armorysons.at(i).c_str())
            {
                if (b)
                    *b = true;
                return true;
            }
        }
        if (b)
            *b = false;
        return false;
    }
    if (channel == "#whatthehellshappened")
    {
        for (unsigned int i = 0; i < mods_whatthehellshappened.size(); i++)
        {
            if (sender == mods_whatthehellshappened.at(i).c_str())
            {
                if (b)
                    *b = true;
                return true;
            }
        }
        if (b)
            *b = false;
        return false;
    }
    if (channel == "#realmcopier")
    {
        for (unsigned int i = 0; i < mods_realmcopier.size(); i++)
        {
            if (sender == mods_realmcopier.at(i).c_str())
            {
                if (b)
                    *b = true;
                return true;
            }
        }
        if (b)
            *b = false;
        return false;
    }
    return false;
}

bool CommandHandler::isOwner(QString sender, QString channel)
{
    if (channel == "#sonfloro" && sender == "sonfloro")
        return true;
    else if (channel == "#gayfloro" && sender == "gayfloro")
        return true;
    else if (channel == "#whatthehellshappened" && sender == "whatthehellshappened")
        return true;
    else if (channel == "#lumiriss" && sender == "lumiriss")
        return true;
    else if (channel == "#armorysons" && sender == "armorysons")
        return true;
    else if (channel == "#realmcopier" && sender == "realmcopier")
        return true;
    else
        return false;
}

void CommandHandler::updateTextFiles()
{
    TextFileParser tfp_lumirissMods(text_file_lumirissMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_lumiEatHand(text_file_lumirissEatHand.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_lumiSorry(text_file_lumirissSorry.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_armorysonsMods(text_file_armorysonsMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_gayfloroMods(text_file_gayfloroMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_sonfloroMods(text_file_sonfloroMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_whatthehellshappenedMods(text_file_whatthehellshappenedMods.toStdString().c_str(), TFP_READ);
    TextFileParser tfp_realmcopierMods(text_file_realmcopierMods.toStdString().c_str(), TFP_READ);
    tfp_lumiSorry.readValue(lumiriss_sorryCount);
    tfp_lumirissMods.readMods(mods_lumiriss);
    tfp_lumiEatHand.readValue(lumiriss_handCount);
    tfp_armorysonsMods.readMods(mods_armorysons);
    tfp_gayfloroMods.readMods(mods_gayfloro);
    tfp_sonfloroMods.readMods(mods_sonfloro);
    tfp_whatthehellshappenedMods.readMods(mods_whatthehellshappened);
    tfp_realmcopierMods.readMods(mods_realmcopier);
}

//Mon Jan 15 20:16:57 CST 2018  #sonfloro sonfloro: !test

QString CommandHandler::getOsrsLevel(std::string data)
{
	
	//159920,1813,84610781
	//length = 20
	//6 = ,
	//6 gets increased to 7
	//
	QString level;
	int substrStart = 0;
	int substrLength = 0;
	emit updateDebugConsole("Data: " + QString(data.c_str()));
	for (unsigned int i = 0; i < data.length(); i++)
	{
		if (data.c_str()[i] == ',') // i = 6
		{
			++i; // i = 7
			substrStart = i;
			for (unsigned int j = 0; j < data.length() - i; j++)
			{
				if (data.c_str()[j + i] == ',') // this is 1 for first iteration
				{
					level = data.substr(substrStart, substrLength).c_str();
				}
				substrLength++;
			}
		}
	}
	return level;
}



std::vector<std::string> CommandHandler::getMessageArgs(QString message)
{
    message.append(' ');
    message.prepend(' ');
    std::vector<std::string> args;
    for (int i = 0; i < message.length(); i++)
    {
        if (message.toStdString().c_str()[i] == ' ')
        {
            for (int j = 1; j < message.length() - i; j++)
            {
                if (message.toStdString().c_str()[i + j] == ' ')
                {
                    args.push_back(message.mid(i + 1, j - 1).toStdString()); //The + 1 and - 1 are there to remove whitespace from the arg
                    break;
                }
            }
        }
    }
    return args;
}

std::vector<std::string> CommandHandler::getOsrsArgs(QString message)
{
	message.append('\n');
	message.prepend('\n');
	std::vector<std::string> args;
	for (int i = 0; i < message.length(); i++)
	{
		if (message.toStdString().c_str()[i] == '\n')
		{
			for (int j = 1; j < message.length() - i; j++)
			{
				if (message.toStdString().c_str()[i + j] == '\n')
				{
					args.push_back(message.mid(i + 1, j - 1).toStdString()); //The + 1 and - 1 are there to remove whitespace from the arg
					break;
				}
			}
		}
	}
	return args;
}

// Change this to a bool and remvoe the crap in !addMod function
void CommandHandler::addMod(QString mod, QString channel)
{
    if (channel == "#sonfloro")
    {
        TextFileParser tfp(text_file_sonfloroMods.toStdString().c_str(), TFP_WRITE_MODS);
        tfp.appendMod(mod.toStdString());
    }
    if (channel == "#gayfloro")
    {
        TextFileParser tfp(text_file_gayfloroMods.toStdString().c_str(), TFP_WRITE_MODS);
        tfp.appendMod(mod.toStdString());
    }
    if (channel == "#lumiriss")
    {
        TextFileParser tfp(text_file_lumirissMods.toStdString().c_str(), TFP_WRITE_MODS);
        tfp.appendMod(mod.toStdString());
    }
    if (channel == "#whatthehellshappened")
    {
        TextFileParser tfp(text_file_whatthehellshappenedMods.toStdString().c_str(), TFP_WRITE_MODS);
        tfp.appendMod(mod.toStdString());
    }
    if (channel == "#armorysons")
    {
        TextFileParser tfp(text_file_armorysonsMods.toStdString().c_str(), TFP_WRITE_MODS);
        tfp.appendMod(mod.toStdString());
    }
    if (channel == "#realmcopier")
    {
        TextFileParser tfp(text_file_realmcopierMods.toStdString().c_str(), TFP_WRITE_MODS);
        tfp.appendMod(mod.toStdString());
    }
}

QString CommandHandler::getFormattedTime(long msecs)
{
    QString formattedTime;
    int hours = msecs/(1000*60*60);
    int minutes = (msecs-(hours*1000*60*60))/(1000*60);
    int seconds = (msecs-(minutes*1000*60)-(hours*1000*60*60))/1000;

    formattedTime.append(QString("%1").arg(hours, 2, 10, QLatin1Char('0')) + ":" +
                         QString( "%1" ).arg(minutes, 2, 10, QLatin1Char('0')) + ":" +
                         QString( "%1" ).arg(seconds, 2, 10, QLatin1Char('0')));

    return formattedTime;
}

void CommandHandler::start()
{
}

void CommandHandler::disconnect()
{
    emit deleteCHThread();
}


