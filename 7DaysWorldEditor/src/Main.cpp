#include "Main.h"

#include "PreprocessorConfig.h"

#include "ConfigFile.h"

#include <experimental/filesystem>
#include <memory>
#include <string>

#include "wx/sizer.h"
#include "OpenGLCanvas.h"

ConfigFile saveVersion;
ConfigFile settings;
std::string currentDirectory;
std::string gameInstallDirectory;

bool Main::OnInit() {
    /*wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxFrame *frame = new wxFrame((wxFrame *)NULL, -1, wxT("Hello GL World"), wxPoint(50, 50), wxSize(400, 200));

    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};

    OpenGLCanvas *glPane = new OpenGLCanvas((wxFrame*)frame, args);
    sizer->Add(glPane, 1, wxEXPAND);

    frame->SetSizer(sizer);
    frame->SetAutoLayout(true);

    frame->Show();
    return true;*/

    std::string argv_str(argv[0]);
    currentDirectory = argv_str.substr(0, argv_str.find_last_of("\\")) + "\\";

    std::experimental::filesystem::create_directory("logs");

    m_logFile = new std::ofstream("logs\\main.log", std::ios::out | std::ios::app);
    *m_logFile << "\n\nExecution Started!\n";

    wxLog *logger = new wxLogStream(m_logFile);
    m_formatter = new LogFormatter();
    delete logger->SetFormatter(m_formatter);
    wxLog::SetActiveTarget(logger);

    //Load configs
    saveVersion.open(currentDirectory + "cfg\\currentVersion.ini");
    settings.open(currentDirectory + "cfg\\settings.ini");

    frame = new MainFrame("7 Days World Editor", wxPoint(0, 0), wxSize(1280, 720));

    frame->CenterOnScreen();
    frame->Show(true);

    /*if (!settings.getProperty("gameInstallDirectory", gameInstallDirectory)) {
        std::unique_ptr<wxMessageDialog> gameLocationInfo = std::make_unique<wxMessageDialog>(frame,
                                                                wxT("This program uses 7 Days to Die game files in order to function properly. Please navigate to and select the game executable."),
                                                                wxT("Info"),
                                                                wxOK | wxCANCEL);
        gameLocationInfo->SetOKCancelLabels(wxID_OK, wxID_EXIT);
        int result = gameLocationInfo->ShowModal();

        if (wxID_CANCEL == result) {
            frame->Destroy();
        } else {
            std::unique_ptr<wxFileDialog> gameLocationDialog = std::make_unique<wxFileDialog>(frame,
                                                                wxT("Please navigate to 7DaysToDie.exe"),
                                                                wxT("C:\\Programs\\Steam\\steamapps\\common\\7 Days To Die"),
                                                                wxEmptyString,
                                                                wxT("7DaysToDie.exe|7DaysToDie.exe"),
                                                                wxFD_FILE_MUST_EXIST);
            gameLocationDialog->CenterOnScreen();
            result = gameLocationDialog->ShowModal();

            if (wxID_OK == result && "7DaysToDie.exe" == gameLocationDialog->GetFilename()) {
                std::string installPath = gameLocationDialog->GetPath().ToStdString();
                installPath = installPath.substr(0, installPath.find_last_of('\\') + 1);
                settings.setProperty("gameInstallDirectory", installPath);
                settings.save();
            } else {
                std::unique_ptr<wxMessageDialog> exitDialog = std::make_unique<wxMessageDialog>(frame,
                                                                  wxT("The program cannot function without the game files and will now exit."),
                                                                  wxT("Error"),
                                                                  wxOK);
                exitDialog->SetOKLabel(wxID_EXIT);
                exitDialog->ShowModal();
                frame->Destroy();
            }
        }
    }*/

    return true;
}

int Main::OnExit() {
    *m_logFile << "Execution complete!\n\n\n";
    delete m_logFile;

    return 0;
}

wxIMPLEMENT_APP(Main);

/*#include "PreprocessorConfig.h"

#include "Chunk.h"
#include "RegionFile.h"

#include "ConfigFile.h"
#include "SaveDeflater.h"

#include <plog\Log.h>

#include <experimental/filesystem>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Main.h"

ConfigFile saveVersion;
std::string currentDirectory;

int main(int argc, char* argv[]) {
    {
        std::string argv_str(argv[0]);
        currentDirectory = argv_str.substr(0, argv_str.find_last_of("\\")) + "\\";

        std::experimental::filesystem::create_directory("logs");

    #ifdef _DEBUG
        plog::init(plog::debug, "logs\\main.log");
    #else
        plog::init(plog::error, "logs\\main.log");
    #endif

        LOGD << "\n\n\nExecution started!";

        //Load save version config
        saveVersion.open(currentDirectory + "cfg\\currentVersion.ini");

        SaveDeflater::deflate();

        /*

        //TEST CODE

        for (int k = -4; k < -1; k++) {
            for (int l = -3; l < 1; ++l) {
                RegionFile regionFile(currentDirectory + "A16.3b12\\Region", k, l);

                if (regionFile.timeStamps.capacity() > 0) {
                    regionFile.write(currentDirectory + "A16.3b12\\data");
                    for (int i = 0; i < 32; ++i) {
                        for (int j = 0; j < 32; ++j) {
                            if (regionFile.chunkExists(i, j)) {
                                //if (k == -3 && l == -3 && i == 11 && j == 5) {
                                    Chunk chunk = Chunk();
                                    bool success = regionFile.readChunk(chunk, i, j);

                                    if (success) {
                                        regionFile.writeChunk(chunk, i, j);
                                    }
                                    int a = 0;

                                    std::fstream binR(currentDirectory + "chunk.read.hex", std::ios::in | std::ios::binary);
                                    std::fstream binW(currentDirectory + "chunk.write.hex", std::ios::in | std::ios::binary);

                                    unsigned char *r = new unsigned char(1000000);
                                    unsigned char *w = new unsigned char(1000000);

                                    binR.write((char *)&r[0], 1000000);
                                    binW.write((char *)&r[0], 1000000);

                                    bool flag = false;

                                    for (int k = 0; k < 1000000; ++k) {
                                        flag = *r != *w;
                                    }

                                    if (flag) {
                                        int g = 0;
                                    }

                                    binR.close();
                                    binW.close();
                                //}
                            }
                        }
                    }
                }
            }
        }*/

        //END TEST CODE
/*
        LOGD << "Execution complete!\n\n\n";
    }
    return 0;
}*/
