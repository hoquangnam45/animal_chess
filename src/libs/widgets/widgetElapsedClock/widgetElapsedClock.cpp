#include "widgetElapsedClock.h"

WidgetElapsedClock::~WidgetElapsedClock() = default;

WidgetElapsedClock::WidgetElapsedClock(QWidget* parent) :
    CLOCK_FORMAT("hh:mm:ss"),
    styler(this, ":/styles/widgetElapsedClock"),
    ui() {
    ui.setupUi(this);

    ui.timerLabel->setText(getElapsedTime());
    connect(ui.startButton, &QPushButton::released, this, &WidgetElapsedClock::startClock);
    connect(&timer, &QTimer::timeout, this, &WidgetElapsedClock::updateClockLabel);
}

QString WidgetElapsedClock::getElapsedTime() {
  return elapsedTime.toString(CLOCK_FORMAT);
}

void WidgetElapsedClock::startClock() {
  timer.start(WidgetElapsedClock::TIMER_TIMEOUT);
}

void WidgetElapsedClock::updateClockLabel() {
  elapsedTime = elapsedTime.addMSecs(WidgetElapsedClock::TIMER_TIMEOUT);
  ui.timerLabel->setText(getElapsedTime());
}

void WidgetElapsedClock::paintEvent(QPaintEvent* e) {
    styler.handlePaintEvent();
};
