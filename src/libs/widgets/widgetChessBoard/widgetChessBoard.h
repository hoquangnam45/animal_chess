#pragma once
#include <chessElement/chessBoard/chessBoard.h>
#include <chessElement/chessCell/chessCell.h>
#include <ultilities/configurationParser/configurationParser.h>
#include <algorithm>
#include <ui_widgetChessBoard.h>
#include <widgets/widgetChessCell/widgetChessCell.h>
#include <layout/chessBoardLayout.h>
#include <component/styler/styler.h>
#include <component/dragger/dragger.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class WidgetChessBoard;
}
QT_END_NAMESPACE

class WidgetChessBoard : public QWidget {
    Q_OBJECT
    public:
        explicit WidgetChessBoard(QWidget* parent = nullptr);
        ~WidgetChessBoard() override;
        void pieceMoved(const ChessPosition& fromPos, const ChessPosition& toPos);
    private:
        ConfigurationParser& parser;
        Ui::WidgetChessBoard ui;
        ChessBoard controller;
        ChessBoardLayout layout;
        Styler styler;
        Dragger dragger;
};
