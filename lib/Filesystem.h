//
// Created by rombus on 7/7/18.
//

#pragma once

#include <exception>
#include <unistd.h>
#include <linux/limits.h>
#include <cstdlib>
#include <memory>

namespace Filesystem {
    struct FileNotFound : public std::exception {
        std::string path;

        explicit FileNotFound(std::string path);
        const char* what() const noexcept override;
    };

    const std::string getCwd();
};
