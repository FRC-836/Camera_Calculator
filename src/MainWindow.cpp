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
  connect(m_ui->btnClearHistory, &QPushButton::clicked, 
          m_ui->lstResults, &QListWidget::clear);

  connect(m_ui->actClose, &QAction::triggered, this, &MainWindow::close);
  connect(m_ui->actAbout, &QAction::triggered, this, &MainWindow::actAboutHandler);
}
void MainWindow::setup()
{
}
void MainWindow::reset()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: reset()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)

  //set all the values back to 0
  m_ui->lneCamPitch->clear();
  m_ui->lneCamYaw->clear();
  m_ui->lneVtWidth->clear();
  m_ui->lneVtHeight->clear();
  m_ui->lneCamFovHor->clear();
  m_ui->lneCamFovVert->clear();
  m_ui->lneCamDist->clear();
  m_ui->lneVtCenterHeight->clear();
  m_ui->lneCamHeight->clear();
  m_ui->lneCamOffset->clear();

  //clear the results window since they are now stale
  m_ui->lstResults->clear();
}
MainWindow::CalcReturn_t MainWindow::calcHeight(const TriangleInfo& params)
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: calculateHeights()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)

  //calculate min and max camera heights
  auto minCamH = -params.minDist * std::tan((params.vFov / 2) + params.camPitch) + params.tgtHeight - (params.tgtSizeV / 2);
  auto maxCamH = params.minDist * std::tan((params.vFov / 2) - params.camPitch) + params.tgtHeight + (params.tgtSizeV / 2);

  CalcReturn_t toReturn;
  std::get<(int)ResultHelper::MAX>(toReturn) = maxCamH;
  std::get<(int)ResultHelper::MIN>(toReturn) = minCamH;
  return toReturn;
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
  //get parameters
  auto dist = m_ui->lneCamYaw->text().toDouble();
  auto camHeight = m_ui->lneCamHeight->text().toDouble();
  auto camOffset = m_ui->lneCamOffset->text().toDouble();
  auto vFov = m_ui->lneCamFovVert->text().toDouble() * DEG_TO_RAD;
  auto hFov = m_ui->lneCamFovHor->text().toDouble() * DEG_TO_RAD;
  auto camPitch = m_ui->lneCamPitch->text().toDouble() * DEG_TO_RAD;
  auto camYaw = m_ui->lneCamYaw->text().toDouble() * DEG_TO_RAD;
  auto tgtHeight = m_ui->lneVtCenterHeight->text().toDouble();
  auto tgtSizeV = m_ui->lneVtHeight->text().toDouble();
  auto tgtSizeH = m_ui->lneVtWidth->text().toDouble();

  auto params = TriangleInfo(dist, camHeight, camOffset, vFov, hFov, camPitch, camYaw,
                             tgtHeight, tgtSizeV, tgtSizeH);

  auto results = calcHeight(params);
  auto max = std::get<(int)ResultHelper::MAX>(results);
  auto min = std::get<(int)ResultHelper::MIN>(results);

  //print to the screen
  m_ui->lstResults->insertItem(0, ""); //blank item to help seperate results
  m_ui->lstResults->insertItem(0, "max: " + QString::number(max));
  m_ui->lstResults->insertItem(0, "min: " + QString::number(min));
}
void MainWindow::actAboutHandler()
{
  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  {
    cout << "DEBUG: MainWindow: actAboutHandler()" << endl;
  } //end  if (CmdOptions::verbosity >= CmdOptions::VERBOSITY::DEBUG_INFO)
  displayAbout();
}

