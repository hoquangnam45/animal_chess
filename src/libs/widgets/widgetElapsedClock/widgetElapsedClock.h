#pragma once

#include <QButtonGroup>
#include <QDebug>
#include <QElapsedTimer>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSizePolicy>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <ui_widgetElapsedClock.h>
#include <ultilities/function/helper.h>
#include <widgets/styleWidget/styleWidget.hpp>
QT_BEGIN_NAMESPACE
namespace Ui {
    Ui::WidgetElapsedClock;
}
QT_END_NAMESPACE
class WidgetElapsedClock : public StyleWidget<QWidget> {
    Q_OBJECT
    private:
        static const int TIMER_TIMEOUT = 1000;
        static const QString CLOCK_FORMAT;
        QTimer timer;
        QTime elapsedTime = QTime(0, 0, 0);
        Ui::WidgetElapsedClock ui;
    protected:
        QDir cssDir() const override;
        QString objectName() const override;
    private slots:
        void updateClockLabel();
        void startClock();
    public:
        explicit WidgetElapsedClock(QWidget* parent = nullptr);
        ~WidgetElapsedClock() override;
        static QString formatElapsedTime(const QTime& time);
};