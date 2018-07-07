//
// Created by rombus on 7/7/18.
//

#include <iostream>
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
    getcwd(buff, PATH_MAX);
    std::string cwd(buff);
    return cwd;
}

const std::string Filesystem::Path::join(const std::vector<std::string>& paths) {
    std::string pathString = paths.front();
    if (pathString[pathString.size() - 1] != '/') {
        pathString.append("/");
    }

    for(int i = 1; i < paths.size(); i++) {
        std::string path = paths[i];
        path = Path::stripPathPart(path);
        pathString.append(path);
    }

    return pathString;
}

const std::string Filesystem::Path::stripPathPart(const std::string pathPart) {
    std::string path = pathPart;

    if(path[0] == '/') {
        path.erase(0, 1);
    }

    if (path[path.size() - 1] != '/') {
        path.append("/");
    }

    return path;
}
