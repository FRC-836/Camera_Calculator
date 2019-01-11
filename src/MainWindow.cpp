#include "MainWindow.h"

extern OutputManager cout;

//private functions
void MainWindow::makeConnections()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: makeConnections()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)

  connect(m_ui->btnReset, &QPushButton::clicked, this, &MainWindow::btnResetClickHandler);
  connect(m_ui->btnCalculate, &QPushButton::clicked, 
          this, &MainWindow::btnCalculateClickHandler);

  connect(m_ui->actClose, &QAction::triggered, this, &MainWindow::close);
  connect(m_ui->actAbout, &QAction::triggered, this, &MainWindow::actAboutHandler);
}
void MainWindow::reset()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: reset()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)

  //set all the values back to 0
  m_ui->dspnCamPitch->setValue(0.0);
  m_ui->dspnVtWidth->setValue(0.0);
  m_ui->dspnVtHeight->setValue(0.0);
  m_ui->dspnCamFovHor->setValue(0.0);
  m_ui->dspnCamFovVert->setValue(0.0);
  m_ui->dspnCamMinDistance->setValue(0.0);
  m_ui->dspnVtCenterHeight->setValue(0.0);

  //clear the results window since they are now stale
  m_ui->lstResults->clear();
}
void MainWindow::calculateResult()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: calculateResult()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)

  //get values
  auto minDist = m_ui->dspnCamMinDistance->value();
  auto vFov = (m_ui->dspnCamFovVert->value() * 3.14159265) / 180;
  auto camPitch = (m_ui->dspnCamPitch->value() * 3.14159265) / 180;
  auto tgtHeight = m_ui->dspnVtCenterHeight->value();
  auto tgtSizeH = m_ui->dspnVtHeight->value();

  //minCamHeight = minDetectDist * tan((FOVv / 2) + camPitch) + (tgtHeight + (tgtL / 2))
  auto minCamH = -minDist * std::tan((vFov / 2) + camPitch) + (tgtHeight + (tgtSizeH / 2));

  //maxCamheight = minDetectDist * tan((FOVv / 2) - camPitch) + (tgtHeight - (tgtL / 2))
  auto maxCamH = minDist * std::tan((vFov / 2) - camPitch) + (tgtHeight - (tgtSizeH / 2));

  //print to the screen
  m_ui->lstResults->insertItem(0, ""); //blank item to help seperate results
  m_ui->lstResults->insertItem(0, "max: " + QString::number(maxCamH));
  m_ui->lstResults->insertItem(0, "min: " + QString::number(minCamH));
}
void MainWindow::displayAbout()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: displayAbout()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
}

//event handlers
void MainWindow::closeEvent(QCloseEvent* e)
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: closeEvent()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
}

//constructors
MainWindow::MainWindow()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: constructing..." << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)

  m_ui = std::make_unique<Ui_MainWindow>();
  m_ui->setupUi(this);

  makeConnections();
}
MainWindow::~MainWindow()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: destructing..." << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
}

//public slots
void MainWindow::btnResetClickHandler()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: btnResetClickHandler()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  reset();
}
void MainWindow::btnCalculateClickHandler()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: btnCalculateClickHandler()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  calculateResult();
}
void MainWindow::actAboutHandler()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: actAboutHandler()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  displayAbout();
}

