#include "mainwindowUI.h"
MainWindowUI::MainWindowUI(QWidget* parent) : StyleWidget<QMainWindow>(parent), elapsedClock(this), chessBoard(this) {
    ui.setupUi(this);

    ui.centralwidget->setObjectName("mainWindowWidget");

    QLayout& layout = *ui.centralwidget->layout();
    layout.addWidget(&elapsedClock);
    layout.addWidget(&chessBoard);
}

MainWindowUI::~MainWindowUI() = default;

QString MainWindowUI::objectName() const {
    return {};
}

QDir MainWindowUI::cssDir() const {
    return {":/styles/mainWindowUI"};
}