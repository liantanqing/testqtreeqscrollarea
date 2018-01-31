#include "mytitlebar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>

MyTitleBar::MyTitleBar(QWidget *parent)
	: QWidget(parent)
	, m_colorR(153)
	, m_colorG(153)
	, m_colorB(153)
	, m_isPressed(false)
	, m_buttonType(MIN_MAX_BUTTON)
{
	// ��ʼ��;
	initControl();
	initConnections();
	loadStyleSheet("MyTitle");
}

MyTitleBar::~MyTitleBar()
{

}

// ��ʼ���ؼ�;
void MyTitleBar::initControl()
{
	m_pIcon         = new QLabel;
	m_pTitleContent = new QLabel;
    m_currentOrder  = new QLabel;
    m_Space         = new QLabel;
    m_Space2        = new QLabel;
    m_currentOrder->setText(tr("Current Order: ")); 

	m_pButtonMin = new QPushButton;
	m_pButtonRestore = new QPushButton;
	m_pButtonMax = new QPushButton;
	m_pButtonClose = new QPushButton;

    m_pSetting     = new QPushButton;
    m_StartTest    = new QPushButton;

    m_OneSplitScreen  = new QPushButton;     //1 ����
    m_TwoSplitScreen  = new QPushButton;     //2 ����
    m_FourSplitScreen = new QPushButton;    //4 ����
    m_MenuButton = new QPushButton;
    //m_MenuButton->setStyleSheet("QPushButton{border-image:url(:/TestQTreeQScrollArea/Resources/menu_gray3.png);}"
    //                            "QPushButton:hover{border-image:url(:/TestQTreeQScrollArea/Resources/menu_green3.png);}"
    //                            "QPushButton::menu-indicator{image:none;}"//ȥ��������
    //                            "QPushButton::menu-indicator#helpMenuAction{image:url(:/TestQTreeQScrollArea/Resources/help.png);}"); 
    m_MenuButton->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT)); 
    m_MenuButton->setObjectName("menuButton");
    QMenu *mymenu=new QMenu;  
    QAction *click      = new QAction(tr("Menu Button")    ,this);
    QAction *about      = new QAction(tr("About")          ,this);
    QAction *switchLang = new QAction(tr("Language")       ,this);
    QAction *Settings   = new QAction(tr("Setting")        ,this);
    QAction *help       = new QAction(tr("Help")           ,this);
    help      ->setObjectName("helpMenuAction");
    help      ->setIcon(QIcon(":/TestQTreeQScrollArea/Resources/help.png"));
    switchLang->setIcon(QIcon(":/TestQTreeQScrollArea/Resources/Language_Switch.png"));
    //about     ->setIcon(QIcon(":/TestQTreeQScrollArea/Resources/about.png"));
    m_MenuButton->setStyleSheet("QPushButton{border-image:url(:/TestQTreeQScrollArea/Resources/menu_gray3.png);}"
        "QPushButton:hover{border-image:url(:/TestQTreeQScrollArea/Resources/menu_green3.png);}"
        "QPushButton::menu-indicator{image:none;}");//ȥ��������
       
    mymenu->addAction(click);
    mymenu->addAction(about);
    mymenu->addAction(switchLang);
    mymenu->addAction(Settings);
    mymenu->addAction(help);
    m_MenuButton->setMenu(mymenu);  

	m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    m_pSetting->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_OneSplitScreen->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_TwoSplitScreen->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_FourSplitScreen->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_StartTest->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_Space->setFixedSize(QSize(BUTTON_WIDTH-10, BUTTON_HEIGHT));
	m_pTitleContent->setObjectName("TitleContent");

	m_pButtonMin->setObjectName("ButtonMin");
	m_pButtonRestore->setObjectName("ButtonRestore");
	m_pButtonMax->setObjectName("ButtonMax");
	m_pButtonClose->setObjectName("ButtonClose");

    QIcon settingIcon(":/customTitle/Resources/setting.png");
    m_pSetting->setIcon(settingIcon);
    m_pSetting->setIconSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    m_pSetting->setFlat(true);
    m_pSetting->setStyleSheet("background: rgb(153,153,153)");

    QIcon onescreenIcon(":/customTitle/Resources/onescreen.png");
    m_OneSplitScreen->setIcon(onescreenIcon);
    m_OneSplitScreen->setIconSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    m_OneSplitScreen->setFlat(true);
    m_OneSplitScreen->setStyleSheet("background: rgb(153,153,153)");
    
    QIcon twoscreenIcon(":/customTitle/Resources/twoscreen.png");
    m_TwoSplitScreen->setIcon(twoscreenIcon);
    m_TwoSplitScreen->setIconSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    m_TwoSplitScreen->setFlat(true);
    m_TwoSplitScreen->setStyleSheet("background: rgb(153,153,153)");

    QIcon fourscreenIcon(":/customTitle/Resources/fourscreen.png");
    m_FourSplitScreen->setIcon(fourscreenIcon);
    m_FourSplitScreen->setIconSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    m_FourSplitScreen->setFlat(true);
    m_FourSplitScreen->setStyleSheet("background: rgb(153,153,153)");
    
    QIcon startTestIcon(":/customTitle/Resources/start.png");
    m_StartTest->setIcon(startTestIcon);
    m_StartTest->setIconSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    m_StartTest->setFlat(true);
    m_StartTest->setStyleSheet("background: rgb(153,153,153)");

	QHBoxLayout* mylayout = new QHBoxLayout(this);
	//mylayout->addWidget(m_pIcon);
	mylayout->addWidget(m_pTitleContent);

    //mylayout->addWidget(m_MenuButton);
    //mylayout->addWidget(m_currentOrder);
    //mylayout->addWidget(m_pComboBox);
    //mylayout->addWidget(m_Space);
    //mylayout->addWidget(m_StartTest);
    //mylayout->addWidget(m_pSetting);
    //mylayout->addWidget(m_OneSplitScreen);
    //mylayout->addWidget(m_TwoSplitScreen);
    //mylayout->addWidget(m_FourSplitScreen);
    //mylayout->addWidget(m_Space2);
	//mylayout->addWidget(m_pButtonMin);
	//mylayout->addWidget(m_pButtonRestore);
	//mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_MenuButton);
	mylayout->addWidget(m_pButtonClose);

	mylayout->setContentsMargins(5, 0, 0, 0);
	mylayout->setSpacing(0);

	m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	this->setFixedHeight(TITLE_HEIGHT);
	this->setWindowFlags(Qt::FramelessWindowHint);
}

// �źŲ۵İ�;
void MyTitleBar::initConnections()
{
	connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
	connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
	connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

// ���ñ���������ɫ,��paintEvent�¼��н��л��Ʊ���������ɫ;
//�ڹ��캯���и���Ĭ��ֵ�������ⲿ������ɫֵ�ı����������ɫ;
void MyTitleBar::setBackgroundColor(int r, int g, int b)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	// ���»��ƣ�����paintEvent�¼���;
	update();
}

// ���ñ�����ͼ��;
void MyTitleBar::setTitleIcon(QString filePath)
{
	QPixmap titleIcon(filePath);
	m_pIcon->setPixmap(titleIcon.scaled(25 , 25));
}

// ���ñ�������;
void MyTitleBar::setTitleContent(QString titleContent)
{
	m_pTitleContent->setText(titleContent);
	m_titleContent = titleContent;
}

// ���ñ���������;
void MyTitleBar::setTitleWidth(int width)
{
	this->setFixedWidth(width);
}

// ���ñ������ϰ�ť����;
// ���ڲ�ͬ���ڱ������ϵİ�ť����һ�������Կ����Զ���������еİ�ť;
// �����ṩ���ĸ���ť���ֱ�Ϊ��С������ԭ����󻯡��رհ�ť�������Ҫ������ť�������������;
void MyTitleBar::setButtonType(ButtonType buttonType)
{
	m_buttonType = buttonType;

	switch (buttonType)
	{
	case MIN_BUTTON:
		{
			m_pButtonRestore->setVisible(false);
			m_pButtonMax->setVisible(false);
		}
		break;
	case MIN_MAX_BUTTON:
		{
			m_pButtonRestore->setVisible(false);
		}
		break;
	case ONLY_CLOSE_BUTTON:
		{
			m_pButtonMin->setVisible(false);
			m_pButtonRestore->setVisible(false);
			m_pButtonMax->setVisible(false);
		}
		break;
	default:
		break;
	}
}

// ���ñ������еı����Ƿ���Զ�����������Ƶ�Ч��;
// һ������±������еı��������ǲ������ģ����Ǽ�Ȼ�Զ���Ϳ��Լ���Ҫ�����ô��ƾ���ô��O(��_��)O��
void MyTitleBar::setTitleRoll()
{
	connect(&m_titleRollTimer, SIGNAL(timeout()), this, SLOT(onRollTitle()));
	m_titleRollTimer.start(200);
}

// ���洰�����ǰ���ڵ�λ���Լ���С;
void MyTitleBar::saveRestoreInfo(const QPoint point, const QSize size)
{
	m_restorePos = point;
	m_restoreSize = size;
}

// ��ȡ�������ǰ���ڵ�λ���Լ���С;
void MyTitleBar::getRestoreInfo(QPoint& point, QSize& size)
{
	point = m_restorePos;
	size = m_restoreSize;
}

// ���Ʊ���������ɫ;
void MyTitleBar::paintEvent(QPaintEvent *event)
{
	//���ñ���ɫ;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(m_colorR, m_colorG, m_colorB)));

	// ��������󻯻��߻�ԭ�󣬴��ڳ��ȱ��ˣ��������ĳ���Ӧ��һ��ı�;
	if (this->width() != this->parentWidget()->width())
	{
		this->setFixedWidth(this->parentWidget()->width());
	}
	QWidget::paintEvent(event);
}

// ����ͨ��mousePressEvent��mouseMoveEvent��mouseReleaseEvent�����¼�ʵ��������϶��������ƶ����ڵ�Ч��;
void MyTitleBar::mousePressEvent(QMouseEvent *event)
{
	//if (m_buttonType == MIN_MAX_BUTTON)
	//{
	//	// �ڴ������ʱ��ֹ�϶�����;
	//	if (m_pButtonMax->isVisible())
	//	{
	//		m_isPressed = true;
	//		m_startMovePos = event->globalPos();
	//	}
	//}
	//else
	//{
		m_isPressed = true;
		m_startMovePos = event->globalPos();
	//}
	
	return QWidget::mousePressEvent(event);
}

void MyTitleBar::mouseMoveEvent(QMouseEvent *event)
{
	if (m_isPressed)
	{
		QPoint movePoint = event->globalPos() - m_startMovePos;
		QPoint widgetPos = this->parentWidget()->pos();
		m_startMovePos = event->globalPos();
		this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
	}
	return QWidget::mouseMoveEvent(event);
}

void MyTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressed = false;
	return QWidget::mouseReleaseEvent(event);
}

// ���ر�����ʽ�ļ�;
// ���Խ���ʽֱ��д���ļ��У���������ʱֱ�Ӽ��ؽ���;
void MyTitleBar::loadStyleSheet(const QString &sheetName)
{
	QFile file(":/customTitle/Resources/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}

// ����Ϊ��ť������Ӧ�Ĳ�;
void MyTitleBar::onButtonMinClicked()
{
	emit signalButtonMinClicked();
}

void MyTitleBar::onButtonRestoreClicked()
{
	m_pButtonRestore->setVisible(false);
 	m_pButtonMax->setVisible(true);
	emit signalButtonRestoreClicked();
}

void MyTitleBar::onButtonMaxClicked()
{
 	m_pButtonMax->setVisible(false);
	m_pButtonRestore->setVisible(true);
	emit signalButtonMaxClicked();
}

void MyTitleBar::onButtonCloseClicked()
{
	emit signalButtonCloseClicked();
}

// �÷�����Ҫ���ñ������еı�����ʾΪ������Ч��;
void MyTitleBar::onRollTitle()
{
	static int nPos = 0;
	QString titleContent = m_titleContent;
	// ����ȡ��λ�ñ��ַ�����ʱ����ͷ��ʼ;
	if (nPos > titleContent.length())
		nPos = 0;

	m_pTitleContent->setText(titleContent.mid(nPos));
	nPos++;
}