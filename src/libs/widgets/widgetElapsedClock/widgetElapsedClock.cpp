#include "widgetElapsedClock.h"

const QString WidgetElapsedClock::CLOCK_FORMAT = "hh:mm:ss";

WidgetElapsedClock::WidgetElapsedClock(QWidget* parent) : QWidget(parent) {}

WidgetElapsedClock::~WidgetElapsedClock() {}

WidgetElapsedClock* WidgetElapsedClock::createElapsedClock(QWidget* parent) {
  WidgetElapsedClock* clock = new WidgetElapsedClock(parent);
  QHBoxLayout* clockWidgetMainLayout = new QHBoxLayout();
  clockWidgetMainLayout->setAlignment(Qt::AlignHCenter);
  clock->setLayout(clockWidgetMainLayout);

  QSizePolicy* clockSizePolicy = new QSizePolicy();

  clock->setSizePolicy(clockSizePolicy->Minimum, clockSizePolicy->Fixed);
  clock->setFixedHeight(CLOCK_WIDGET_HEIGHT);

  clock->timer_label->setText(clock->getElapsedTime());
  clockWidgetMainLayout->addWidget(clock->timer_label);

  clockWidgetMainLayout->setMargin(0);
  clock->setStyleSheet("border: 1px solid red;background: yellow");
  connect(clock->timer, SIGNAL(timeout()), clock, SLOT(updateClock()));
  clock->start();
  return clock;
}

QString WidgetElapsedClock::getElapsedTime() {
  return this->elapsedTime->toString(WidgetElapsedClock::CLOCK_FORMAT);
}

void WidgetElapsedClock::start() {
  this->timer->start(WidgetElapsedClock::TIMER_TIMEOUT);
}

void WidgetElapsedClock::updateClock() {
  *this->elapsedTime =
      this->elapsedTime->addMSecs(WidgetElapsedClock::TIMER_TIMEOUT);
  this->timer_label->setText(this->getElapsedTime());
}