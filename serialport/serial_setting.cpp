#include "serial_setting.h"

serial_setting::serial_setting(QWidget *parent) : QWidget(parent)
{
    gridlayout = new QGridLayout();
    for (int i = 0; i < 6; i++)
    {
        label[i] = new QLabel();
    }
    label[0]->setText("串口号");
    label[1]->setText("波特率");
    label[2]->setText("数据位");
    label[3]->setText("停止位");
    label[4]->setText("校验位");
    label[5]->setText("流控");

    for (int i = 0; i < 6; i++)
    {
        gridlayout->addWidget(label[i], i, 0, 1, 1);
    }

    for (int i =0; i < 6; i++)
    {
        combobox[i] = new QComboBox();
    }

    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    foreach(const QSerialPortInfo &serialportinfo, list)
    {
        combobox[0]->addItem(serialportinfo.portName());
    }

    QStringList boudrate;
    boudrate << QString(tr("9600")) << QString(tr("115200")) << QString("2400") << QString("4800");
    combobox[1]->addItems(boudrate);

    QStringList databits;
    databits << QString(tr("5")) << QString(tr("6")) << QString(tr("7")) << QString(tr("7")) << QString(tr("8"));
    combobox[2]->addItems(databits);

    QStringList stopbits;
    stopbits << QString(tr("1")) << QString(tr("1.5")) << QString(tr("2"));
    combobox[3]->addItems(stopbits);

    QStringList paritybit;
    paritybit << QString(tr("none")) << QString(tr("odd")) << QString(tr("even"));
    combobox[4]->addItems(paritybit);

    QStringList flowcontrol;
    flowcontrol << QString(tr("none")) << QString(tr("software")) << QString(tr("hardware"));
    combobox[5]->addItems(flowcontrol);

    for (int i = 0; i < 6; i++)
    {
        gridlayout->addWidget(combobox[i], i, 1, 1, 1);
    }

    pushbutton = new QPushButton(tr("确认"));
    gridlayout->addWidget(pushbutton, 6, 1, 1, 1);
    this->setLayout(gridlayout);
}
