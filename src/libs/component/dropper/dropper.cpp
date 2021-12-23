#include "dropper.h"


Dropper::Dropper(QWidget *widget) {
    widget->setAcceptDrops(true);
}

void Dropper::handleDropEvent(QDropEvent *event, const std::function<bool(QDropEvent*)>& shouldAcceptDrop) {
    if (!shouldAcceptDrop(event)) {
        return;
    }
    event->acceptProposedAction();
}

void Dropper::handleDragEnterEvent(QDragEnterEvent *event, const std::function<bool(QDropEvent*)>& shouldAcceptDrop) {
    if (!shouldAcceptDrop(event)) {
        return;
    }
    event->acceptProposedAction();
}

Dropper::~Dropper() = default;

