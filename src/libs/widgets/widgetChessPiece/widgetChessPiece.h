#pragma once
#include <QLabel>
#include <component/styler/styler.h>
#include <chessElement/chessPiece/chessPiece.h>
#include <ultilities/configurationParser/configurationParser.h>
#include <ui_widgetChessPiece.h>
#include <QDebug>
#include <component/dragger/dragger.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class WidgetChessPiece;
}
QT_END_NAMESPACE
class WidgetChessPiece: public QWidget {
    Q_OBJECT
    public:
        WidgetChessPiece(QWidget *parent, const ChessPiece &chessPiece);
        void resizeEvent(QResizeEvent* e) override;
        void paintEvent(QPaintEvent* e) override;
        void mousePressEvent(QMouseEvent* e) override;
    private:
        bool isSelected;
        bool isHighlighted;
        
        Ui::WidgetChessPiece ui;
        const ChessPiece& chessPiece;
        QPixmap m_piece;
        ConfigurationParser& parser;
        Styler styler;
        Dragger dragger;
        QPixmap getScaledPixmap() const;
};