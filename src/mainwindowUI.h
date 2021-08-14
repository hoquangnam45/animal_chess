#pragma once
#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QLayout>
#include <QMainWindow>
#include <ultilities/configurationParser/configurationParser.h>
#include <widgets/widgetChessBoard/widgetChessBoard.h>
#include <widgets/widgetElapsedClock/widgetElapsedClock.h>
#include <ui_mainwindowUI.h>
#include <widgets/styleWidget/styleWidget.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindowUI;
}
QT_END_NAMESPACE

class MainWindowUI : public StyleWidget<QMainWindow> {
    Q_OBJECT
    public:
        explicit MainWindowUI(QWidget* parent = nullptr);
        ~MainWindowUI() override;
    protected:
        QString objectName() const override;
        QDir cssDir() const override;
    private:
        Ui::MainWindowUI ui;
        WidgetElapsedClock elapsedClock;
        WidgetChessBoard chessBoard;
};
