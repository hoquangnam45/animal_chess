#pragma once
#include <ui_widgetChessCell.h>
#include <QWidget>
#include <chessElement/chessCell/chessCell.h>
#include <QLabel>
#include <chessElement/chessBoard/chessBoard.h>
#include <ultilities/function/helper.h>
#include <QResizeEvent>
#include <QLayout>
#include <ultilities/configurationParser/configurationParser.h>
#include <widgets/styleWidget/styleWidget.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
    class WidgetChessCell;
}
QT_END_NAMESPACE

class WidgetChessCell: public StyleWidget<QLabel> {
    Q_OBJECT
    private:
        Ui::WidgetChessCell ui;
        QPixmap m_terrain;
        QPixmap m_chessPiece;
        const ChessCell& chessCell;
    protected:
        QDir cssDir() const override;
        QString objectName() const override;
    public:
        explicit WidgetChessCell(const ChessCell& chessCell, QWidget* parent = nullptr);
        ~WidgetChessCell() override;
        void resizeEvent(QResizeEvent* e) override;
};