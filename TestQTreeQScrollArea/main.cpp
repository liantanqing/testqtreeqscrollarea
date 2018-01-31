#include "testqtreeqscrollarea.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QTranslator>
class LoadQSSStyleSheet
{
public:
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LoadQSSStyleSheet::setStyle(":/TestQTreeQScrollArea/MutilProductionTool.qss");
    QTranslator translator;
    translator.load("F:/SpecialFunctionCode/testqtreeqscrollareaqss/testqtreeqscrollarea/TestQTreeQScrollArea/testqtreeqscrollarea_zh.qm");
    a.installTranslator(&translator);
    LoadQSSStyleSheet::setStyle("F:/SpecialFunctionCode/testqtreeqscrollareaqss/testqtreeqscrollarea/TestQTreeQScrollArea/MutilProductionTool.qss");
    TestQTreeQScrollArea w;
    w.show();
    return a.exec();
}
