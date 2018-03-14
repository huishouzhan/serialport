#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <serial_setting.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialport;
    serial_setting * settings;
    bool can_write = true;
public slots:
    void readMyCom(void);
    void on_lineEdit_returnPressed();
    void serErrorinof(QSerialPort::SerialPortError);
private slots:
    void pushbuttonclicked();
    void on_action_triggered();
};

#endif // MAINWINDOW_H
