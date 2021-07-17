#include "widgetChessBoard.h"

WidgetChessBoard::WidgetChessBoard(QWidget* parent) : QWidget(parent) {
  this->chessBoardController = ConfigurationParser::constructChessBoard(
      QDir(":/config/defaultChessConfig"));
};

void WidgetChessBoard::viewChessBoard() { return; }

WidgetChessBoard::~WidgetChessBoard() {}
