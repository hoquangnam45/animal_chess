#include "widgetChessBoard.h"
WidgetChessBoard::WidgetChessBoard(QWidget* parent) :
    layout(this),
    parser(ConfigurationParser::getInstance()),
    ui(),
    styler(this, ":/styles/widgetChessBoard"),
    controller(parser.constructChessBoard(), [this] (auto arg1, auto arg2) { pieceMoved(arg1, arg2); }) {
    ui.setupUi(this);
    setLayout(&layout);
    for (const auto &row: controller.boardArray) {
        processChessWidgetByRow(row);
    }
}

void WidgetChessBoard::processChessWidgetByRow(const std::array<ChessCell, 7> &row) {
    for (const auto &cell: row) {
        moveChessWidgetToPosition(cell);
    }
}

void WidgetChessBoard::moveChessWidgetToPosition(const ChessCell &cell) {
    auto *widget = new WidgetChessCell(this, cell);
    layout.addWidget(widget);
    if (cell.standingPiece) {
        controller.movePiece(ChessPosition(-1, -1), cell.chessPosition);
    }
}

WidgetChessBoard::~WidgetChessBoard() = default;

void WidgetChessBoard::pieceMoved(const ChessPosition& fromPos, const ChessPosition& toPos) {
//    if (fromPos == ChessPosition(-1, -1)) {
//        return;
//    }
//    auto& from = (WidgetChessCell&) *layout.itemAt(ChessBoardLayout::flattenIdx(fromPos))->widget();
//    auto& to = (WidgetChessCell&) *layout.itemAt(ChessBoardLayout::flattenIdx(toPos))->widget();
//
//    to.p_widgetChessPiece = std::move(from.p_widgetChessPiece);
//    from.removePiece();
//    to.addPiece();
}