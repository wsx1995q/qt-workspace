#include "mainwindow.h"

#include <QAction>
#include <QApplication>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Hello — qt-workspace"));
    resize(420, 280);

    setupUi();
    createMenus();
    statusBar()->showMessage(tr("就绪"));
    updateCounterText();
}

void MainWindow::setupUi()
{
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);
    layout->setContentsMargins(24, 24, 24, 24);
    layout->setSpacing(16);

    m_label = new QLabel(central);
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setWordWrap(true);

    m_button = new QPushButton(tr("点击我"), central);
    m_button->setMinimumHeight(36);
    connect(m_button, &QPushButton::clicked, this, &MainWindow::incrementCounter);

    layout->addStretch();
    layout->addWidget(m_label);
    layout->addWidget(m_button, 0, Qt::AlignHCenter);
    layout->addStretch();

    setCentralWidget(central);
}

void MainWindow::createMenus()
{
    auto *fileMenu = menuBar()->addMenu(tr("文件(&F)"));

    auto *quitAction = fileMenu->addAction(tr("退出(&Q)"));
    quitAction->setShortcut(QKeySequence::Quit);
    quitAction->setStatusTip(tr("退出应用程序"));
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    auto *helpMenu = menuBar()->addMenu(tr("帮助(&H)"));

    auto *aboutAction = helpMenu->addAction(tr("关于(&A)"));
    aboutAction->setStatusTip(tr("关于本程序"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
}

void MainWindow::incrementCounter()
{
    ++m_clickCount;
    updateCounterText();
    statusBar()->showMessage(tr("已点击 %1 次").arg(m_clickCount), 2000);
}

void MainWindow::updateCounterText()
{
    m_label->setText(tr("你好，欢迎使用 qt-workspace！\n当前点击次数：%1").arg(m_clickCount));
}

void MainWindow::showAbout()
{
    QMessageBox::about(
        this,
        tr("关于 Hello"),
        tr("<h3>Hello</h3>"
           "<p>这是 <b>qt-workspace</b> 中的示例窗口程序。</p>"
           "<p>基于 Qt 6 Widgets，用 CMake 构建。</p>"));
}
