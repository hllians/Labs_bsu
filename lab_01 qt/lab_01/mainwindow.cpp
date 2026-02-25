#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Текущее время - Глушанко Ульяна, 4 группа");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(10);
    updateTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QDateTime current = QDateTime::currentDateTime();
    QString timeString = current.toString("HH:mm:ss.zzz");
    QLabel *timeLabel = findChild<QLabel*>("label");
    if (timeLabel) {
        timeLabel->setText(timeString);
    }
}
