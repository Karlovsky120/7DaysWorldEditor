#pragma once

#include <string>

class OpenGLInitializer {
public:
    bool static InitializeOpenGL(std::string *error);

private:
    OpenGLInitializer();
    ~OpenGLInitializer();
};

