#include "mainwindowUI.h"
MainWindowUI::MainWindowUI(QWidget* parent) :
    QMainWindow(parent),
    elapsedClock(this),
    chessBoard(this),
    styler(this, ":/styles/mainWindowUI"),
    ui() {
    ui.setupUi(this);

    QLayout& layout = *ui.centralwidget->layout();
    layout.addWidget(&elapsedClock);
    layout.addWidget(&chessBoard);
}

MainWindowUI::~MainWindowUI() = default;