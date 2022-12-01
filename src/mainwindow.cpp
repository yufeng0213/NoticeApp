#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("/home/yufeng/qtPro/NoticeApp/notice/notice_style_sheet.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    this->hide();

    mSysTrayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon("./icon/0.png");
    mSysTrayIcon->setIcon(icon);
    mSysTrayIcon->setToolTip(QObject::trUtf8("text system plane icon"));
    connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

    createActions();
    createMenu();

    mSysTrayIcon->show();
}
void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason){
    switch (reason) {
        case QSystemTrayIcon::Trigger:
            mSysTrayIcon->showMessage(QObject::trUtf8("Message Title"),
                                      QObject::trUtf8("welcome use this program"),
                                      QSystemTrayIcon::Information,
                                      1000);
        break;
        case QSystemTrayIcon::DoubleClick:
            this->show();
        break;
        default:
        break;

    }
}


void MainWindow::createActions(){
    mShowMainAction = new QAction(QObject::trUtf8("show main page"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::trUtf8("exit"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));
}

void MainWindow::createMenu(){
    mMenu = new QMenu(this);
    mMenu->addAction(mShowMainAction);
    mMenu->addSeparator();
    mMenu->addAction(mExitAppAction);
    mSysTrayIcon->setContextMenu(mMenu);
}

void MainWindow::on_showMainAction(){
    this->show();
}

void MainWindow::on_exitAppAction(){
    exit(0);
}




void MainWindow::on_btn_newtask_clicked()
{
    TaskContent *task  = new TaskContent;
    task->show();
}

