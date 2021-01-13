#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    QWidget* mainWindowWidget = new QWidget();
    QVBoxLayout* mainWindowLayout = new QVBoxLayout();
    mainWindowWidget->setLayout(mainWindowLayout);
    mainWindowLayout->setMargin(0);

    gameMenuBar = widgetMenuBar::setupMenuBar();
    mainWindowLayout->setMenuBar(gameMenuBar);

    widgetElapsedClock* elapsedClock = widgetElapsedClock::createElapsedClock();
    mainWindowLayout->setAlignment(Qt::AlignTop);
    mainWindowLayout->addWidget(elapsedClock);

    widgetChessBoard* chessBoard = widgetChessBoard::initBoard();

    this->setCentralWidget(mainWindowWidget);
}

MainWindow::~MainWindow(){
    delete ui;
}

MainWindow* MainWindow::animalChessApp(QWidget *parent){
    return new MainWindow(parent);
}
