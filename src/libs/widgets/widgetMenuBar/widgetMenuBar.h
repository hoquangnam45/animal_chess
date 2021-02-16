#ifndef WIDGETMENUBAR_H
#define WIDGETMENUBAR_H

#include <QDebug>
#include <QMenuBar>
#include <QString>

class WidgetMenuBar : public QMenuBar {
 public:
  static WidgetMenuBar *setupMenuBar(QWidget *parent = nullptr);
  ~WidgetMenuBar();

 private:
  WidgetMenuBar(QWidget *parent);
  QMenu *menuGame;
  QMenu *menuView;
};

#endif  // WIDGETMENUBAR_H
