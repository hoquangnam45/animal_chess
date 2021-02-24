#include "widgetMenuBar.h"
WidgetMenuBar::WidgetMenuBar(QWidget* parent) : QMenuBar(parent) {
  menuGame = new QMenu(tr("Game"));
  menuView = new QMenu(tr("View"));
  menuConfiguration = buildConfigurationMenu();
  this->addMenu(menuGame);
  this->addMenu(menuView);
  this->addMenu(menuConfiguration);
}

QMenu* WidgetMenuBar::buildConfigurationMenu() {
  if (menuConfiguration) {
    delete menuConfiguration;
    menuConfiguration = nullptr;
  }
  QMenu* configurationMenu = new QMenu(tr("Configuration"));
  configurationMenu->addAction(tr("Load game configration"), this,
                               &WidgetMenuBar::openFileDialog);
  return configurationMenu;
}
void WidgetMenuBar::openFileDialog() {
  QString fileName = QFileDialog::getOpenFileName();
  if (!fileName) chessBoard = configParser.contructDefaultChessBoard();
  chessBoard = configParser.constructChessBoard(fileName);
}
WidgetMenuBar* WidgetMenuBar::setupMenuBar(QWidget* parent) {
  return new WidgetMenuBar(parent);
}

WidgetMenuBar::~WidgetMenuBar() {
  if (menuGame) delete menuGame;
  if (menuView) delete menuView;
  if (menuConfiguration) delete menuConfiguration;
}
