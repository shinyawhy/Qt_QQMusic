#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "form.h"
#include "ui_form.h"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QMediaPlayer>
#include <QStandardItemModel>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *NAM;
    QString downloadPath, sstyle, guid;
    QMediaPlayer *player;
    QLabel *label_lyric,*label_cover;
    Form *desktopLyric;
    QDialog *dialog_settings;
    QLineEdit *lineEditDownloadPath;
    QPushButton *pushButton_fontcolor;
    QPixmap pixmap_cover;
    int page;
    struct Lyric{
        QTime time;
        QString sentence;
    };
    QList<Lyric> lyrics;
    void getKey();
    QString readSettings(QString path,QString group, QString key);
    void writeSettings(QString path, QString group, QString key, QString value);
    void toplist();

private slots:
    void on_action_directory_triggered();
    void on_action_settings_triggered();
    void on_action_about_triggered();
    void on_pushButton_pageLast_clicked();
    void on_pushButton_pageNext_clicked();
    void on_pushButton_play_clicked();
    void on_pushButton_skipf_clicked();
    void on_pushButton_skipb_clicked();
    void on_pushButton_cover_clicked();
    void on_pushButton_lyric_clicked();
    void on_pushButton_download_clicked();
    void on_pushButton_fullscreen_clicked();
    void initSearch();
    void search();
    void copy(int,int);
    void playSong(int,int);
    void positionChange(qint64);
    void durationChange(qint64);
    void setSTime(int);
    void setMPPosition();
    void stateChange(QMediaPlayer::State);
    void updateProgress(qint64, qint64);
    void chooseFont();
    void chooseFontColor();
    void chooseDownloadPath();
    void replyAlbumPixmap(QNetworkReply *reply);
    void replyLyrics(QNetworkReply *reply);
    void enterFullscreen();
    void exitFullscreen();
};

#endif // MAINWINDOW_H
