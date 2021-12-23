#pragma once

#include <QWidget>
#include <utility>
#include <QDropEvent>
#include <QMimeData>
#include <QDragEnterEvent>

class Dropper {
    public:
        explicit Dropper(QWidget* widget);
        ~Dropper();

        void handleDragEnterEvent(QDragEnterEvent* event, const std::function<bool(QDropEvent*)>& shouldAcceptDrop);
        void handleDropEvent(QDropEvent* event, const std::function<bool(QDropEvent*)>& shouldAcceptDrop);
};