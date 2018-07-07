//
// Created by rombus on 7/7/18.
//

#pragma once

#include <exception>
#include <unistd.h>
#include <linux/limits.h>
#include <cstdlib>
#include <memory>
#include <vector>

namespace Filesystem {
    struct FileNotFound : public std::exception {
        std::string path;

        explicit FileNotFound(std::string path);
        const char* what() const noexcept override;
    };

    const std::string getCwd();

    struct Path {
        static const std::string join(const std::vector<std::string>& paths);
        static const std::string stripPathPart(std::string pathPart);
    };
};
