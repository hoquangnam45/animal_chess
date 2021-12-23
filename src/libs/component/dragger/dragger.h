#pragma once
#include <QDrag>
#include <QWidget>
#include <QMouseEvent>
#include <QMimeData>
#include <QLabel>

class Dragger {
    private:
        QWidget* widget;
    public:
        explicit Dragger(QWidget* widget);
        ~Dragger();

        void handleMousePressEvent(QMouseEvent* e);
};