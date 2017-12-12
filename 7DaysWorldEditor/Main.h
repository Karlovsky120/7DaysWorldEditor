#pragma once

#include "MainFrame.h"
#include "LogFormatter.h"

#include "wxwidgets.h"

#include <fstream>

class Main : public wxApp {
private:
	MainFrame *frame;

	std::ofstream *m_logFile;
	LogFormatter *m_formatter;

public:
	virtual bool OnInit();
	virtual int OnExit();
};

