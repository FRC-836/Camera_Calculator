#ifndef CAMERA_CALCULATOR_MAIN_WINDOW_H
#define CAMERA_CALCULATOR_MAIN_WINDOW_H

#include <memory>

#include <QMainWindow>

#include "ui_MainWindow.h"
#include "OutputManager.h"
#include "CmdOptions.h"

class MainWindow : public QMainWindow
{
  private:
    //member variables
    std::unique_ptr<Ui_MainWindow> m_ui;

    //private functions
    void makeConnections();

  public:
    //constructors
    MainWindow();
    ~MainWindow();

    //public functions

  signals:
    //signals

  public slots:
    //public slots
    void btnResetClickHandler();

};

#endif
