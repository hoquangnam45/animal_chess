#pragma once
#include "styleWidget.h"
// Define the implementation in header
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template <class T>
StyleWidget<T>::StyleWidget(QWidget* parent): T(parent) {}

template <class T>
StyleWidget<T>::~StyleWidget() = default;

template <class T>
void StyleWidget<T>::paintEvent(QPaintEvent *e) {
    T::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    QWidget::style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

template <class T>
void StyleWidget<T>::showEvent(QShowEvent *e) {
    T::showEvent(e);
    setStylesheet(this, cssDir(), objectName());
}