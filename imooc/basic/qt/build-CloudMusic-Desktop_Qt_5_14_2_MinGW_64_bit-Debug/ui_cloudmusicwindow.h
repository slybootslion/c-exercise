/********************************************************************************
** Form generated from reading UI file 'cloudmusicwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDMUSICWINDOW_H
#define UI_CLOUDMUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloudMusicWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer_9;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CloudMusicWindow)
    {
        if (CloudMusicWindow->objectName().isEmpty())
            CloudMusicWindow->setObjectName(QString::fromUtf8("CloudMusicWindow"));
        CloudMusicWindow->resize(609, 522);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CloudMusicWindow->sizePolicy().hasHeightForWidth());
        CloudMusicWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(CloudMusicWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{\n"
"border-image: url(:/images/background.png);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        verticalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_9);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/play-pri.png);"));

        gridLayout->addWidget(pushButton_5, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 6, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setStyleSheet(QString::fromUtf8("border-image: url(:/images/cycle-play.png);"));

        gridLayout->addWidget(pushButton_8, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 2, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 2, 8, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/play-next.png);"));

        gridLayout->addWidget(pushButton_6, 1, 6, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setStyleSheet(QString::fromUtf8("border-image: url(:/images/default-music-list.png);"));

        gridLayout->addWidget(pushButton_7, 1, 8, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/pause.png);"));

        gridLayout->addWidget(pushButton, 0, 4, 3, 1);

        verticalSpacer_7 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 0, 8, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 7, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(4, 5);

        verticalLayout->addLayout(gridLayout);

        verticalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(lineEdit);

        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidget_2 = new QTableWidget(tab_2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_3->addWidget(tableWidget_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 16);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_4->addWidget(textEdit);

        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        CloudMusicWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CloudMusicWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 609, 23));
        CloudMusicWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CloudMusicWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CloudMusicWindow->setStatusBar(statusbar);

        retranslateUi(CloudMusicWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CloudMusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CloudMusicWindow)
    {
        CloudMusicWindow->setWindowTitle(QCoreApplication::translate("CloudMusicWindow", "CloudMusicWindow", nullptr));
        pushButton_5->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("CloudMusicWindow", "00:00", nullptr));
        label_2->setText(QCoreApplication::translate("CloudMusicWindow", "00:00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CloudMusicWindow", "\346\234\254\345\234\260\346\255\214\346\233\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CloudMusicWindow", "\347\275\221\347\273\234\346\255\214\346\233\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CloudMusicWindow: public Ui_CloudMusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDMUSICWINDOW_H
