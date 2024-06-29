#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDate>
#include <QTime>
#include <QDialog>
#include <QTextEdit>
#include <QLabel>

class DateTimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DateTimeWidget(QWidget *parent = nullptr);

private slots:
    void showCalendar();
    void updateDateTimeLineEdit();
    void validateAndUpdateDateTime();
    void on_dateTimeLineEdit_textEdited(const QString &arg1);
private:
    QLabel *validationLabel;
    QTextEdit *textEdit;
    QLineEdit *dateTimeLineEdit;
    QPushButton *calendarButton;
    QVBoxLayout *mainLayout;
    QDate selectedDate;
    QTime selectedTime;
};

#endif // DATETIMEWIDGET_H
