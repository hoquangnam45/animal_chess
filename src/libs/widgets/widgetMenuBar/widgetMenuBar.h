#ifndef WIDGETMENUBAR_H
#define WIDGETMENUBAR_H

#include <chessElement/chessBoard/chessBoard.h>
#include <ultilities/configurationParser/configurationParser.h>

#include <QDebug>
#include <QFileDialog>
#include <QMenuBar>
#include <QString>

class WidgetMenuBar : public QMenuBar {
  Q_OBJECT
 public:
  WidgetMenuBar(QWidget *parent = nullptr);
  ~WidgetMenuBar();

 private:
  QMenu menuGame;
  QMenu menuView;
  QMenu menuConfiguration;
  QDir configFilePath;
  void buildConfigurationMenu();

 private slots:
  void openFileDialog();
};

#endif  // WIDGETMENUBAR_H
