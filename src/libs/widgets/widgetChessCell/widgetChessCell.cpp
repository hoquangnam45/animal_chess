#include "widgetChessCell.h"

WidgetChessCell::WidgetChessCell(QWidget *parent, const ChessCell &chessCell):
    chessCell(chessCell),
    ui(),
    dropper(this),
    styler(this, ":/styles/widgetChessCell"),
    parser(ConfigurationParser::getInstance()) {
    m_terrain = QPixmap(parser.terrainResource(chessCell.chessTerrain));
    ui.setupUi(this);
    ui.terrain->setLayout([] () {
        auto* layout = new QHBoxLayout();
        layout->setContentsMargins(0,0,0,0);
        return layout;
    } ());
    if (chessCell.standingPiece) {
        p_widgetChessPiece = std::make_unique<WidgetChessPiece>(nullptr, *chessCell.standingPiece);
        addPiece();
    }

    ui.topLayout->setContentsMargins(0,0,0,0);
}

WidgetChessCell::~WidgetChessCell() = default;

void WidgetChessCell::resizeEvent(QResizeEvent *e) {
    QWidget::resizeEvent(e);
    ui.terrain->setPixmap(m_terrain.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    updateSize();
}

void WidgetChessCell::updateSize() {
    return ui.terrain->setGeometry(parentWidget()->geometry());
}

void WidgetChessCell::addPiece() {
    ui.terrain->layout()->addWidget(p_widgetChessPiece.get());
}

void WidgetChessCell::removePiece() {
    ui.terrain->layout()->removeWidget(p_widgetChessPiece.get());
}

void WidgetChessCell::dragEnterEvent(QDragEnterEvent *event) {
    dropper.handleDragEnterEvent(event, [] (auto* arg) { return shouldAcceptDrop(arg); });
}

void WidgetChessCell::dropEvent(QDropEvent *event) {
    dropper.handleDropEvent(event, [] (auto* arg) { return shouldAcceptDrop(arg); });
}

bool WidgetChessCell::shouldAcceptDrop(QDropEvent* event) {
    return event->mimeData()->objectName() == "WidgetChessPiece" && event->dropAction() == Qt::MoveAction;
}