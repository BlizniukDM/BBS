#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_ChangeColorButton_clicked()
{
    pen.setColor(Qt::black);

}

void MainWindow::on_ChangeColorButton_2_clicked()
{
    pen.setColor(Qt::blue);
}

void MainWindow::on_ChangeColorButton_3_clicked()
{
    pen.setColor(Qt::green);
}

void MainWindow::on_ChangeColorButton_4_clicked()
{
    pen.setColor(Qt::red);
}

void MainWindow::on_DefaultPenButton_clicked()
{
    pen.setWidth(2);
}


void MainWindow::on_BoldPenButton_clicked()
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


void MainWindow::button_color_change()
{
    ui->ChangeColorButton->setStyleSheet("background-color: grey; color: black");
    ui->ChangeColorButton_2->setStyleSheet("background-color: grey; color: black");
    ui->ChangeColorButton_3->setStyleSheet("background-color: grey; color: black");
    ui->ChangeColorButton_4->setStyleSheet("background-color: grey; color: black");
    ui->BoldPenButton->setStyleSheet("background-color: grey; color: black");\
    ui->DefaultPenButton->setStyleSheet("background-color: grey; color: black");
    ui->menubar->setStyleSheet("background-color: grey; color: black");
    ui->Testbutton->setStyleSheet("background-color: grey; color: black");
}


void MainWindow::Menu_connect()
{
    connect(ui->actionUPDATE,&QAction::triggered, this, &MainWindow::Update);
    connect(ui->actionHELP,&QAction::triggered, this, &MainWindow::Help);
    connect(ui->actionSAVE_2,&QAction::triggered, this, &MainWindow::Save);
    connect(ui->actionLOAD_2,&QAction::triggered, this, &MainWindow::Load);

}

void MainWindow::logTime(const QString &message, const QDateTime &time)
{
    QFile file("logss.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << message << time.toString("yyyy-MM-dd HH:mm:ss") << "\n";
    }
}



void MainWindow::on_Testbutton_clicked()
{
    QDateTime endTime = QDateTime::currentDateTime();
    logTime("Program end time: ", endTime);

    qint64 duration = startTime.msecsTo(endTime);
    QFile file("log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Duration: " << QTime::fromMSecsSinceStartOfDay(duration).toString("HH:mm:ss") << "\n";
    }

    saveLongestLaunch();
    displayStatistics();
}

void MainWindow::displayStatistics()
{
    QString firstLaunch = readFirstLaunch();
    QString lastLaunch = readLastLaunch();
    QString longestLaunch = readLongestLaunch();

    QString statistics = QString("Statistics:\n\n"
                                 "First Launch:\n%1\n\n"
                                 "Last Launch:\n%2\n\n"
                                 "Longest Duration:\n%3")
                             .arg(firstLaunch)
                             .arg(lastLaunch)
                             .arg(longestLaunch);

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

void MainWindow::saveLongestLaunch()
{
    QFile file("log.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString logContent = in.readAll();
    file.close();

    QStringList lines = logContent.split('\n');
    QDateTime currentStartTime, currentEndTime;
    qint64 maxDuration = 0;

    for (int i = 0; i < lines.size(); ++i) {
        if (lines[i].startsWith("Program start time: ")) {
            currentStartTime = QDateTime::fromString(lines[i].mid(19), "yyyy-MM-dd HH:mm:ss");
        } else if (lines[i].startsWith("Program end time: ")) {
            currentEndTime = QDateTime::fromString(lines[i].mid(17), "yyyy-MM-dd HH:mm:ss");
            if (currentStartTime.isValid()) {
                qint64 duration = currentStartTime.msecsTo(currentEndTime);
                if (duration > maxDuration) {
                    maxDuration = duration;
                }
            }
        }
    }

    // Read the previous longest duration
    qint64 previousMaxDuration = 0;
    QFile longestLaunchFile("longest_launch.txt");
    if (longestLaunchFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&longestLaunchFile);
        QString firstLine = in.readLine(); // Start time
        QString secondLine = in.readLine(); // End time
        QString thirdLine = in.readLine(); // Duration

        if (!thirdLine.isEmpty()) {
            QTime previousMaxDurationTime = QTime::fromString(thirdLine.mid(10), "HH:mm:ss");
            previousMaxDuration = QTime(0, 0).msecsTo(previousMaxDurationTime);
        }
        longestLaunchFile.close();
    }

    // Update the longest launch file if the current max duration is greater than the previous
    if (maxDuration > previousMaxDuration) {
        if (longestLaunchFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&longestLaunchFile);
            out << "Program start time: " << currentStartTime.toString("yyyy-MM-dd HH:mm:ss") << "\n";
            out << "Program end time: " << currentEndTime.toString("yyyy-MM-dd HH:mm:ss") << "\n";
            out << "Duration: " << QTime::fromMSecsSinceStartOfDay(maxDuration).toString("HH:mm:ss") << "\n";
        }
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

QString MainWindow::readLongestLaunch()
{
    QFile file("longest_launch.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    return in.readAll();
}



