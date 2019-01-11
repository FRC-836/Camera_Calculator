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

  //TEMP
  m_ui->lstResults->addItem("Test");
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

