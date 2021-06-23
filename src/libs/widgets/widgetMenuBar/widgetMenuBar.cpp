#include "widgetMenuBar.h"
WidgetMenuBar::WidgetMenuBar(QWidget* parent)
    : QMenuBar(parent) {
  menuGame.setTitle(tr("Game"));
  menuView.setTitle(tr("View"));
  buildConfigurationMenu();
  addMenu(&menuGame);
  addMenu(&menuView);
  addMenu(&menuConfiguration);
}

void WidgetMenuBar::buildConfigurationMenu() {
  menuConfiguration.setTitle(tr("Configuration"));
  menuConfiguration.addAction(tr("Load game configration"), this,
                                &WidgetMenuBar::openFileDialog);
}

void WidgetMenuBar::openFileDialog() {
  QString fileName = QFileDialog::getOpenFileName();
  if (fileName.isEmpty()) {
    return;
  }
  configFilePath = QDir(fileName);
}

WidgetMenuBar::~WidgetMenuBar() {}
