#ifndef CAMERA_CALCULATOR_MAIN_WINDOW_H
#define CAMERA_CALCULATOR_MAIN_WINDOW_H

#include <memory>
#include <cmath>
#include <tuple>

#include <QMainWindow>
#include <QCloseEvent>
#include <QTextStream>
#include <QDoubleValidator>
#include <QStringList>
#include <QMessageBox>

#include "ui_MainWindow.h"
#include "OutputManager.h"
#include "CmdOptions.h"

class MainWindow : public QMainWindow
{
  private:
    //useful constants
    const double RAD_TO_DEG = 180.0 / 3.14159265;
    const double DEG_TO_RAD = 3.14159265 / 180.0;

    //enums and types
    struct TriangleInfo
    {
      double minDist;
      double camHeight;
      double camOffset;
      double vFov;
      double hFov;
      double camPitch;
      double camYaw;
      double tgtHeight;
      double tgtSizeV;
      double tgtSizeH;
      TriangleInfo(double minDist, double camHeight, double camOffset, double vFov, 
                   double hFov, double camPitch, double camYaw, double tgtHeight, 
                   double tgtSizeV, double tgtSizeH)
      {
        this->minDist = minDist;
        this->camHeight = camHeight;
        this->camOffset = camOffset;
        this->vFov = vFov;
        this->hFov = hFov;
        this->camPitch = camPitch;
        this->camYaw = camYaw;
        this->tgtHeight = tgtHeight;
        this->tgtSizeH = tgtSizeH;
        this->tgtSizeV = tgtSizeV;
      }
      QString toString(const char* prefix = "") const
      {
        QString toReturn;
        QTextStream sstream(&toReturn);
        sstream << prefix << "dist: " << minDist << endl;
        sstream << prefix << QStringLiteral("camHeight: ") << camHeight << endl;
        sstream << prefix << QStringLiteral("camOffset: ") << camOffset << endl;
        sstream << prefix << QStringLiteral("vFov: ") << vFov << endl;
        sstream << prefix << QStringLiteral("hFov: ") << hFov << endl;
        sstream << prefix << QStringLiteral("camPitch: ") << camPitch << endl;
        sstream << prefix << QStringLiteral("camYaw: ") << camYaw << endl;
        sstream << prefix << QStringLiteral("tgtHeight: ") << tgtHeight << endl;
        sstream << prefix << QStringLiteral("tgtSizeH: ") << tgtSizeH << endl;
        sstream << prefix << QStringLiteral("tgtSizeV: ") << tgtSizeV;
        return toReturn;
      }
    };

    //member variables
    std::unique_ptr<Ui_MainWindow> m_ui;

    //private functions
    void makeConnections();
    void setup();
    void reset();
    QStringList calcLocation(const TriangleInfo& params);
    QStringList calcDistance(const TriangleInfo& params);
    QStringList calcFov(const TriangleInfo& params);
    QStringList calcOrientation(const TriangleInfo& params);
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
