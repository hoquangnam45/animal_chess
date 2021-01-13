#ifndef WIDGETMENUBAR_H
#define WIDGETMENUBAR_H

#include<QMenuBar>
#include<QString>
#include<QDebug>

class widgetMenuBar : public QMenuBar{
    public:
        static widgetMenuBar* setupMenuBar(QWidget* parent = nullptr);
        ~widgetMenuBar();
    private:
        widgetMenuBar(QWidget *parent);
        QMenu *menuGame;
        QMenu *menuView;

};

#endif // WIDGETMENUBAR_H
