#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_camera=new QCamera(QCameraInfo::defaultCamera());
    qInfo() << QCameraInfo::defaultCamera().description();
    //QCameraImageCapture* m_imageCapture=new QCameraImageCapture(m_camera);
    //m_camera->setCaptureMode(QCamera::CaptureStillImage);

    m_camera->setViewfinder(ui->cameraWidget);
    m_camera->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    QCameraImageProcessing *imageProcessing = m_camera->imageProcessing();
    if (imageProcessing->isAvailable())
        imageProcessing->setBrightness(value/100.);
    qInfo() << value/100.;

}

void MainWindow::on_contrastSlider_valueChanged(int value)
{
    QCameraImageProcessing *imageProcessing = m_camera->imageProcessing();
    if (imageProcessing->isAvailable())
        imageProcessing->setContrast(value/100.);
}

void MainWindow::on_saturationSlider_valueChanged(int value)
{
    QCameraImageProcessing *imageProcessing = m_camera->imageProcessing();
    if (imageProcessing->isAvailable())
        imageProcessing->setSaturation(value/100.);
}
