#pragma once

#include "mainwindowUI.h"
class MainWindow: public MainWindowUI {
    Q_OBJECT
    private:
    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow() override;
};
