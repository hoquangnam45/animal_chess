#pragma once
#include <ui_widgetChessCell.h>
#include <QWidget>
#include <chessElement/chessCell/chessCell.h>
#include <QLabel>
#include <chessElement/chessBoard/chessBoard.h>
#include <QResizeEvent>
#include <QLayout>
#include <ultilities/configurationParser/configurationParser.h>
#include <widgets/widgetChessPiece/widgetChessPiece.h>
#include <component/styler/styler.h>
#include <component/dropper/dropper.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class WidgetChessCell;
}
QT_END_NAMESPACE

class WidgetChessCell: public QWidget {
    Q_OBJECT
    private:
        Styler styler;
        const ChessCell& chessCell;
        Ui::WidgetChessCell ui;
        QPixmap m_terrain;
        QPixmap m_chessPiece;
        ConfigurationParser& parser;
        Dropper dropper;
    public:
        WidgetChessCell(QWidget *parent, const ChessCell &chessCell);
        ~WidgetChessCell() override;
        void resizeEvent(QResizeEvent* e) override;
        void updateSize();
        void addPiece();
        void removePiece();
        void dragEnterEvent(QDragEnterEvent* event) override;
        void dropEvent(QDropEvent* event) override;
        static bool shouldAcceptDrop(QDropEvent* event);
        std::unique_ptr<WidgetChessPiece> p_widgetChessPiece;
};