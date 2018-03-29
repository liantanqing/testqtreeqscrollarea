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
#include <QtCore/QDir>
#include <QtWidgets/QFileDialog>
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

    void onSavePictrueStateChanged();
    void onTestPinSwitchStateChanged(int state);
    void onPressRubberStateChanged();
    void onDomeKeyStateChanged();
    void onTestDataFolderPathButtonClicked();
    void onautoMachineIpLineEditFinished();
    void onautoMachinePortLineEditFinished();
    void onautoMachineIpLineEdit_2Finished();
    void onautoMachinePortLineEdit_2Finished();
    void onautoMachineIpLineEdit_3Finished();
    void onautoMachinePortLineEdit_3Finished();
    void onautoMachineIpLineEdit_4Finished();
    void onautoMachinePortLineEdit_4Finished();

    //void onEnableQrStateChanged();
    //void onToolModeComboBoxIndexChanged(int index);
    //void onTestConnectionPushButton();
    //void onEnableDatabaseStateChanged();
    //void onSaveQRcodeFolderPathEditingFinished();
    //void onQrcodeLengthEditingFinished();
    //void onQrcodePrefixLengthEditingFinished();
    //void onQrcodePrefixEditingFinished();
    

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
