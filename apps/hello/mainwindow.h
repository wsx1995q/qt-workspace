#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void incrementCounter();
    void showAbout();

private:
    void setupUi();
    void createMenus();
    void updateCounterText();

    QLabel *m_label = nullptr;
    QPushButton *m_button = nullptr;
    int m_clickCount = 0;
};

#endif // MAINWINDOW_H
