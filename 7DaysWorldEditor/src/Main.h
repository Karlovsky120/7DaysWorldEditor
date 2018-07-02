#pragma once

#include "MainFrame.h"
#include "LogFormatter.h"

#include "wxwidgets.h"

#include <fstream>

class Main : public wxApp {
public:
    virtual bool OnInit();
    virtual int OnExit();

private:
    MainFrame * frame;

    std::ofstream *m_logFile;
    LogFormatter *m_formatter;
};
