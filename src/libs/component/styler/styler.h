#pragma once

#include <QPaintEvent>
#include <QWidget>
#include <QStyleOption>
#include <QFile>
#include <QPainter>

class Styler {
    public:
        explicit Styler(QWidget* widget, QString cssPath);
        void handlePaintEvent();
    private:
        QWidget* widget;
        QString cssPath;
        void setStylesheet();
};
