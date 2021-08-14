#pragma once
#include <chessElement/chessBoard/chessBoard.h>
#include <chessElement/chessCell/chessCell.h>
#include <ultilities/configurationParser/configurationParser.h>
#include <algorithm>
#include <ui_widgetChessBoard.h>
#include <widgets/widgetChessCell/widgetChessCell.h>
#include <ultilities/function/helper.h>
#include <layout/chessBoardLayout.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class WidgetChessBoard;
}
QT_END_NAMESPACE
class WidgetChessBoard : public StyleWidget<QWidget> {
    Q_OBJECT
    public:
        explicit WidgetChessBoard(QWidget* parent = nullptr);
        ~WidgetChessBoard() override;
    protected:
        QDir cssDir() const override;
        QString objectName() const override;
    private:
        Ui::WidgetChessBoard ui;
        ChessBoard controller;
        ChessBoardLayout layout;
};
