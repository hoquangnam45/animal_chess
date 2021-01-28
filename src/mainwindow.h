#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <widgets/widgetChessBoard/widgetChessBoard.h>
#include <widgets/widgetElapsedClock/widgetElapsedClock.h>
#include <widgets/widgetMenuBar/widgetMenuBar.h>

#include <QDebug>
#include <QLayout>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  static MainWindow *animalChessApp(QWidget *parent = nullptr);
  ~MainWindow();

  // public slots
  // void updateTimer(elapsedTime);
 private:
  Ui::MainWindow *ui;
  MainWindow(QWidget *parent);
  WidgetMenuBar *gameMenuBar;
  //        WidgetElapsedClock *elapsedClock;
};
#endif  // MAINWINDOW_H
