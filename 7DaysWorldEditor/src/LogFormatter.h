#pragma once

#include "wxWidgets.h"

#include <string>
#include <sstream>

class LogFormatter : public wxLogFormatter {
public:
    virtual wxString Format(wxLogLevel level, const wxString &msg, const wxLogRecordInfo &info) const;
};
