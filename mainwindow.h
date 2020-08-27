#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDateTime>
#include "commandhandler.h"
#include "bot.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void writePong();
    void updateConsoles(QString readline, QString channle, QString sender, QString message);
    void writeStatusMessage(QString message);
    void on_chatButton_clicked();
    void on_chatLineEdit_returnPressed();
    void on_tabWidget_currentChanged(int index);
	void updateDebugConsole(QString message);
signals:
    void disconnectBot(); // connected
    void disconnectCH();
    void sendCustomMessage(QString channel, QString message);
    void addMod(QString mod, QString channel);
    bool isMod(QString mod, QString channel, bool *b);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
