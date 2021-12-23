#include "dragger.h"

Dragger::Dragger(QWidget* widget):
    widget(widget) {}

Dragger::~Dragger() = default;

void Dragger::handleMousePressEvent(QMouseEvent* event) {
    if (event->button() != Qt::MouseButton::LeftButton) {
        return;
    }
    auto* dragObject = new QDrag(widget);
    auto* mimeData = new QMimeData();

    auto* label = dynamic_cast<QLabel*>(widget->childAt(event->pos()));
    if (!label) {
        return;
    }
    label->hide();
    mimeData->setObjectName(widget->objectName());
    dragObject->setMimeData(mimeData);
    dragObject->setPixmap(label->pixmap());
    dragObject->setHotSpot(event->pos() - label->pos());
    dragObject->exec();
    label->show();
    delete dragObject;
}