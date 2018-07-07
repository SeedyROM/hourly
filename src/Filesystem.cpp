//
// Created by rombus on 7/7/18.
//

#include <cstring>

#include "Filesystem.h"

Filesystem::FileNotFound::FileNotFound(std::string path) {
    this->path = std::move(path);
}

const char* Filesystem::FileNotFound::what() const noexcept {
    return "Failed to find file at specified path...";
}

const std::string Filesystem::getCwd() {
    char buff[PATH_MAX];
    getcwd( buff, PATH_MAX );
    std::string cwd( buff );
    return cwd;
}
