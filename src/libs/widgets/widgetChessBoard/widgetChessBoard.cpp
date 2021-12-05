#include "widgetChessBoard.h"
WidgetChessBoard::WidgetChessBoard(QWidget* parent) :
    layout(this),
    parser(ConfigurationParser::getInstance()),
    ui(),
    styler(this, ":/styles/widgetChessBoard"),
    // https://stackoverflow.com/questions/7582546/using-generic-stdfunction-objects-with-member-functions-in-one-class
    controller(parser.constructChessBoard(), std::bind(&WidgetChessBoard::pieceMoved, this, std::placeholders::_1, std::placeholders::_2)) {
    ui.setupUi(this);
    setLayout(&layout);
    for (const auto &row: controller.boardArray) {
        for (const auto &cell: row) {
            auto *widget = new WidgetChessCell(this, cell);
            layout.addWidget(widget);
            if (cell.standingPiece) {
                controller.movePiece(ChessPosition(-1, -1), cell.chessPosition);
            }
        }
    }
}

WidgetChessBoard::~WidgetChessBoard() = default;

void WidgetChessBoard::pieceMoved(const ChessPosition& fromPos, const ChessPosition& toPos) {
    if (fromPos == ChessPosition(-1, -1)) {
        return;
    }
    auto& from = (WidgetChessCell&) *layout.itemAt(ChessBoardLayout::flattenIdx(fromPos))->widget();
    auto& to = (WidgetChessCell&) *layout.itemAt(ChessBoardLayout::flattenIdx(toPos))->widget();

    to.p_widgetChessPiece = std::move(from.p_widgetChessPiece);
    from.removePiece();
    to.addPiece();
}