#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QThread>
#include <QtNetwork>
#include <vector>
#include <stdlib.h>
#include <random>
#include "textfileparser.h"

#define API_REQUEST_TYPE_UPTIME 1
#define API_REQUEST_TYPE_TITLE 2

class CommandHandler : public QObject
{
    Q_OBJECT
public:
    explicit CommandHandler(QObject *parent = Q_NULLPTR);
    virtual ~CommandHandler() {}
signals:
    void sendMessage(QString channel, QString message); //connect sendMessaage to Bot's sendMessage slot DONE
    void updateDelay(int delay);
    void deleteCHThread();
	void updateDebugConsole(QString message);
private slots:
    void onMessage(QString channel, QString sender, QString message);
    void start();
    void disconnect();
    void onYouTubeAPIResponse(QNetworkReply *reply);
    void onTwitchAPIResponse(QNetworkReply *reply);
	void onJagexAPIResponse(QNetworkReply* reply);
    void updateTextFiles();
    void addMod(QString mod, QString channel);
    bool isMod(QString sender, QString channel, bool *b = nullptr);
private:

    void updateMods();
    bool isOwner(QString sender, QString channel);
    std::vector<std::string> getMessageArgs(QString message);
	std::vector<std::string> getOsrsArgs(QString message);
    QString getFormattedTime(long msecs);
	QString getOsrsLevel(std::string data);

    std::vector<std::string> mods_lumiriss;
    std::vector<std::string> mods_armorysons;
    std::vector<std::string> mods_gayfloro;
    std::vector<std::string> mods_sonfloro;
    std::vector<std::string> mods_whatthehellshappened;
    std::vector<std::string> mods_realmcopier;
    QString text_file_log;
    QString text_file_lumirissSorry;
    QString text_file_lumirissMods;
    QString text_file_lumirissEatHand;
    QString text_file_sonfloroMods;
    QString text_file_gayfloroMods;
    QString text_file_whatthehellshappenedMods;
    QString text_file_armorysonsMods;
    QString text_file_realmcopierMods;
    QString text_file_quoteFile;
    int lumiriss_handCount;
    int lumiriss_sorryCount;


    std::random_device m_randomDevice;

    int m_TwitchAPIRequestType;

    QNetworkAccessManager* m_YouTubeAPIManager;
    QNetworkAccessManager* m_TwitchAPIManager;
	QNetworkAccessManager* m_JagexAPIManager;
    QString m_YouTubeAPICurrentChannel;
    QString m_TwitchAPICurrentChannel;
	QString m_JagexAPICurrentChannel;
	QString m_JagexAPIrsn;
	QString m_JagexAPISpecificSkill;
};

#endif // COMMANDHANDLER_H
