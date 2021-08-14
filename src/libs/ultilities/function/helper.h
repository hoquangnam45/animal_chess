#pragma once
#include <QWidget>
#include <QDir>
#include <QString>

void setStylesheet(QWidget *widget, const QDir &dir);

void setStylesheet(QWidget *widget, const QDir &dir, const QString &widgetName);
