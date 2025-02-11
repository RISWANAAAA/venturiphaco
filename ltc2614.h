#ifndef LTC2614_H
#define LTC2614_H

#include <QObject>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev2.1"
#define SPI_BITS_PER_WORD 8
#define SPI_SPEED 1000000

class ltc2614 : public QObject
{
    Q_OBJECT
public:
    explicit ltc2614(QObject *parent = nullptr);
    ~ltc2614();
    void openDevice();
    void writeDAC(int channel,uint16_t value);
    void writeDAC550x(int channel,uint16_t value);
    //uint16_t value=0x0000;

private:
    std::string device;
    int fd;
    uint32_t speed;
    uint8_t bits;

signals:

};

#endif // LTC2614_H
