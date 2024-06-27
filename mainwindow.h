/*После экскурсии в понедельник сбросить на почту zubovich2023 первую часть ознакомительного отчёта*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void parseLogFile(const QString &logContent, QString &firstLaunch, QString &lastLaunch, QString &longestDuration);

private slots:
    void on_ChangeColorButton_clicked();

    void on_ChangeColorButton_2_clicked();

    void on_ChangeColorButton_3_clicked();

    void on_ChangeColorButton_4_clicked();

    void on_DefaultPenButton_clicked();

    void on_BoldPenButton_clicked();




    void Save();

    void Load();

    void Update();

    void Help();



    void on_Testbutton_clicked();

private:
    Ui::MainWindow *ui;
    QImage image;
    QPainter painter;
    QPoint lastPoint;
    bool drawing;
    QPen pen;
    QDateTime startTime;
};

#endif // MAINWINDOW_H
