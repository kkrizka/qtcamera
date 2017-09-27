#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_brightnessSlider_valueChanged(int value);
  void on_contrastSlider_valueChanged(int value);
  void on_saturationSlider_valueChanged(int value);

private:
  Ui::MainWindow *ui;

  QCamera* m_camera;
};

#endif // MAINWINDOW_H
