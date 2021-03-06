#ifndef SCORE_ANALYZER_CMD_OPTIONS_H
#define SCORE_ANALYZER_CMD_OPTIONS_H

#include <qstring.h>
#include <qmap.h>

#include "OutputManager.h"

class CmdOptions
{
  public:
    enum class VERBOSITY
    {
      NO_INFO,
      ERRORS_ONLY,
      ERRORS_AND_WARNINGS,
      USER_INFO,
      VERBOSE_INFO,
      DEBUG_INFO,
      ALL_INFO
    };
    static const QMap<VERBOSITY, QString> VERBOSITY_STR_MAP;

    static VERBOSITY verbosity; //verbosity of output
};

OutputManager& operator<<(OutputManager& out, CmdOptions::VERBOSITY toPrint);

#endif
