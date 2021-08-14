#include "widgetChessCell.h"

WidgetChessCell::WidgetChessCell(const ChessCell& chessCell, QWidget* parent): StyleWidget<QLabel>(parent), chessCell(chessCell) {
    ui.setupUi(this);
    QDir terrainDir(ConfigurationParser::TERRAIN_RESOURCES.at(chessCell.chessTerrain));
    if (chessCell.standingPiece) {
        QDir pieceDir(ConfigurationParser::PIECE_RESOURCES.at(chessCell.standingPiece->chessTeam).at(chessCell.standingPiece->chessType));
        m_chessPiece = QPixmap(pieceDir.canonicalPath());
    }
    m_terrain = QPixmap(terrainDir.canonicalPath());
}

WidgetChessCell::~WidgetChessCell() = default;

QDir WidgetChessCell::cssDir() const {
    return {":/styles/widgetChessCell"};
}

QString WidgetChessCell::objectName() const {
    return {};
}

void WidgetChessCell::resizeEvent(QResizeEvent *e) {
    QWidget::resizeEvent(e);
    setPixmap(m_terrain.scaled(e->size()));
}
