#include "widgetElapsedClock.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>

const QString widgetElapsedClock::CLOCK_FORMAT = "hh:mm:ss";

widgetElapsedClock::widgetElapsedClock(QWidget* parent) : QWidget(parent){

}

widgetElapsedClock::~widgetElapsedClock(){

}

widgetElapsedClock* widgetElapsedClock::createElapsedClock(QWidget* parent){
    widgetElapsedClock* clock = new widgetElapsedClock(parent);
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

QString widgetElapsedClock::getElapsedTime(){
    return this->elapsedTime->toString(widgetElapsedClock::CLOCK_FORMAT);
}

void widgetElapsedClock::start() {
    this->timer->start(widgetElapsedClock::TIMER_TIMEOUT);
}

void widgetElapsedClock::updateClock(){
    *this->elapsedTime = this->elapsedTime->addMSecs(widgetElapsedClock::TIMER_TIMEOUT);
    this->timer_label->setText(this->getElapsedTime());
}