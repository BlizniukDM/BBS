//зубович самый лучший
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
    } else if (event->button() == Qt::RightButton) {
        image.fill(Qt::white);
        update();
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

void MainWindow::button_color_change()
{
    ui->ChangeColorButton->setStyleSheet("background-color: grey; color: black");
    ui->ChangeColorButton_2->setStyleSheet("background-color: grey; color: black");
    ui->ChangeColorButton_3->setStyleSheet("background-color: grey; color: black");
    ui->ChangeColorButton_4->setStyleSheet("background-color: grey; color: black");
    ui->BoldPenButton->setStyleSheet("background-color: grey; color: black");\
    ui->DefaultPenButton->setStyleSheet("background-color: grey; color: black");
}


