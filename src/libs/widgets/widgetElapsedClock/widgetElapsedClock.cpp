#include "widgetElapsedClock.h"

const QString WidgetElapsedClock::CLOCK_FORMAT = "hh:mm:ss";

WidgetElapsedClock::~WidgetElapsedClock() {}

WidgetElapsedClock::WidgetElapsedClock(QWidget* parent) : QWidget(parent) {
  QHBoxLayout* clockWidgetMainLayout = new QHBoxLayout();
  this->setLayout(clockWidgetMainLayout);

  this->setSizePolicy(QSizePolicy::Policy::Preferred,
                      QSizePolicy::Policy::Fixed);
  this->setFixedHeight(CLOCK_WIDGET_HEIGHT);

  this->timer_label.setText(this->getElapsedTime());
  clockWidgetMainLayout->addWidget(&this->timer_label);

  clockWidgetMainLayout->addWidget(&this->startButton);
  connect(&this->startButton, &QPushButton::released, this,
          &WidgetElapsedClock::startClock);
  connect(&this->timer, &QTimer::timeout, this,
          &WidgetElapsedClock::updateClockLabel);

  clockWidgetMainLayout->setMargin(0);
}

QString WidgetElapsedClock::getElapsedTime() {
  return this->elapsedTime.toString(WidgetElapsedClock::CLOCK_FORMAT);
}

void WidgetElapsedClock::startClock() {
  this->timer.start(WidgetElapsedClock::TIMER_TIMEOUT);
}

void WidgetElapsedClock::updateClockLabel() {
  this->elapsedTime =
      this->elapsedTime.addMSecs(WidgetElapsedClock::TIMER_TIMEOUT);
  this->timer_label.setText(this->getElapsedTime());
}