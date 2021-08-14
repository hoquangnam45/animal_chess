#pragma once
#include <QWidget>
#include <QPaintEvent>
#include <QShowEvent>
#include <QStyleOption>
#include <QPainter>
#include <QDir>
#include <QString>
#include <ultilities/function/helper.h>

template <class T>
class StyleWidget: public T {
    public:
        explicit StyleWidget(QWidget *parent = nullptr);
        ~StyleWidget();
        // Have to override this so css component selector work with q_object macro:
        // https://stackoverflow.com/questions/56975868/qt-q-object-macro-causes-unexpected-behaviour-with-style-sheets
        void paintEvent(QPaintEvent* e) override;
        void showEvent(QShowEvent* e) override;
    protected:
        virtual QDir cssDir() const = 0; // Subclass must override this
        virtual QString objectName() const = 0;
};