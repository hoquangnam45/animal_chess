#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLayout>
#include "customLib/customWidget/widgetMenuBar.h"
#include "customLib/customWidget/widgetElapsedClock.h"
#include "customLib/customWidget/widgetChessBoard.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        static MainWindow* animalChessApp(QWidget *parent = nullptr);
        ~MainWindow();

    //public slots
        //void updateTimer(elapsedTime);
    private:
        Ui::MainWindow *ui;
        MainWindow(QWidget *parent);
        widgetMenuBar *gameMenuBar;
//        widgetElapsedClock *elapsedClock;
};
#endif // MAINWINDOW_H
