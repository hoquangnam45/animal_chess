#ifndef WIDGETMENUBAR_H
#define WIDGETMENUBAR_H

#include <chessElement/chessBoard/chessBoard.h>
#include <ultilities/configurationParser/configurationParser.h>

#include <QDebug>
#include <QFileDialog>
#include <QMenuBar>
#include <QString>
extern ConfigurationParser configParser;
extern ChessBoard chessBoard;
class WidgetMenuBar : public QMenuBar {
  Q_OBJECT
 public:
  static WidgetMenuBar *setupMenuBar(QWidget *parent = nullptr);
  ~WidgetMenuBar();

 private:
  WidgetMenuBar(QWidget *parent);
  QMenu *buildConfigurationMenu();

  QMenu *menuGame = nullptr;
  QMenu *menuView = nullptr;
  QMenu *menuConfiguration = nullptr;

 private slots:
  void openFileDialog();
};

#endif  // WIDGETMENUBAR_H
