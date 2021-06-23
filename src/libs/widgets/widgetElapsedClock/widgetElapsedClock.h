#ifndef WIDGETELAPSEDCLOCK_H
#define WIDGETELAPSEDCLOCK_H

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

class WidgetElapsedClock : public QWidget {
  Q_OBJECT
 private:
  static const int TIMER_TIMEOUT = 1000;
  static const int CLOCK_WIDGET_HEIGHT = 40;
  static const QString CLOCK_FORMAT;
  bool clockStart = false;
  QTimer timer;
  QString timer_text;
  QLabel timer_label;
  QTime elapsedTime = QTime(0, 0, 0);
  QPushButton startButton = QPushButton(tr("Start"));
  void handleStartButton();
 private slots:
  void updateClockLabel();
  void startClock();

 public:
  WidgetElapsedClock(QWidget* parent = nullptr);
  ~WidgetElapsedClock();
  QString getElapsedTime();
};

#endif  // WIDGETELAPSEDCLOCK_H
