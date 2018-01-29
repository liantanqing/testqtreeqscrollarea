/********************************************************************************
** Form generated from reading UI file 'testqtreeqscrollarea.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQTREEQSCROLLAREA_H
#define UI_TESTQTREEQSCROLLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQTreeQScrollAreaClass
{
public:
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestQTreeQScrollAreaClass)
    {
        if (TestQTreeQScrollAreaClass->objectName().isEmpty())
            TestQTreeQScrollAreaClass->setObjectName(QStringLiteral("TestQTreeQScrollAreaClass"));
        TestQTreeQScrollAreaClass->resize(700, 570);
        centralWidget = new QWidget(TestQTreeQScrollAreaClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestQTreeQScrollAreaClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestQTreeQScrollAreaClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestQTreeQScrollAreaClass->setStatusBar(statusBar);

        retranslateUi(TestQTreeQScrollAreaClass);

        QMetaObject::connectSlotsByName(TestQTreeQScrollAreaClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestQTreeQScrollAreaClass)
    {
        TestQTreeQScrollAreaClass->setWindowTitle(QApplication::translate("TestQTreeQScrollAreaClass", "TestQTreeQScrollArea", 0));
    } // retranslateUi

};

namespace Ui {
    class TestQTreeQScrollAreaClass: public Ui_TestQTreeQScrollAreaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQTREEQSCROLLAREA_H
