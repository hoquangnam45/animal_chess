#include "styler.h"

#include <utility>

Styler::Styler(QWidget* widget, QString cssPath):
    cssPath(std::move(cssPath)),
    widget(widget) {
    setStylesheet();
}

void Styler::setStylesheet() {
    QFile cssFile(cssPath);
    cssFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString css = cssFile.readAll();
    widget->setStyleSheet(css);
}

void Styler::handlePaintEvent() {
    QStyleOption opt;
    opt.initFrom(widget);
    QPainter p(widget);
    widget->style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, widget);
}