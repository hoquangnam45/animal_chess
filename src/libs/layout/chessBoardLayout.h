#pragma once
#include <QLayout>
#include <QWidget>
#include <vector>
#include <array>
#include <memory>

class ChessBoardLayout: public QLayout {
    private:
        QRect geometry;
        std::vector<QLayoutItem*> items;
        static const int CELL_MIN_SIZE = 60;
    public:
        explicit ChessBoardLayout(QWidget* parent = nullptr);
        ~ChessBoardLayout() override;
        void addItem(QLayoutItem *) override;
        QLayoutItem * itemAt(int index) const override;
        QLayoutItem * takeAt(int index) override;
        int count() const override;
        QSize sizeHint() const override;
        QSize minimumSize() const override;
        void setGeometry(const QRect &) override;
        static const int BOARD_WIDTH = 7;
        static const int BOARD_HEIGHT = 9;
};
