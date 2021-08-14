#include "widgetChessBoard.h"
WidgetChessBoard::WidgetChessBoard(QWidget* parent) : StyleWidget<QWidget>(parent), layout(this), controller(ConfigurationParser::constructChessBoard()) {
    ui.setupUi(this);
    setLayout(&layout);
    for (const auto &row: controller.boardArray) {
        for (const auto &cell: row) {
            layout.addWidget(new WidgetChessCell(cell, this));
        }
    }
}

WidgetChessBoard::~WidgetChessBoard() = default;

QDir WidgetChessBoard::cssDir() const {
    return {":/styles/widgetChessBoard"};
}

QString WidgetChessBoard::objectName() const {
    return "widgetChessBoard";
}