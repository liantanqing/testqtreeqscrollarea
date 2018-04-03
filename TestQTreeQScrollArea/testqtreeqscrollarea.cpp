#include "testqtreeqscrollarea.h"

TestQTreeQScrollArea::TestQTreeQScrollArea(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 使用自定义标题栏;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    initTitleBar();
    this->resize(QSize(600, 420));
    this->setObjectName("testQTreeQScrollArea");
    qtreeWidget      = new QTreeWidget(this);
    basicSettings    = new QTreeWidgetItem(QStringList() << tr("Basic"));
    databaseSettings = new QTreeWidgetItem(QStringList() << tr("Database"));
    qrCodeSettings   = new QTreeWidgetItem(QStringList() << tr("QRCode"));
    qtreeWidget->addTopLevelItem(basicSettings);
    qtreeWidget->addTopLevelItem(databaseSettings);
    qtreeWidget->addTopLevelItem(qrCodeSettings);
    qtreeWidget->setMaximumWidth(150);
    qtreeWidget->setHeaderHidden(true);
    qtreeWidget->setObjectName("qtreeWidget");

    /////////////////////////基本设置面板/////////////////////////////////////////////////
    QVBoxLayout *vbox     = new QVBoxLayout;
    scrollArea            = new QScrollArea(this);
    functionCustom        = new QGroupBox(tr("Function Custom"), scrollArea);
    functionCustom->setObjectName("functionCustomGroupBox");
    QLabel *savePictureLab= new QLabel(tr("Save Picture"));
    checkBoxSavePic       = new QCheckBox;
    checkBoxSavePic->setCheckState(Qt::Checked);
    QHBoxLayout *savePictureHLayout = new QHBoxLayout;
    savePictureHLayout->addWidget(savePictureLab);
    savePictureHLayout->addWidget(checkBoxSavePic);

    QLabel *checkBoxDomeKeyLab= new QLabel(tr("Dome Test"));
    checkBoxDomeKeyTest       = new QCheckBox;
    QHBoxLayout *DomeKeyHLayout = new QHBoxLayout;
    DomeKeyHLayout->addWidget(checkBoxDomeKeyLab);
    DomeKeyHLayout->addWidget(checkBoxDomeKeyTest);

    QLabel *PressRubberLab= new QLabel(tr("Connect IC Automatic Test"));
    checkBoxPressRubber       = new QCheckBox;
    QHBoxLayout *PressRubberHLayout = new QHBoxLayout;
    PressRubberHLayout->addWidget(PressRubberLab);
    PressRubberHLayout->addWidget(checkBoxPressRubber);

    QLabel *TestPinLab= new QLabel(tr("TestP Switch"));
    checkBoxTestPinSwitch       = new QCheckBox;
    checkBoxTestPinSwitch->setCheckState(Qt::Checked);
    QHBoxLayout *TestPinHLayout = new QHBoxLayout;
    TestPinHLayout->addWidget(TestPinLab);
    TestPinHLayout->addWidget(checkBoxTestPinSwitch);
    
    //
    QHBoxLayout *dataPathHLayout = new QHBoxLayout;
    dataPathLabel         = new QLabel(QString(tr("Data Path: ")));
    testDataFolderPath    = new QLineEdit;
    toolButton            = new QPushButton(QString(tr("Select Directory")));
    toolButton->setObjectName("SelectDirectory");
    dataPathHLayout->addWidget(dataPathLabel);
    dataPathHLayout->addWidget(testDataFolderPath);
    dataPathHLayout->addWidget(toolButton);

    vbox->addLayout(savePictureHLayout);
    vbox->addLayout(TestPinHLayout);
    vbox->addLayout(PressRubberHLayout);
    vbox->addLayout(DomeKeyHLayout);
    vbox->addLayout(dataPathHLayout);
    vbox->addStretch(1);
    functionCustom->setLayout(vbox);

    QHBoxLayout *hbox     = new QHBoxLayout;
    QGroupBox *machineControlMode = new QGroupBox(tr("Machine Model"), scrollArea);
    machineControlMode->setObjectName("machineControlGroupBox");
    manualModel                   = new QRadioButton(tr("Manual Mode"));
    semiautomaticModel            = new QRadioButton(tr("Semiautomatic Mode"));
    networkMode                   = new QRadioButton(tr("Network Mode"));
    manualModel->setChecked(true);
    hbox->addWidget(manualModel);
    hbox->addWidget(semiautomaticModel);
    hbox->addWidget(networkMode);
    hbox->addStretch(1);
    machineControlMode->setLayout(hbox);

    autoMachineIP_Port               = new QGroupBox(tr("Config Ip and Port"), scrollArea);
    autoMachineIP_Port->setObjectName("autoMachineIP_PortGroupBox");
    QVBoxLayout *vAutoMachineIP_Port = new QVBoxLayout;
    QHBoxLayout *deviceHbox1  = new QHBoxLayout;
    autoMachineip1            = new QLabel(QString(tr("AutoMachine1 IP: ")));
    autoMachineport1          = new QLabel(QString(tr("AutoMachine1 Port:")));;
    autoMachineIpLineEdit     = new QLineEdit;
    autoMachinePortLineEdit   = new QLineEdit;
    deviceHbox1->addWidget(autoMachineip1);
    deviceHbox1->addWidget(autoMachineIpLineEdit);
    deviceHbox1->addWidget(autoMachineport1);
    deviceHbox1->addWidget(autoMachinePortLineEdit);

    QHBoxLayout *deviceHbox2  = new QHBoxLayout;
    autoMachineip2            = new QLabel(QString(tr("AutoMachine2 IP: ")));
    autoMachineport2          = new QLabel(QString(tr("AutoMachine2 Port:")));
    autoMachineIpLineEdit_2   = new QLineEdit;
    autoMachinePortLineEdit_2 = new QLineEdit;
    deviceHbox2->addWidget(autoMachineip2);
    deviceHbox2->addWidget(autoMachineIpLineEdit_2);
    deviceHbox2->addWidget(autoMachineport2);
    deviceHbox2->addWidget(autoMachinePortLineEdit_2);

    QHBoxLayout *deviceHbox3  = new QHBoxLayout;
    autoMachineip3            = new QLabel(QString(tr("AutoMachine3 IP: ")));
    autoMachineport3          = new QLabel(QString(tr("AutoMachine3 Port:")));
    autoMachineIpLineEdit_3   = new QLineEdit;
    autoMachinePortLineEdit_3 = new QLineEdit;
    deviceHbox3->addWidget(autoMachineip3);
    deviceHbox3->addWidget(autoMachineIpLineEdit_3);
    deviceHbox3->addWidget(autoMachineport3);
    deviceHbox3->addWidget(autoMachinePortLineEdit_3);

    QHBoxLayout *deviceHbox4  = new QHBoxLayout;
    autoMachineip4            = new QLabel(QString(tr("AutoMachine4 IP: ")));
    autoMachineport4          = new QLabel(QString(tr("AutoMachine4 Port:")));
    autoMachineIpLineEdit_4   = new QLineEdit;
    autoMachinePortLineEdit_4 = new QLineEdit;
    deviceHbox4->addWidget(autoMachineip4);
    deviceHbox4->addWidget(autoMachineIpLineEdit_4);
    deviceHbox4->addWidget(autoMachineport4);
    deviceHbox4->addWidget(autoMachinePortLineEdit_4);
    vAutoMachineIP_Port->addLayout(deviceHbox1);
    vAutoMachineIP_Port->addLayout(deviceHbox2);
    vAutoMachineIP_Port->addLayout(deviceHbox3);
    vAutoMachineIP_Port->addLayout(deviceHbox4);
    autoMachineIP_Port->setLayout(vAutoMachineIP_Port);

    QVBoxLayout *vScrollArea     = new QVBoxLayout;
    vScrollArea->addWidget(functionCustom);
    vScrollArea->addWidget(autoMachineIP_Port);
    vScrollArea->addWidget(machineControlMode);
    scrollArea->setLayout(vScrollArea);

    ////////////////////////数据库操作面板////////////////////////////////////////////////
    databaseScrollArea                              = new QScrollArea(this);
    QGroupBox       *databaseConnectGroupBox        = new QGroupBox(tr("DataBase Connection"), databaseScrollArea);
    databaseConnectGroupBox->setObjectName("databaseConnectGroupBox");
    QHBoxLayout     *enableDatabaseHBox             = new QHBoxLayout;
    QLabel          *enableDatabaseLabel            = new QLabel(QString(tr("Enable Database")));
    QCheckBox       *checkBoxEnableDatabaseFunction = new QCheckBox;
    enableDatabaseHBox->addWidget(enableDatabaseLabel);
    enableDatabaseHBox->addWidget(checkBoxEnableDatabaseFunction);
    QHBoxLayout     *ipaddressHBox                  = new QHBoxLayout;
    QLabel          *ipaddresslabel                 = new QLabel(QString(tr("IP Address:   ")));
    QLineEdit       *ipaddressLineEdit              = new QLineEdit;
    ipaddressHBox->addWidget(ipaddresslabel);
    ipaddressHBox->addWidget(ipaddressLineEdit);
    QHBoxLayout     *databasenameHBox               = new QHBoxLayout;
    QLabel          *databasenamelabel              = new QLabel(QString(tr("DataBase Name:")));
    QLineEdit       *databasenameLineEdit           = new QLineEdit;
    databasenameHBox->addWidget(databasenamelabel);
    databasenameHBox->addWidget(databasenameLineEdit);
    QHBoxLayout     *tablenameHBox                  = new QHBoxLayout;
    QLabel          *tablenamelabel                 = new QLabel(QString(tr("Table Name:   ")));
    QLineEdit       *tablenameLineEdit              = new QLineEdit;
    tablenameHBox->addWidget(tablenamelabel);
    tablenameHBox->addWidget(tablenameLineEdit);
    QHBoxLayout     *usernameHBox                   = new QHBoxLayout;
    QLabel          *usernamelabel                  = new QLabel(QString(tr("User Name:    ")));
    QLineEdit       *usernameLineEdit               = new QLineEdit;
    usernameHBox->addWidget(usernamelabel);
    usernameHBox->addWidget(usernameLineEdit);
    QHBoxLayout     *passwordHBox                   = new QHBoxLayout;
    QLabel          *passwordlabel                  = new QLabel(QString(tr("Password:     ")));
    passwordLineEdit                                = new QLineEdit;
    passwordHBox->addWidget(passwordlabel);
    passwordHBox->addWidget(passwordLineEdit);
    QHBoxLayout     *testConnectionHBox             = new QHBoxLayout;
    QLabel          *testConnectionlabel            = new QLabel(QString(tr("Clicked Me:   ")));
    QPushButton     *testConnectionPushButton       = new QPushButton(QString(tr("Test Connection")));
    testConnectionPushButton->setObjectName("testConnectionPushButton");
    testConnectionHBox->addWidget(testConnectionlabel);
    testConnectionHBox->addWidget(testConnectionPushButton);
    
    QVBoxLayout     *vDatabaseGroupBoxVLayout            = new QVBoxLayout;
    vDatabaseGroupBoxVLayout->addLayout(enableDatabaseHBox);
    vDatabaseGroupBoxVLayout->addLayout(ipaddressHBox);
    vDatabaseGroupBoxVLayout->addLayout(databasenameHBox);
    vDatabaseGroupBoxVLayout->addLayout(tablenameHBox);
    vDatabaseGroupBoxVLayout->addLayout(usernameHBox);
    vDatabaseGroupBoxVLayout->addLayout(passwordHBox);
    vDatabaseGroupBoxVLayout->addLayout(testConnectionHBox);
    databaseConnectGroupBox->setLayout(vDatabaseGroupBoxVLayout);
    QVBoxLayout     *vDatabaseVLayout            = new QVBoxLayout;
    vDatabaseVLayout->addWidget(databaseConnectGroupBox);
    vDatabaseVLayout->addStretch(1);
    databaseScrollArea->setLayout(vDatabaseVLayout);

    //////////////////////////二维码设置面板////////////////////////////////////////////////
    qrcodeScrollArea                    = new QScrollArea(this);
    QGroupBox *qrcodeGroupBox           = new QGroupBox     ((tr("Qr Code: ")), qrcodeScrollArea);
    qrcodeGroupBox->setObjectName("qrcodeGroupBox");
    QHBoxLayout     *enableQrcodeHBox             = new QHBoxLayout;
    QLabel          *enableQrcodeLabel            = new QLabel(QString(tr("Enable QrCode")));
    checkBoxEnableQr = new QCheckBox;
    enableQrcodeHBox->addWidget(enableQrcodeLabel);
    enableQrcodeHBox->addWidget(checkBoxEnableQr);
    QHBoxLayout *filePathHBox           = new QHBoxLayout;
    filePathLabel                       = new QLabel(QString(tr("File Path:    ")));
    saveQRcodeFolderPath                = new QLineEdit;
    filePathHBox->addWidget(filePathLabel);
    filePathHBox->addWidget(saveQRcodeFolderPath);
    QHBoxLayout *qrcodeLengthHBox       = new QHBoxLayout;
    qrcodeLengthLabel                   = new QLabel(QString(tr("QrCode Length:")));
    qrcodeLength                        = new QLineEdit;
    qrcodeLengthHBox->addWidget(qrcodeLengthLabel);
    qrcodeLengthHBox->addWidget(qrcodeLength);
    QHBoxLayout *qrcodePrefixLengthHBox = new QHBoxLayout;
    qrcodePrefixLengthLabel             = new QLabel(QString(tr("QRCode PreLen:")));
    qrcodePrefixLength                  = new QLineEdit;
    qrcodePrefixLengthHBox->addWidget(qrcodePrefixLengthLabel);
    qrcodePrefixLengthHBox->addWidget(qrcodePrefixLength);
    QHBoxLayout *qrcodePrefixHBox       = new QHBoxLayout;
    qrcodePrefixLabel                   = new QLabel(QString(tr("QRCode Prefix:")));
    qrcodePrefix                        = new QLineEdit;
    qrcodePrefixHBox->addWidget(qrcodePrefixLabel);
    qrcodePrefixHBox->addWidget(qrcodePrefix);
    QVBoxLayout     *vQrCodeGroupBoxVLayout            = new QVBoxLayout;
    vQrCodeGroupBoxVLayout->addLayout(enableQrcodeHBox);
    vQrCodeGroupBoxVLayout->addLayout(filePathHBox);
    vQrCodeGroupBoxVLayout->addLayout(qrcodeLengthHBox);
    vQrCodeGroupBoxVLayout->addLayout(qrcodePrefixLengthHBox);
    vQrCodeGroupBoxVLayout->addLayout(qrcodePrefixHBox);
    qrcodeGroupBox->setLayout(vQrCodeGroupBoxVLayout);
    QVBoxLayout     *vQrCodeVLayout            = new QVBoxLayout;
    vQrCodeVLayout->addWidget(qrcodeGroupBox);
    vQrCodeVLayout->addStretch(1);
    qrcodeScrollArea->setLayout(vQrCodeVLayout);

    hBoxLayout              = new QHBoxLayout(this);
    hBoxLayout->addWidget(qtreeWidget);
    hBoxLayout->addWidget(scrollArea);
    hBoxLayout->addWidget(databaseScrollArea);
    hBoxLayout->addWidget(qrcodeScrollArea);
    vBoxLayout             = new QVBoxLayout(this);
    QLabel *blankSpaceLabel = new QLabel;
    blankSpaceLabel->setFixedHeight(20);
    vBoxLayout->addWidget(blankSpaceLabel);
    vBoxLayout->addLayout(hBoxLayout);
    databaseScrollArea->hide(); 
    qrcodeScrollArea->hide();
    ui.centralWidget->setLayout(vBoxLayout);
    QObject::connect(qtreeWidget,        &QTreeWidget::itemClicked, this, &TestQTreeQScrollArea::onItemClicked);
    QObject::connect(networkMode,        &QRadioButton::toggled,    this, &TestQTreeQScrollArea::onNetworkModeRadioButton);
    QObject::connect(semiautomaticModel, &QRadioButton::toggled,    this, &TestQTreeQScrollArea::onSemiautomaticModelRadioButton);
    QObject::connect(manualModel,        &QRadioButton::toggled,    this, &TestQTreeQScrollArea::onManualModelRadioButton);

    QObject::connect(checkBoxSavePic,       &QCheckBox::stateChanged,  this, &TestQTreeQScrollArea::onSavePictrueStateChanged);
    QObject::connect(checkBoxTestPinSwitch, &QCheckBox::stateChanged,  this, &TestQTreeQScrollArea::onTestPinSwitchStateChanged);
    QObject::connect(checkBoxPressRubber,   &QCheckBox::stateChanged,  this, &TestQTreeQScrollArea::onPressRubberStateChanged);
    QObject::connect(checkBoxDomeKeyTest,   &QCheckBox::stateChanged,  this, &TestQTreeQScrollArea::onDomeKeyStateChanged);
    QObject::connect(toolButton,            &QToolButton::released,    this, &TestQTreeQScrollArea::onTestDataFolderPathButtonClicked);
    QObject::connect(autoMachineIpLineEdit,     &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachineIpLineEditFinished);
    QObject::connect(autoMachinePortLineEdit,   &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachinePortLineEditFinished);
    QObject::connect(autoMachineIpLineEdit_2,   &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachineIpLineEdit_2Finished);
    QObject::connect(autoMachinePortLineEdit_2, &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachinePortLineEdit_2Finished);
    QObject::connect(autoMachineIpLineEdit_3,   &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachineIpLineEdit_3Finished);
    QObject::connect(autoMachinePortLineEdit_3, &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachinePortLineEdit_3Finished);
    QObject::connect(autoMachineIpLineEdit_4,   &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachineIpLineEdit_4Finished);
    QObject::connect(autoMachinePortLineEdit_4, &QLineEdit::editingFinished, this, &TestQTreeQScrollArea::onautoMachinePortLineEdit_4Finished);
    QObject::connect(checkBoxEnableDatabaseFunction, &QCheckBox::stateChanged, this, &TestQTreeQScrollArea::onEnableDatabaseStateChanged);
    QObject::connect(testConnectionPushButton,       &QPushButton::clicked,    this, &TestQTreeQScrollArea::onTestConnectionPushButton);
    QObject::connect(checkBoxEnableQr,               &QCheckBox::stateChanged, this, &TestQTreeQScrollArea::onEnableQrStateChanged);
}
 
TestQTreeQScrollArea::~TestQTreeQScrollArea()
{
    //delete qtreeWidget;
    //delete basicSettings;
    //delete databaseSettings;
    //delete scrollArea;
    //delete hBoxLayout;
}

void TestQTreeQScrollArea::onItemClicked(QTreeWidgetItem * item, int column)
{
   QString itemText =  item->text(column);
   if (!itemText.compare(tr("Database")))
   {
       scrollArea->hide();
       qrcodeScrollArea->hide();
       databaseScrollArea->show();
   }else if (!itemText.compare(tr("QRCode")))
   {
       databaseScrollArea->hide();
       scrollArea->hide();
       qrcodeScrollArea->show();
   }else if (!itemText.compare(tr("Basic")))
   {
       scrollArea->show();
       qrcodeScrollArea->hide();
       databaseScrollArea->hide();
   }
}

void TestQTreeQScrollArea::initTitleBar()
{
    m_titleBar = new MyTitleBar(this);
    // 初始化标题栏;
    m_titleBar->setTitleIcon(":/customTitle/Resources/titleicon.png");
    QString titleName = QString(tr("Sunwave Setting"));
    m_titleBar->setTitleContent(titleName);
    m_titleBar->setButtonType(MIN_MAX_BUTTON);
    m_titleBar->setTitleWidth(this->width());

    connect(m_titleBar, SIGNAL(signalButtonMinClicked()),     this, SLOT(onButtonMinClicked()));
    connect(m_titleBar, SIGNAL(signalButtonCloseClicked()),   this, SLOT(onButtonCloseClicked()));

}

void TestQTreeQScrollArea::onButtonMinClicked()
{
    if (Qt::Tool == (windowFlags() & Qt::Tool))
    {
        hide();    //设置了Qt::Tool 如果调用showMinimized()则窗口就销毁了？？？
    }
    else
    {
        showMinimized();
    }
}

void TestQTreeQScrollArea::onButtonCloseClicked()
{
    close();
}

void TestQTreeQScrollArea::onSavePictrueStateChanged()
{
}

void TestQTreeQScrollArea::onTestPinSwitchStateChanged(int state)
{
    switch(state)
    {
    case 0:
        //globalConfig->setTestPinCheckBoxState(false);
        break;
    case 2:
        //globalConfig->setTestPinCheckBoxState(true);
        break;
    default:
        break;
    }
}

void TestQTreeQScrollArea::onPressRubberStateChanged()
{
}

void TestQTreeQScrollArea::onDomeKeyStateChanged()
{
    //globalConfig->setDomeKeyTest((settingsUi->checkBoxDomeKeyTest ->checkState() == Qt::Checked ? true : false));
}

void TestQTreeQScrollArea::onTestDataFolderPathButtonClicked()
{
    QString tempPath = testDataFolderPath->text();
    QDir temp;
    QString fileName;
    if(temp.exists(tempPath)){
        fileName = QFileDialog::getExistingDirectory(this, tr("Save File Path"), tempPath, QFileDialog::ShowDirsOnly|QFileDialog::DontConfirmOverwrite);
    }else{
        fileName = QFileDialog::getExistingDirectory(this, tr("Save File Path"), QApplication::applicationDirPath(), QFileDialog::ShowDirsOnly|QFileDialog::DontConfirmOverwrite);
    }

    if(!fileName.isEmpty()){
        testDataFolderPath->setText(fileName);
        //globalConfig->setSettingsDataPath(fileName);
    }

}

void TestQTreeQScrollArea::onautoMachineIpLineEditFinished()
{

    //globalConfig->setAutoMachineIP(settingsUi->autoMachineIpLineEdit->text());
}

void TestQTreeQScrollArea::onautoMachinePortLineEditFinished()
{
    //globalConfig->setAutoMachinePort(settingsUi->autoMachinePortLineEdit->text());
}

void TestQTreeQScrollArea::onautoMachineIpLineEdit_2Finished()
{
    //globalConfig->setAutoMachine2IP(settingsUi->autoMachineIpLineEdit_2->text());
}

void TestQTreeQScrollArea::onautoMachinePortLineEdit_2Finished()
{
    //globalConfig->setAutoMachine2Port(settingsUi->autoMachinePortLineEdit_2->text());
}

void TestQTreeQScrollArea::onautoMachineIpLineEdit_3Finished()
{
    //globalConfig->setAutoMachine3IP(settingsUi->autoMachineIpLineEdit_3->text());
}

void TestQTreeQScrollArea::onautoMachinePortLineEdit_3Finished()
{
    //globalConfig->setAutoMachine3Port(settingsUi->autoMachinePortLineEdit_3->text());
}

void TestQTreeQScrollArea::onautoMachineIpLineEdit_4Finished()
{
    //globalConfig->setAutoMachine4IP(settingsUi->autoMachineIpLineEdit_4->text());
}

void TestQTreeQScrollArea::onautoMachinePortLineEdit_4Finished()
{
    //globalConfig->setAutoMachine4Port(settingsUi->autoMachinePortLineEdit_4->text());
}

void TestQTreeQScrollArea::onManualModelRadioButton(bool checkState)
{

}

void TestQTreeQScrollArea::onSemiautomaticModelRadioButton(bool checkState)
{

}

void TestQTreeQScrollArea::onNetworkModeRadioButton(bool checkState)
{
    if (checkState)
    {
        autoMachineIP_Port->show();
    }else
    {
        autoMachineIP_Port->hide();
    }
}

void TestQTreeQScrollArea::onEnableDatabaseStateChanged()
{
    bool enableDatabase = checkBoxEnableDatabaseFunction->checkState();
    //globalConfig->setEnableDatabaseState(enableDatabase);
    //emit sigDatabaseEnableState(enableDatabase);
}

void TestQTreeQScrollArea::onTestConnectionPushButton()
{
    bool enableDatabase = checkBoxEnableDatabaseFunction->checkState();
    //emit sigDatabaseEnableState(enableDatabase);
    //emit sigTestConnectionDatabase(ipaddressLineEdit->text(),databasenameLineEdit->text(),
    //    tablenameLineEdit->text(), usernameLineEdit->text(),passwordLineEdit->text());
    //testConnectionPushButton->setEnabled(false);
    //globalConfig->setEnableDatabaseState(checkBoxEnableDatabaseFunction->checkState() == Qt::Checked ? true : false);
    //globalConfig->setIPAddress(ipaddressLineEdit->text());
    //globalConfig->setDataBaseName(databasenameLineEdit->text());
    //globalConfig->setTableName(tablenameLineEdit->text());
    //globalConfig->setUserName(usernameLineEdit->text());
    //globalConfig->setPassWord(passwordLineEdit->text());
}

void TestQTreeQScrollArea::onEnableQrStateChanged()
{
    bool enableQr = checkBoxEnableQr->checkState();
    //label->setEnabled(enableQr);
    //saveQRcodeFolderPath->setEnabled(enableQr);
    //qrcodeLength->setEnabled(enableQr);
    //qrcodePrefixLength->setEnabled(enableQr);
    //qrcodePrefix->setEnabled(enableQr);

    //qrCodeLineEdit_1->setVisible(enableQr);
    //qrCodeLineEdit_2->setVisible(enableQr);
    //qrCodeLineEdit_3->setVisible(enableQr);
    //qrCodeLineEdit_4->setVisible(enableQr);

    //globalConfig->setOfilmTestLogEnableQr(enableQr);
    //globalConfig->setOfilmTestLogQrCodeLength(qrcodeLength->text());
    //globalConfig->setOfilmTestLogQrCodePreLen(qrcodePrefixLength->text());
    //globalConfig->setOfilmTestLogQrCodePreFix(qrcodePrefix->text());
}