#ifndef SERIAL_SETTING_H
#define SERIAL_SETTING_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSerialPortInfo>
#include <QPushButton>

class serial_setting : public QWidget
{
    Q_OBJECT
public:
    explicit serial_setting(QWidget *parent = 0);
    QPushButton * pushbutton;
    QLabel * label[6];
    QComboBox * combobox[6];

private:
    QGridLayout * gridlayout;

signals:

public slots:
};

#endif // SERIAL_SETTING_H
