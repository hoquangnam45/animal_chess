#include "helper.h"

void setStylesheet(QWidget *widget, const QDir &dir) {
    QFile cssFile(dir.canonicalPath());
    cssFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString css = cssFile.readAll();
    widget->setStyleSheet(css);
}

void setStylesheet(QWidget *widget, const QDir &dir, const QString &widgetName) {
    setStylesheet(widget, dir);
    widget->setObjectName(widgetName);
}