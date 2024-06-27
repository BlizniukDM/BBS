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

    logTime("Program started");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logTime(const QString& message) {
    QFile file("log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << message << ": " << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") << "\n";
        file.close();
    }
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
}


void MainWindow::Menu_connect()
{
    connect(ui->actionUPDATE,&QAction::triggered, this, &MainWindow::Update);
    connect(ui->actionHELP,&QAction::triggered, this, &MainWindow::Help);
    connect(ui->actionSAVE_2,&QAction::triggered, this, &MainWindow::Save);
    connect(ui->actionLOAD_2,&QAction::triggered, this, &MainWindow::Load);

}



void MainWindow::on_Testbutton_clicked()
{
    logTime("Testbutton clicked");
    QApplication::quit();
}

