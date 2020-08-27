#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bot.h"
#include <QDebug>
#include <QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/img/chadThink.png"));
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint /*Qt::FramelessWindowHint*/);


	// Initialize a new Bot thread
	QThread* botThread = new QThread();
	Bot* gayfloro = new Bot();
	gayfloro->moveToThread(botThread);
	// Fuckload of connections
	connect(botThread, SIGNAL(started()), gayfloro, SLOT(start()));
	connect(botThread, SIGNAL(finished()), botThread, SLOT(deleteLater()));
	connect(gayfloro, SIGNAL(updateConsoles(QString, QString, QString, QString)), this, SLOT(updateConsoles(QString, QString, QString, QString)), Qt::QueuedConnection);
	connect(gayfloro, SIGNAL(deleteBotThread()), botThread, SLOT(quit()));
	connect(gayfloro, SIGNAL(writePong()), this, SLOT(writePong()), Qt::QueuedConnection);
	connect(gayfloro, SIGNAL(writeStatusMessage(QString)), this, SLOT(writeStatusMessage(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(disconnectBot()), gayfloro, SLOT(disconnect()), Qt::QueuedConnection);
	connect(this, SIGNAL(sendCustomMessage(QString, QString)), gayfloro, SLOT(sendMessage(QString, QString)), Qt::QueuedConnection);


	// Initialize a new CommandHandler thread
	QThread* chThread = new QThread();	
	CommandHandler* commandHandler = new CommandHandler();
	commandHandler->moveToThread(chThread);
	// More shitty connections
	connect(chThread, SIGNAL(started()), commandHandler, SLOT(start()));
	connect(chThread, SIGNAL(finished()), chThread, SLOT(deleteLater()));
	connect(commandHandler, SIGNAL(sendMessage(QString, QString)), gayfloro, SLOT(sendMessage(QString, QString)), Qt::BlockingQueuedConnection);
	connect(commandHandler, SIGNAL(sendMessage(QString, QString)), commandHandler, SLOT(updateTextFiles()));
	connect(commandHandler, SIGNAL(updateDelay(int)), gayfloro, SLOT(updateDelay(int)), Qt::QueuedConnection);
	connect(commandHandler, SIGNAL(deleteCHThread()), chThread, SLOT(quit()));
	connect(commandHandler, SIGNAL(updateDebugConsole(QString)), this, SLOT(updateDebugConsole(QString)), Qt::QueuedConnection);
	connect(gayfloro, SIGNAL(onMessage(QString, QString, QString)), commandHandler, SLOT(onMessage(QString, QString, QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(disconnectCH()), commandHandler, SLOT(disconnect()), Qt::QueuedConnection);
	connect(this, SIGNAL(addMod(QString, QString)), commandHandler, SLOT(addMod(QString, QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(isMod(QString, QString, bool*)), commandHandler, SLOT(isMod(QString, QString, bool*)), Qt::BlockingQueuedConnection);




	botThread->start();
	chThread->start();
}

MainWindow::~MainWindow()
{
	// Delete Bot Thread
	emit disconnectBot();
	// Delete CommandHandler Thread
	emit disconnectCH();

    delete ui;
}

void MainWindow::updateConsoles(QString readline, QString channel, QString sender, QString message)
{
    // fix mod files getting filled with whitespace

    // Just check if mod QString length is not equal to zero instead of shitty pointer fuckery


    // QDateTime::currentDateTime().toString("hh:mm  ")
    //qDebug() << readline;
    bool isUserMessage = true;
    // remove \n\r off of message and channel"
    message = message.trimmed();
    channel = channel.trimmed();

    if ((readline.contains("JOIN") || readline.contains("PART") || readline.contains("MODE")) && !readline.contains("PRIVMSG"))
        isUserMessage = false;

    if (!isUserMessage && readline.contains("MODE"))
    {
        QString mod;
        for (int i = 0; i < readline.length(); i++)
        {
            if (readline.toStdString().c_str()[i] == '+' && readline.toStdString().c_str()[i + 1] == 'o')
                mod = readline.mid(i + 3);
        }
        if (mod.length() > 0)
        {
            bool b = false;
            if (channel == "#sonfloro")
            {
                emit isMod(mod, channel, &b);
                if (!b)
                {
                    qDebug() << "Mod: " << mod << " channel: " << channel << " readline: " << readline << " message: " << message;
                    emit addMod(mod, channel);
                }
            }
            else if (channel == "#itzmisszoey")
            {
                emit isMod(mod, channel, &b);
                if (!b)
                {
                    qDebug() << "Mod: " << mod << " channel: " << channel << " readline: " << readline << " message: " << message;
                    emit addMod(mod, channel);
                }
            }
            else if (channel == "#lumiriss")
            {
                emit isMod(mod, channel, &b);
                if (!b)
                {
                    qDebug() << "Mod: " << mod << " channel: " << channel << " readline: " << readline << " message: " << message;
                    emit addMod(mod, channel);
                }
            }
            else if (channel == "#whatthehellshappened")
            {
                emit isMod(mod, channel, &b);
                if (!b)
                {
                    qDebug() << "Mod: " << mod << " channel: " << channel << " readline: " << readline << " message: " << message;
                    emit addMod(mod, channel);
                }
            }
            else if (channel == "#armorysons")
            {
                emit isMod(mod, channel, &b);
                if (!b)
                {
                    qDebug() << "Mod: " << mod << " channel: " << channel << " readline: " << readline << " message: " << message;
                    emit addMod(mod, channel);
                }
            }
            else if (channel == "#realmcopier")
            {
                emit isMod(mod, channel, &b);
                if (!b)
                {
                    qDebug() << "Mod: " << mod << " channel: " << channel << " readline: " << readline << " message: " << message;
                    emit addMod(mod, channel);
                }
            }
        }

    }

    if (channel == "#sonfloro")
    {
        if (isUserMessage)
            ui->console_sonfloro->append(QDateTime::currentDateTime().toString("hh:mm  ") + sender + ": " + message);
        else
            ui->console_sonfloro->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
    }
    else if (channel == "#itzmisszoey")
    {
        if (isUserMessage)
            ui->console_zoey->append(QDateTime::currentDateTime().toString("hh:mm  ") + sender + ": " + message);
        else
            ui->console_zoey->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
    }
    else if (channel == "#lumiriss")
    {
        if (isUserMessage)
            ui->console_lumiriss->append(QDateTime::currentDateTime().toString("hh:mm  ") + sender + ": " + message);
        else
            ui->console_lumiriss->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
    }
    else if (channel == "#whatthehellshappened")
    {
        if (isUserMessage)
            ui->console_whatthehellshappened->append(QDateTime::currentDateTime().toString("hh:mm  ") + sender + ": " + message);
        else
            ui->console_whatthehellshappened->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
    }
    else if (channel == "#armorysons")
    {
        if (isUserMessage)
            ui->console_armorysons->append(QDateTime::currentDateTime().toString("hh:mm  ") + sender + ": " + message);
        else
            ui->console_armorysons->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
    }
    else if (channel == "#realmcopier")
    {
        if (isUserMessage)
            ui->console_realmcopier->append(QDateTime::currentDateTime().toString("hh:mm  ") + sender + ": " + message);
        else
            ui->console_realmcopier->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
    }
    else if (readline == "PING :tmi.twitch.tv")
        ui->console_main->append(readline);
    else
        ui->console_main->append(QDateTime::currentDateTime().toString("hh:mm  ") + readline);
}

void MainWindow::writePong()
{
    ui->console_main->append("PONG :irc.twitch.tv");
}

void MainWindow::writeStatusMessage(QString message)
{
    ui->console_main->append(message);
}

void MainWindow::on_chatButton_clicked()
{
    QString message = ui->chatLineEdit->text();
    QString channel = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    if (message.size() > 0)
    {
        emit sendCustomMessage(channel, message);
        this->updateConsoles("", channel, "gayfloro", message);
    }
    ui->chatLineEdit->clear();
}

void MainWindow::on_chatLineEdit_returnPressed()
{
    QString message = ui->chatLineEdit->text();
    QString channel = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    if (message.size() > 0)
    {
        emit sendCustomMessage(channel, message);
        this->updateConsoles("", channel, "gayfloro", message);
    }
    ui->chatLineEdit->clear();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (QString::compare(ui->tabWidget->tabText(index), "Main", Qt::CaseInsensitive) == 0)
    {
        ui->chatLineEdit->setEnabled(false);
        ui->chatButton->setEnabled(false);
    }
    else if (ui->chatLineEdit->isEnabled() == false)
    {
        ui->chatLineEdit->setEnabled(true);
        ui->chatButton->setEnabled(true);
    }
}


void MainWindow::updateDebugConsole(QString message)
{
	ui->console_debug->append(message);
}
