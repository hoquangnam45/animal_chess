#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QWidget* mainWindowWidget = new QWidget();

  mainWindowWidget->setLayout(&mainWindowLayout);
  mainWindowLayout.setMargin(0);

  mainWindowLayout.setMenuBar(&gameMenuBar);

  mainWindowLayout.setAlignment(Qt::AlignTop);
  mainWindowLayout.addWidget(&elapsedClock);

  mainWindowLayout.addWidget(&chessBoard);

  setCentralWidget(mainWindowWidget);
}

MainWindow::~MainWindow() { delete ui; }