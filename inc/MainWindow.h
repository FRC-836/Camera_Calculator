#ifndef CAMERA_CALCULATOR_MAIN_WINDOW_H
#define CAMERA_CALCULATOR_MAIN_WINDOW_H

#include <memory>
#include <cmath>
#include <tuple>

#include <QMainWindow>
#include <QCloseEvent>

#include "ui_MainWindow.h"
#include "OutputManager.h"
#include "CmdOptions.h"

class MainWindow : public QMainWindow
{
  private:
    //enums and types
    enum class ResultHelper
    {
      MIN,
      MAX
    };
    using CalcReturn_t = std::tuple<double, double>;

    //member variables
    std::unique_ptr<Ui_MainWindow> m_ui;

    //private functions
    void makeConnections();
    void reset();
    CalcReturn_t calculateHeights();
    void displayAbout();

  protected:
    //event handlers
    void closeEvent(QCloseEvent* e) override;

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
    void btnCalculateClickHandler();
    void actAboutHandler();
};

#endif
