#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColor>


#include <bitset>
#include <vector>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Load, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->Save, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->Encode, &QPushButton::clicked, this, &MainWindow::encodeMsg);
    connect(ui->Decode, &QPushButton::clicked, this, &MainWindow::decodeMsg);
    connect(ui->TextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::msgChanged);
    connect(ui->Clear, &QPushButton::clicked, this, &MainWindow::clearText);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Допустимые форматы (*.png)");
    if( MainWindow::image.load(fileName) ){
    image.convertTo(QImage::Format_ARGB32);

    ui->label->setText("Изображение успешно загружено");
    }
    else ui->label->setText("Изображение не загружено");
}

void MainWindow::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Допустимые форматы (*.png)");
    if( MainWindow::image.save(fileName) ){
        ui->label->setText("Изображение успешно сохранено");
    }
    else ui->label->setText("Изображение не сохранено");
}

void MainWindow::encodeMsg()
{

    QString text = ui->TextEdit->toPlainText();
    QByteArray utext = text.toUtf8();
    int msgSize = utext.size();
    utext.reserve(utext.size()+3+4);

    utext.toHex();
    int textSize = utext.size()*8+24+32;
    int imageSize = MainWindow::image.width()*MainWindow::image.height()*3;

    if (imageSize < textSize){
        ui->label->setText("Ошибка. Не достаточно места!");
        return;
    }

    const uint first = 0x000000ff;
    const uint second = 0x0000ff00;
    const uint third = 0x00ff0000;
    const uint fourth = 0xff000000;

    QByteArray size;
    size.reserve(4);
    size.resize(4);
    size.toHex();
    size[3] = msgSize & first;
    size[2] = (msgSize & second) >> 8;
    size[1] = (msgSize & third) >> 16;
    size[0] = (msgSize & fourth) >> 24;

    QByteArray key;
    key.reserve(3);
    key.resize(3);
    key.toHex();
    key[0] = 0xe2;
    key[1] = 0x9d;
    key[2] = 0xa4;

    utext.prepend(size);
    utext.prepend(key);
    std::bitset<8> byte = utext[0];

    const int option = 0x01;
    int i = 0;
    for (int y = 0; y < MainWindow::image.height() && i < textSize; ++y){
        for (int x = 0; x < MainWindow::image.width() && i < textSize; ++x){
            QColor color = MainWindow::image.pixelColor(x, y);
            int red = (color.red()>>1)<<1;
            int green = (color.green()>>1)<<1;
            int blue = (color.blue()>>1)<<1;
            if (byte.test(7 - i%8) && i < textSize){
                red |= option;

            }
            ++i;
            if (i < textSize) byte = utext[i/8];

            if (byte.test(7 - i%8) && i < textSize){
                green |= option;

            }
            ++i;
            if (i < textSize) byte = utext[i/8];

            if (byte.test(7 - i%8) && i < textSize){
                blue |= option;

            }
            ++i;
            if (i < textSize) byte = utext[i/8];

            QColor colorSet(red, green, blue);
            MainWindow::image.setPixelColor(x, y, colorSet);
        }
    }
    ui->label->setText("Сообщение добавлено в картинку!");


}

int toNum(std::bitset<8> byte){
    int num = 0;
    for (int i = 0; i < 8; ++i){
        if (byte[i]) num += pow(2, i);
    }
    return num;
}


void MainWindow::decodeMsg()
{
    QByteArray key;
    key.reserve(3);
    key.resize(3);
    key[0] = 0xe2;
    key[1] = 0x9d;
    key[2] = 0xa4;

    const int option = 0x01;
    QByteArray keyFromIm;
    keyFromIm.reserve(3);
    keyFromIm.resize(3);
    int y = 0;
    int i = 0;
    std::bitset<8> byte;
    QColor color;
    for (int x = 0; x < 8; ++x){
        color = MainWindow::image.pixelColor(x, y);
        int red = color.red();
        if ((red & option) == 1) byte.set(7 - i%8);
        ++i;
        if (i%8 == 0 && i!=0){
            keyFromIm[i/8 - 1] = toNum(byte);
            byte.reset();
        }
        int green = color.green();
        if ((green & option) == 1) byte.set(7 - i%8);
        ++i;
        if (i%8 == 0){
            keyFromIm[i/8 - 1] = toNum(byte);
            byte.reset();
        }
        int blue = color.blue();
        if ((blue & option) == 1) byte.set(7 - i%8);
        ++i;
        if (i%8 == 0){
            keyFromIm[i/8 - 1] = toNum(byte);
            byte.reset();
        }

    }

    if (key != keyFromIm) {
        ui->label->setText("Сообщение не обнаружено");
        return;
    }

    QByteArray size;
    size.reserve(4);
    size.resize(4);
    i = 0;
    for (int x = 8; x < 19; ++x){
        color = MainWindow::image.pixelColor(x, y);
        int red = color.red();
        if ((red & option) == 1) byte.set(7 - i%8);
        ++i;
        if (i%8 == 0 && i!=0){
            size[i/8 - 1] = toNum(byte);
            byte.reset();
        }
        int green = color.green();
        if ((green & option) == 1) byte.set(7 - i%8);
        ++i;
        if (i%8 == 0){
            size[i/8 - 1] = toNum(byte);
            byte.reset();
        }
        if (i == 32) break;
        int blue = color.blue();
        if ((blue & option) == 1) byte.set(7 - i%8);
        ++i;
        if (i%8 == 0){
            size[i/8 - 1] = toNum(byte);
            byte.reset();
        }
    }
    size.toHex();

    int msgSize = 0;
    for (int i = 0; i < 4; ++i){
        byte = size[i];
        msgSize += toNum(byte)*pow(2, 24 - i*8);
    }

    ui->label->setText(QString("Присутствует сообщение длиной %1 байт").arg(msgSize));

    QByteArray Msg;
    Msg.reserve(msgSize);
    Msg.resize(msgSize);
    byte.reset();
    i = 0;
    for (int y = 0; y < MainWindow::image.height() && i < msgSize*8; ++y){
        for (int x = 0; x < MainWindow::image.width() && i < msgSize*8; ++x){
            if (i == 0) x = 18;
            color = MainWindow::image.pixelColor(x, y);
            if (i != 0){
                int red = color.red();
                if ((red & option) == 1) byte.set(7 - i%8);
                ++i;
                if (i%8 == 0 && i!=0){
                    Msg[i/8 - 1] = toNum(byte);
                    byte.reset();
                }
                int green = color.green();
                if ((green & option) == 1) byte.set(7 - i%8);
                ++i;
                if (i%8 == 0){
                    Msg[i/8 - 1] = toNum(byte);
                    byte.reset();
                }
            }
            int blue = color.blue();
            if ((blue & option) == 1) byte.set(7 - i%8);
            ++i;
            if (i%8 == 0 && i!=0){
                Msg[i/8 - 1] = toNum(byte);
                byte.reset();
            }
        }
    }
    QString text = QString::fromUtf8(Msg);
    ui->TextEdit->setPlainText(text);

}

void MainWindow::msgChanged()
{
    int imageSize = MainWindow::image.width()*MainWindow::image.height()*3;
    QString text = ui->TextEdit->toPlainText();
    QByteArray utext = text.toUtf8();
    int msgSize = utext.size()*8;
    int remainder = imageSize - 24 - 32 - msgSize;
    if(remainder >= 0){
        ui->label->setText(QString("Ещё можно ввести: %1 байт").arg(remainder));
    }
    else ui->label->setText(QString("Сообщение слишком большое"));

}

void MainWindow::clearText()
{
    ui->TextEdit->setPlainText("");
    ui->label->setText(QString("Здесь отображаются сообщения!"));
}






























