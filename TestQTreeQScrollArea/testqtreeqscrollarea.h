#ifndef TESTQTREEQSCROLLAREA_H
#define TESTQTREEQSCROLLAREA_H

#include <QtWidgets/QMainWindow>
#include "ui_testqtreeqscrollarea.h"
#include "mytitlebar.h"
#include <QLayout>
#include <QTreeWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
class TestQTreeQScrollArea : public QMainWindow
{
    Q_OBJECT

public:
    TestQTreeQScrollArea(QWidget *parent = 0);
    ~TestQTreeQScrollArea();

public Q_SLOTS:
    void onItemClicked(QTreeWidgetItem * item, int column);
    void onNetworkModeRadioButton(bool checkState);
    void onSemiautomaticModelRadioButton(bool checkState);
    void onManualModelRadioButton(bool checkState);
    void initTitleBar();
    void onButtonMinClicked();
    void onButtonCloseClicked();
private:
    Ui::TestQTreeQScrollAreaClass ui;
    MyTitleBar* m_titleBar;
    QTreeWidget     *qtreeWidget;
    QTreeWidgetItem *basicSettings;
    QTreeWidgetItem *databaseSettings;
    QTreeWidgetItem *qrCodeSettings;

    QScrollArea     *scrollArea;
    QGroupBox       *functionCustom;
    QCheckBox       *checkBoxSavePic;
    QCheckBox       *checkBoxTestPinSwitch;
    QCheckBox       *checkBoxPressRubber;
    QCheckBox       *checkBoxDomeKeyTest;
    QLabel          *dataPathLabel;
    QLineEdit       *testDataFolderPath;
    QPushButton     *toolButton;
    QRadioButton    *manualModel;
    QRadioButton    *semiautomaticModel;
    QRadioButton    *networkMode;

    QGroupBox *autoMachineIP_Port;
    QLabel          *autoMachineip1;
    QLabel          *autoMachineport1;
    QLineEdit       *autoMachineIpLineEdit;
    QLineEdit       *autoMachinePortLineEdit;

    QLabel          *autoMachineip2;
    QLabel          *autoMachineport2;
    QLineEdit       *autoMachineIpLineEdit_2;
    QLineEdit       *autoMachinePortLineEdit_2;

    QLabel          *autoMachineip3;
    QLabel          *autoMachineport3;
    QLineEdit       *autoMachineIpLineEdit_3;
    QLineEdit       *autoMachinePortLineEdit_3;

    QLabel          *autoMachineip4;
    QLabel          *autoMachineport4;
    QLineEdit       *autoMachineIpLineEdit_4;
    QLineEdit       *autoMachinePortLineEdit_4;
    
    QScrollArea     *databaseScrollArea;
    QCheckBox       *checkBoxEnableDatabaseFunction;
    QLabel          *ipaddresslabel;
    QLineEdit       *ipaddressLineEdit;
    QLabel          *databasenamelabel;
    QLineEdit       *databasenameLineEdit;
    QLabel          *tablenamelabel;
    QLineEdit       *tablenameLineEdit;
    QLabel          *usernamelabel;
    QLineEdit       *usernameLineEdit;
    QLabel          *passwordlabel;
    QLineEdit       *passwordLineEdit;
    QPushButton     *testConnectionPushButton;

    QScrollArea     *qrcodeScrollArea;
    QCheckBox       *checkBoxEnableQr;
    QLabel          *filePathLabel;
    QLineEdit       *saveQRcodeFolderPath;
    QLabel          *qrcodeLengthLabel;
    QLineEdit       *qrcodeLength;
    QLabel          *qrcodePrefixLengthLabel;
    QLineEdit       *qrcodePrefixLength;
    QLabel          *qrcodePrefixLabel;
    QLineEdit       *qrcodePrefix;

    QHBoxLayout     *hBoxLayout;
    QVBoxLayout     *vBoxLayout;
};

#endif // TESTQTREEQSCROLLAREA_H
