#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>
#include <string>
#include <cstring>
#include <QString>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setGeometry(QRect(0, 0, 1500, 1500));
    ui->setupUi(this);

    image = QImage(1500, 1500, QImage::Format_ARGB32);
    image.fill(Qt::white);


    drawing = false;

    pen.setColor(Qt::black);
    pen.setWidth(2);
    button_color_change();
    Menu_connect();

    startTime = QDateTime::currentDateTime();
    logTime("Program start time: ", startTime);

    if (readFirstLaunch().isEmpty()) {
        saveFirstLaunch();
    }
    saveLastLaunch();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, image);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawing = true;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing) {
        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update();
    }
}

void MainWindow::Black()
{
    pen.setColor(Qt::black);
}

void MainWindow::Blue()
{
    pen.setColor(Qt::blue);
}

void MainWindow::Green()
{
    pen.setColor(Qt::green);
}

void MainWindow::Red()
{
    pen.setColor(Qt::red);
}

void MainWindow::DefaultPen()
{
    pen.setWidth(2);
}


void MainWindow::BoldPen()
{
    pen.setWidth(4);
}


void MainWindow::Save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("PNG Files (*.png);;JPEG Files (*.jpg *.jpeg)"));

    if (!fileName.isEmpty()) {
        if (image.save(fileName)) {
            QMessageBox::information(this, tr("Image Saved"), tr("The image has been saved successfully."));
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Failed to save the image."));
        }
    }

}


void MainWindow::Load()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("PNG Files (*.png);;JPEG Files (*.jpg *.jpeg)"));

    if (!fileName.isEmpty()) {
        QImage loadedImage;
        if (loadedImage.load(fileName)) {
            image = loadedImage;
            update();
            QMessageBox::information(this, tr("Image Loaded"), tr("The image has been loaded successfully."));
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Failed to load the image."));
        }
    }
}


void MainWindow::Update()
{
    image.fill(Qt::white);
    update();
}


void MainWindow::Help()
{
    QMessageBox::information(this, tr("Help"),
                             tr("ЛКМ - рисуем\n"
                                "Кнопка UPDATE и Кнопка esc - стирает всё\n"
                                "Кнопка SAVE - сохраняет вашу работу\n"
                                "Кнопка LOAD - загружает работу на экран\n"
                                "Кнопки RED, BLUE, GREEN, BLACK - Кнопки изменения цвета"));
}

void MainWindow::Data()
{
    image.fill(Qt::white);
    DateTimeWidget *datetimewidget = new DateTimeWidget(this);
    //textEdit->show();
    datetimewidget->show();
    datetimewidget->setFixedWidth(400);
    datetimewidget->setFixedHeight(400);
    datetimewidget->move(300, 100);
    datetimewidget->setVisible(true);
}


void MainWindow::button_color_change()
{
    ui->menubar->setStyleSheet("background-color: grey; color: black");
    ui->menuEND_Test->setStyleSheet("background-color: grey; color: black");
}


void MainWindow::Menu_connect()
{
    connect(ui->actionUPDATE,&QAction::triggered, this, &MainWindow::Update);
    connect(ui->actionHELP,&QAction::triggered, this, &MainWindow::Help);
    connect(ui->actionSAVE_2,&QAction::triggered, this, &MainWindow::Save);
    connect(ui->actionLOAD_2,&QAction::triggered, this, &MainWindow::Load);
    connect(ui->actionDATA,&QAction::triggered, this, &MainWindow::Data);
    connect(ui->actionBLACK,&QAction::triggered, this, &MainWindow::Black);
    connect(ui->actionBLUE,&QAction::triggered, this, &MainWindow::Blue);
    connect(ui->actionRED,&QAction::triggered, this, &MainWindow::Red);
    connect(ui->actionGREEN,&QAction::triggered, this, &MainWindow::Green);
    connect(ui->actionBOLD_PEN,&QAction::triggered, this, &MainWindow::BoldPen);
    connect(ui->actionDEFAULT_PEN,&QAction::triggered, this, &MainWindow::DefaultPen);
    connect(ui->actionEndBar,&QAction::triggered, this, &MainWindow::EndTest);

}

void MainWindow::logTime(const QString &message, const QDateTime &time)
{
    QFile file("logss.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << message << time.toString("yyyy-MM-dd HH:mm:ss") << "\n";
    }
}



void MainWindow::EndTest()
{
    QDateTime endTime = QDateTime::currentDateTime();
    logTime("Program end time: ", endTime);

    qint64 duration = startTime.msecsTo(endTime);
    QFile file("log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Program start time: " << startTime.toString("yyyy-MM-dd HH:mm:ss") << "\n";
        out << "Program end time: " << endTime.toString("yyyy-MM-dd HH:mm:ss") << "\n";
        out << "Duration: " << QTime::fromMSecsSinceStartOfDay(duration).toString("HH:mm:ss") << "\n";
    }
    displayStatistics();
}

void MainWindow::displayStatistics()
{
    QString firstLaunch = readFirstLaunch();
    QString lastLaunch = readLastLaunch();

    QString statistics = QString("Statistics:\n\n"
                                 "Первый запуск:\n%1\n\n"
                                 "Последний запуск:\n%2\n\n")
                             .arg(firstLaunch)
                             .arg(lastLaunch);

    QMessageBox::information(this, tr("Statistics"), statistics);
    QApplication::quit();
}

void MainWindow::saveFirstLaunch()
{
    QFile file("first_launch.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Program start time: " << startTime.toString("yyyy-MM-dd HH:mm:ss") << "\n";
    }
}

void MainWindow::saveLastLaunch()
{
    QFile file("last_launch.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Program start time: " << startTime.toString("yyyy-MM-dd HH:mm:ss") << "\n";
    }
}


QString MainWindow::readFirstLaunch()
{
    QFile file("first_launch.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    return in.readAll();
}

QString MainWindow::readLastLaunch()
{
    QFile file("last_launch.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    return in.readAll();
}




