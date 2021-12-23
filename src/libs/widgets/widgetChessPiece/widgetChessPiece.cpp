#include "widgetChessPiece.h"

WidgetChessPiece::WidgetChessPiece(QWidget *parent, const ChessPiece &chessPiece):
    chessPiece(chessPiece),
    parser(ConfigurationParser::getInstance()),
    ui(),
    dragger(this),
    styler(this, ":/styles/widgetChessPiece") {
    m_piece = QPixmap(parser.pieceResource(chessPiece.chessTeam, chessPiece.chessType));
    ui.setupUi(this);
    ui.topLayout->setContentsMargins(0,0,0,0);
}

void WidgetChessPiece::resizeEvent(QResizeEvent *e) {
    QWidget::resizeEvent(e);
    ui.label->setPixmap(getScaledPixmap());
}

QPixmap WidgetChessPiece::getScaledPixmap() const {
    return m_piece.scaled(parentWidget()->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void WidgetChessPiece::paintEvent(QPaintEvent* e) {
    styler.handlePaintEvent();
}

void WidgetChessPiece::mousePressEvent(QMouseEvent* e) {

    dragger.handleMousePressEvent(e);
}