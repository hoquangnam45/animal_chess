#include "chessBoardLayout.h"

void ChessBoardLayout::addItem(QLayoutItem * item) {
    items.push_back(item);
}

QLayoutItem * ChessBoardLayout::itemAt(int index) const {
    if (index < 0 || index >= items.size()) {
        return nullptr;
    }
    return items[index];
}

QLayoutItem * ChessBoardLayout::takeAt(int index) {
    auto item = itemAt(index);
    if (!item) {
        return item;
    }
    items.erase(items.begin() + index);
    return item;
}

int ChessBoardLayout::count() const {
    return items.size();
}

QSize ChessBoardLayout::sizeHint() const {
    return minimumSize();
}

QSize ChessBoardLayout::minimumSize() const {
    assert(count() == BOARD_HEIGHT * BOARD_WIDTH);
    return {CELL_MIN_SIZE * BOARD_WIDTH, CELL_MIN_SIZE * BOARD_HEIGHT};
}

void ChessBoardLayout::setGeometry(const QRect &rect) {
    if (geometry == rect) {
        return;
    }
    geometry = rect;
    QLayout::setGeometry(geometry);
    int widgetWidth = geometry.width();
    int widgetHeight = geometry.height();
    int boardHeight = widgetHeight;
    QSize cellSize = QSize(boardHeight / BOARD_HEIGHT, boardHeight / BOARD_HEIGHT);
    int boardWidth = cellSize.width() * BOARD_WIDTH;
    QPoint topLeft = QPoint((widgetWidth - boardWidth) / 2, 0);
    for (int i = 0; i < count(); i++) {
        auto item = itemAt(i);
        int row = i / BOARD_WIDTH;
        int col = i % BOARD_WIDTH;
        item->setGeometry(QRect(topLeft + QPoint(col * cellSize.width(), row * cellSize.height()), cellSize));
    }
}

ChessBoardLayout::ChessBoardLayout(QWidget* parent): QLayout(parent) {}

ChessBoardLayout::~ChessBoardLayout() {
    while (auto item = takeAt(0)) {
        delete item;
    }
}
