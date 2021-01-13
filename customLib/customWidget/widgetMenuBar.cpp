#include "widgetMenuBar.h"
widgetMenuBar::widgetMenuBar(QWidget* parent) : QMenuBar(parent){
    menuGame = new QMenu(tr("Game"));
    menuView = new QMenu(tr("View"));
    this->addMenu(menuGame);
    this->addMenu(menuView);
}

widgetMenuBar* widgetMenuBar::setupMenuBar(QWidget* parent){
    return new widgetMenuBar(parent);
}

widgetMenuBar::~widgetMenuBar(){
    delete menuGame;
    delete menuView;
}
