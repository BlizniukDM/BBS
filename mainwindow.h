/*После экскурсии в понедельник сбросить на почту zubovich2023 первую часть ознакомительного отчёта*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dateTimeWidget.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPen>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void button_color_change();
    void Menu_connect();
    void logTime(const QString &message, const QDateTime &time);
    void displayStatistics();
    void saveFirstLaunch();
    void saveLastLaunch();

private slots:
    void Black();

    void Blue();

    void Green();

    void Red();

    void DefaultPen();

    void BoldPen();

    void Save();

    void Load();

    void Update();

    void Help();

    void Data();

    void EndTest();

private:
    Ui::MainWindow *ui;
    QImage image;
    QPainter painter;
    QPoint lastPoint;
    bool drawing;
    QPen pen;
    QDateTime startTime;
    QString readFirstLaunch();
    QString readLastLaunch();
};

#endif // MAINWINDOW_H
