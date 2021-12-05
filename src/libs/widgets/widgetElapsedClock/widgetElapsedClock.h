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
#include <component/styler/styler.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class WidgetElapsedClock;
}
QT_END_NAMESPACE
class WidgetElapsedClock : public QWidget {
    Q_OBJECT
    private:
        static const int TIMER_TIMEOUT = 1000;
        const QString CLOCK_FORMAT;
        Styler styler;
        QTimer timer;
        QTime elapsedTime = QTime(0, 0, 0);
        Ui::WidgetElapsedClock ui;
    private slots:
        void updateClockLabel();
        void startClock();
    public:
        void paintEvent(QPaintEvent* e) override;
        explicit WidgetElapsedClock(QWidget* parent = nullptr);
        ~WidgetElapsedClock() override;
        QString getElapsedTime();
};