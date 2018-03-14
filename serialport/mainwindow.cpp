#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new serial_setting;
    connect(settings->pushbutton,&QPushButton::clicked,this,&MainWindow::pushbuttonclicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readMyCom(void)
{
    QByteArray temp;
    temp = serialport->readAll();
    ui->textBrowser->append(temp);
}
#if 0
#include <QTextCodec>

inline QString GBK2UTF8(const QString &inStr)
{
    QTextCodec *gbk = QTextCodec::codecForName("GB18030");
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");

    QString g2u = gbk->toUnicode(gbk->fromUnicode(inStr));			  // gbk  convert utf8
    return g2u;
}

inline QString UTF82GBK(const QString &inStr)
{
    QTextCodec *gbk = QTextCodec::codecForName("GB18030");
    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");

    QString utf2gbk = gbk->toUnicode(inStr.toLocal8Bit());
    return utf2gbk;
}

inline std::string gbk2utf8(const QString &inStr)
{
    return GBK2UTF8(inStr).toStdString();
}

inline QString utf82gbk(const std::string &inStr)
{
    QString str = QString::fromStdString(inStr);

    return UTF82GBK(str);
}
#endif

void MainWindow::on_lineEdit_returnPressed()
{
    if (can_write == false)
    {
         ui->textBrowser->append(tr("串口出错"));
    }
    else
    {
        serialport->write(QByteArray(ui->lineEdit->text().toLatin1()));
    }
}

void MainWindow::pushbuttonclicked()
{
    qDebug()<< "pushbuttonclicked";

    settings->close();
    serialport = new QSerialPort();

    serialport->setPortName(settings->combobox[0]->currentText());
    serialport->setBaudRate(settings->combobox[1]->currentText().toInt());
    //设置串口数据位
    if (settings->combobox[2]->currentText() == "5")
        serialport->setDataBits(QSerialPort::Data5);
    else if (settings->combobox[2]->currentText() == "6")
        serialport->setDataBits(QSerialPort::Data6);
    else if (settings->combobox[2]->currentText() == "7")
        serialport->setDataBits(QSerialPort::Data7);
    else if (settings->combobox[2]->currentText() == "8")
        serialport->setDataBits(QSerialPort::Data8);
    else
        serialport->setDataBits(QSerialPort::UnknownDataBits);

    //设置串口停止位
    if (settings->combobox[3]->currentText() == "1")
        serialport->setStopBits(QSerialPort::OneStop);
    else if (settings->combobox[3]->currentText() == "1.5")
        serialport->setStopBits(QSerialPort::OneAndHalfStop);
    else if (settings->combobox[3]->currentText() == "2")
        serialport->setStopBits(QSerialPort::TwoStop);
    else
        serialport->setStopBits(QSerialPort::UnknownStopBits);

    //设置串口校验位
    if (settings->combobox[4]->currentText() == "none")
        serialport->setParity(QSerialPort::NoParity);
    else if (settings->combobox[4]->currentText() == "odd")
        serialport->setParity(QSerialPort::OddParity);
    else if (settings->combobox[4]->currentText() == "even")
        serialport->setParity(QSerialPort::EvenParity);
    else
        serialport->setParity(QSerialPort::UnknownParity);

    if (serialport->open(QSerialPort::ReadWrite))
    {
        qDebug("打开成功");
        ui->textBrowser->append("打开成功");
    }
    else
    {
        qDebug("打开失败");
        ui->textBrowser->append("打开失败");
    }
    connect(serialport,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(serErrorinof(QSerialPort::SerialPortError)));
    connect(serialport,&QSerialPort::readyRead,this,&MainWindow::readMyCom);

}

void MainWindow::on_action_triggered()
{
    settings->show();
    qDebug()<<"OK!";
}

void MainWindow::serErrorinof(QSerialPort::SerialPortError)
{
    qDebug()<< "serErrorinof";
    can_write = false;
}
