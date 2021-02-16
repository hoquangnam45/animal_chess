#ifndef WIDGETELAPSEDCLOCK_H
#define WIDGETELAPSEDCLOCK_H

#include <QDebug>
#include <QElapsedTimer>
#include <QHBoxLayout>
#include <QLabel>
#include <QSizePolicy>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class WidgetElapsedClock : public QWidget {
  Q_OBJECT
 private:
  static const int TIMER_TIMEOUT = 1000;
  static const int CLOCK_WIDGET_HEIGHT = 40;
  static const QString CLOCK_FORMAT;
  WidgetElapsedClock(QWidget* parent);
  bool clockStart = false;
  QString getElapsedTime();
  QTimer* timer = new QTimer();
  QString* timer_text = new QString();
  QLabel* timer_label = new QLabel();
  QTime* elapsedTime = new QTime(0, 0, 0);
 private slots:
  void updateClock();

 public:
  ~WidgetElapsedClock();
  static WidgetElapsedClock* createElapsedClock(QWidget* parent = nullptr);
  void start();

 signals:
  void test();
};

#endif  // WIDGETELAPSEDCLOCK_H
