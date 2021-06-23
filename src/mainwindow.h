#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ultilities/configurationParser/configurationParser.h>
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
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  WidgetMenuBar gameMenuBar;
  WidgetElapsedClock elapsedClock;
  WidgetChessBoard chessBoard;
  QVBoxLayout mainWindowLayout;
};
#endif  // MAINWINDOW_H
