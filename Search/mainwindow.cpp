#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <QString>
#include <fstream>
#include <QFile>
#include <map>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

vector<std::string> readFromFile(const QString& filename) {
    QFile file(filename);
    vector<string> lines;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cerr << "Не удалось открыть файл: " << filename.toStdString() << endl;
        return lines;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.push_back(line.toStdString());
    }

    return lines;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int levenshteinDistance(const string& s1, const string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({ dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1 });
            }
        }
    }
    return dp[m][n];
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    std::map<QChar, QChar> layoutMap;
    layoutMap[QChar('q')] = QChar(L'й');
    layoutMap[QChar('w')] = QChar(L'ц');
    layoutMap[QChar('e')] = QChar(L'у');
    layoutMap[QChar('r')] = QChar(L'к');
    layoutMap[QChar('t')] = QChar(L'е');
    layoutMap[QChar('y')] = QChar(L'н');
    layoutMap[QChar('u')] = QChar(L'г');
    layoutMap[QChar('i')] = QChar(L'ш');
    layoutMap[QChar('o')] = QChar(L'щ');
    layoutMap[QChar('p')] = QChar(L'з');
    layoutMap[QChar('a')] = QChar(L'ф');
    layoutMap[QChar('s')] = QChar(L'ы');
    layoutMap[QChar('d')] = QChar(L'в');
    layoutMap[QChar('f')] = QChar(L'а');
    layoutMap[QChar('g')] = QChar(L'п');
    layoutMap[QChar('h')] = QChar(L'р');
    layoutMap[QChar('j')] = QChar(L'о');
    layoutMap[QChar('k')] = QChar(L'л');
    layoutMap[QChar('l')] = QChar(L'д');
    layoutMap[QChar('z')] = QChar(L'я');
    layoutMap[QChar('x')] = QChar(L'ч');
    layoutMap[QChar('c')] = QChar(L'с');
    layoutMap[QChar('v')] = QChar(L'м');
    layoutMap[QChar('b')] = QChar(L'и');
    layoutMap[QChar('n')] = QChar(L'т');
    layoutMap[QChar('m')] = QChar(L'ь');

    QString resourcePath = "text.txt";
    vector<string> lines = readFromFile(resourcePath);
    string str;
    string line = arg1.toStdString();
    string ss1, ss2;
    int int_max1 = INT_MAX, int_max2 = INT_MAX;

    // Найти последнюю позицию пробела
    size_t lastSpacePos = line.find_last_of(' ');

    // Извлечь последнее слово
    if (lastSpacePos == string::npos) {
        // Если пробелов нет, вся строка является последним словом
        str = line;
    } else {
        // Извлечь подстроку после последнего пробела
        str = line.substr(lastSpacePos + 1);
    }

    QString line1 = QString::fromStdString(str);
    for(size_t i = 0; i < line1.size(); i++) {
        QChar currentChar = line1[i];
        if (layoutMap.find(currentChar) != layoutMap.end()) {
            line1[i] = layoutMap[currentChar];
        }
    }

    str = line1.toStdString();
    bool wordFound = false;
    int minDistance = INT_MAX;
    string closestMatch;
    // Проверка наличия слова в файле
    for (const string& fileLine : lines) {
        if (str == fileLine) {
            wordFound = true;
            break;
        }
    }

    // Установка цвета текста в зависимости от наличия слова
    QPalette palette = ui->lineEdit->palette();
    if (wordFound) {
        palette.setColor(QPalette::Text, Qt::black);
        ui->lineEdit->setPalette(palette);
    } else {
        palette.setColor(QPalette::Text, Qt::red);
        ui->lineEdit->setPalette(palette);
    }
    for (const string& line : lines) {
        int distance = levenshteinDistance(str, line);
        if (distance < minDistance) {
            minDistance = distance;
            closestMatch = line;
        }
        if (distance < int_max1 && closestMatch != line) {
            int_max1 = distance;
            ss1 = line;
        }
        if (distance < int_max2 && closestMatch != line && ss1 != line) {
            int_max2 = distance;
            ss2 = line;
        }
    }

    if(str == "") {
        closestMatch = "";
        ss1 = "";
        ss2 = "";
    }
    QString result1 = QString::fromStdString(ss1);
    QString result2 = QString::fromStdString(ss2);
    QString result = QString::fromStdString(closestMatch);
    ui->pushButton->setText(result);
    ui->pushButton1_2->setText(result1);
    ui->pushButton1_3->setText(result2);
}

void MainWindow::on_pushButton1_2_clicked()
{
    QString stri = ui->pushButton1_2->text();
    string stri1 = stri.toStdString();
    QString str11 = ui->lineEdit->text();
    string line = str11.toStdString();
    // Найти последнюю позицию пробела
    size_t lastSpacePos = line.find_last_of(' ');
    // Извлечь последнее слово
    if (lastSpacePos == string::npos) {
        ui->lineEdit->setText(stri);
    } else {
        // Извлечь подстроку после последнего пробела
        line = line.substr(0,lastSpacePos + 1);
        line += stri1;
        QString strii = QString::fromStdString(line);
        ui->lineEdit->setText(strii);
    }
    QPalette palette = ui->lineEdit->palette();
    palette.setColor(QPalette::Text, Qt::black);
    ui->lineEdit->setPalette(palette);
}

void MainWindow::on_pushButton_clicked()
{
    QString stri = ui->pushButton->text();
    string stri1 = stri.toStdString();
    QString str11 = ui->lineEdit->text();
    string line = str11.toStdString();
    // Найти последнюю позицию пробела
    size_t lastSpacePos = line.find_last_of(' ');
    // Извлечь последнее слово
    if (lastSpacePos == string::npos) {
        ui->lineEdit->setText(stri);
    } else {
        // Извлечь подстроку после последнего пробела
        line = line.substr(0,lastSpacePos + 1);
        line += stri1;
        QString strii = QString::fromStdString(line);
        ui->lineEdit->setText(strii);
    }
    QPalette palette = ui->lineEdit->palette();
    palette.setColor(QPalette::Text, Qt::black);
    ui->lineEdit->setPalette(palette);
}

void MainWindow::on_pushButton1_3_clicked()
{
    QString stri = ui->pushButton1_3->text();
    string stri1 = stri.toStdString();
    QString str11 = ui->lineEdit->text();
    string line = str11.toStdString();
    // Найти последнюю позицию пробела
    size_t lastSpacePos = line.find_last_of(' ');
    // Извлечь последнее слово
    if (lastSpacePos == string::npos) {
        ui->lineEdit->setText(stri);
    } else {
        // Извлечь подстроку после последнего пробела
        line = line.substr(0,lastSpacePos + 1);
        line += stri1;
        QString strii = QString::fromStdString(line);
        ui->lineEdit->setText(strii);
    }
    QPalette palette = ui->lineEdit->palette();
    palette.setColor(QPalette::Text, Qt::black);
    ui->lineEdit->setPalette(palette);
}


void MainWindow::on_pushButton1_clicked()
{}


void MainWindow::on_pushButton_2_clicked()
{
    QString arg1 = ui->lineEdit->text();
    string line = arg1.toStdString();
    string str;

    // Найти последнюю позицию пробела
    size_t lastSpacePos = line.find_last_of(' ');

    // Извлечь последнее слово
    if (lastSpacePos == string::npos) {
        // Если пробелов нет, вся строка является последним словом
        str = line;
    } else {
        // Извлечь подстроку после последнего пробела
        str = line.substr(lastSpacePos + 1);
    }

    ofstream os("text.txt", ios::app);

    os << str << '\n'; // Записываем слово с символом новой строки

    os.close();
    QPalette palette = ui->lineEdit->palette();
    palette.setColor(QPalette::Text, Qt::black);
    ui->lineEdit->setPalette(palette);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str = "Вы нашли ";
    QString str2 = ui->lineEdit->text();
    str += str2;
    QMessageBox::information(this, "Поздравляю!", str);
}

