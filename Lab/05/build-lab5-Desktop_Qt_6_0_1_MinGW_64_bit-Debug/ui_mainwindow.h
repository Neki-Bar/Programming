/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Load;
    QPushButton *Save;
    QPushButton *Encode;
    QPushButton *Decode;
    QPlainTextEdit *TextEdit;
    QLabel *label;
    QPushButton *Clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 170, 171, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Load = new QPushButton(verticalLayoutWidget);
        Load->setObjectName(QString::fromUtf8("Load"));

        verticalLayout->addWidget(Load);

        Save = new QPushButton(verticalLayoutWidget);
        Save->setObjectName(QString::fromUtf8("Save"));

        verticalLayout->addWidget(Save);

        Encode = new QPushButton(verticalLayoutWidget);
        Encode->setObjectName(QString::fromUtf8("Encode"));

        verticalLayout->addWidget(Encode);

        Decode = new QPushButton(verticalLayoutWidget);
        Decode->setObjectName(QString::fromUtf8("Decode"));

        verticalLayout->addWidget(Decode);

        TextEdit = new QPlainTextEdit(centralwidget);
        TextEdit->setObjectName(QString::fromUtf8("TextEdit"));
        TextEdit->setGeometry(QRect(350, 170, 351, 221));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 40, 521, 81));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(599, 410, 101, 22));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        Encode->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", nullptr));
        Decode->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", nullptr));
        TextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\265\321\201\321\214 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\216\321\202\321\201\321\217 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217!", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
