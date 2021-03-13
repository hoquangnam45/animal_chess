#include <QApplication>
#include <QDebug>
#include <QDir>
#include "mainwindow.h"
int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow* w = MainWindow::animalChessApp();
  w->show();
  return a.exec();
}
