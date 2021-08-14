#include "widgetElapsedClock.h"

const QString WidgetElapsedClock::CLOCK_FORMAT = "hh:mm:ss";

WidgetElapsedClock::~WidgetElapsedClock() = default;

WidgetElapsedClock::WidgetElapsedClock(QWidget* parent) : StyleWidget<QWidget>(parent) {
    ui.setupUi(this);

    ui.timerLabel->setText(formatElapsedTime(elapsedTime));
    connect(ui.startButton, &QPushButton::released, this, &WidgetElapsedClock::startClock);
    connect(&timer, &QTimer::timeout, this, &WidgetElapsedClock::updateClockLabel);
}

QString WidgetElapsedClock::formatElapsedTime(const QTime& time) {
  return time.toString(WidgetElapsedClock::CLOCK_FORMAT);
}

void WidgetElapsedClock::startClock() {
  timer.start(WidgetElapsedClock::TIMER_TIMEOUT);
}

void WidgetElapsedClock::updateClockLabel() {
  elapsedTime = elapsedTime.addMSecs(WidgetElapsedClock::TIMER_TIMEOUT);
  ui.timerLabel->setText(formatElapsedTime(elapsedTime));
}

QDir WidgetElapsedClock::cssDir() const {
    return {":/styles/widgetElapsedClock"};
}

QString WidgetElapsedClock::objectName() const {\
    return "widgetElapsedClock";
}