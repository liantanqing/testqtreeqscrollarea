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
	// 初始化;
	initControl();
	initConnections();
	loadStyleSheet("MyTitle");
}

MyTitleBar::~MyTitleBar()
{

}

// 初始化控件;
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

    m_OneSplitScreen  = new QPushButton;     //1 分屏
    m_TwoSplitScreen  = new QPushButton;     //2 分屏
    m_FourSplitScreen = new QPushButton;    //4 分屏
    m_MenuButton = new QPushButton;
    //m_MenuButton->setStyleSheet("QPushButton{border-image:url(:/TestQTreeQScrollArea/Resources/menu_gray3.png);}"
    //                            "QPushButton:hover{border-image:url(:/TestQTreeQScrollArea/Resources/menu_green3.png);}"
    //                            "QPushButton::menu-indicator{image:none;}"//去掉倒三角
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
        "QPushButton::menu-indicator{image:none;}");//去掉倒三角
       
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

// 信号槽的绑定;
void MyTitleBar::initConnections()
{
	connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
	connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
	connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

// 设置标题栏背景色,在paintEvent事件中进行绘制标题栏背景色;
//在构造函数中给了默认值，可以外部设置颜色值改变标题栏背景色;
void MyTitleBar::setBackgroundColor(int r, int g, int b)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	// 重新绘制（调用paintEvent事件）;
	update();
}

// 设置标题栏图标;
void MyTitleBar::setTitleIcon(QString filePath)
{
	QPixmap titleIcon(filePath);
	m_pIcon->setPixmap(titleIcon.scaled(25 , 25));
}

// 设置标题内容;
void MyTitleBar::setTitleContent(QString titleContent)
{
	m_pTitleContent->setText(titleContent);
	m_titleContent = titleContent;
}

// 设置标题栏长度;
void MyTitleBar::setTitleWidth(int width)
{
	this->setFixedWidth(width);
}

// 设置标题栏上按钮类型;
// 由于不同窗口标题栏上的按钮都不一样，所以可以自定义标题栏中的按钮;
// 这里提供了四个按钮，分别为最小化、还原、最大化、关闭按钮，如果需要其他按钮可自行添加设置;
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

// 设置标题栏中的标题是否会自动滚动，跑马灯的效果;
// 一般情况下标题栏中的标题内容是不滚动的，但是既然自定义就看自己需要嘛，想怎么设计就怎么搞O(∩_∩)O！
void MyTitleBar::setTitleRoll()
{
	connect(&m_titleRollTimer, SIGNAL(timeout()), this, SLOT(onRollTitle()));
	m_titleRollTimer.start(200);
}

// 保存窗口最大化前窗口的位置以及大小;
void MyTitleBar::saveRestoreInfo(const QPoint point, const QSize size)
{
	m_restorePos = point;
	m_restoreSize = size;
}

// 获取窗口最大化前窗口的位置以及大小;
void MyTitleBar::getRestoreInfo(QPoint& point, QSize& size)
{
	point = m_restorePos;
	size = m_restoreSize;
}

// 绘制标题栏背景色;
void MyTitleBar::paintEvent(QPaintEvent *event)
{
	//设置背景色;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(m_colorR, m_colorG, m_colorB)));

	// 当窗口最大化或者还原后，窗口长度变了，标题栏的长度应当一起改变;
	if (this->width() != this->parentWidget()->width())
	{
		this->setFixedWidth(this->parentWidget()->width());
	}
	QWidget::paintEvent(event);
}

// 以下通过mousePressEvent、mouseMoveEvent、mouseReleaseEvent三个事件实现了鼠标拖动标题栏移动窗口的效果;
void MyTitleBar::mousePressEvent(QMouseEvent *event)
{
	//if (m_buttonType == MIN_MAX_BUTTON)
	//{
	//	// 在窗口最大化时禁止拖动窗口;
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

// 加载本地样式文件;
// 可以将样式直接写在文件中，程序运行时直接加载进来;
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

// 以下为按钮操作响应的槽;
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

// 该方法主要是让标题栏中的标题显示为滚动的效果;
void MyTitleBar::onRollTitle()
{
	static int nPos = 0;
	QString titleContent = m_titleContent;
	// 当截取的位置比字符串长时，从头开始;
	if (nPos > titleContent.length())
		nPos = 0;

	m_pTitleContent->setText(titleContent.mid(nPos));
	nPos++;
}