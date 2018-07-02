#include "LogFormatter.h"

wxString LogFormatter::Format(wxLogLevel level, const wxString &msg, const wxLogRecordInfo &info) const {
    return wxString::Format("[%d] %s(%d) in %s : %s", info.threadId, info.filename, info.line, info.func, msg);
}
