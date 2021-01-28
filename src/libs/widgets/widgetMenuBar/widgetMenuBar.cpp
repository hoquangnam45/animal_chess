#include "widgetMenuBar.h"
WidgetMenuBar::WidgetMenuBar(QWidget* parent) : QMenuBar(parent) {
  menuGame = new QMenu(tr("Game"));
  menuView = new QMenu(tr("View"));
  this->addMenu(menuGame);
  this->addMenu(menuView);
}

WidgetMenuBar* WidgetMenuBar::setupMenuBar(QWidget* parent) {
  return new WidgetMenuBar(parent);
}

WidgetMenuBar::~WidgetMenuBar() {
  delete menuGame;
  delete menuView;
}
