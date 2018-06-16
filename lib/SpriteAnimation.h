//
// Created by rombus on 6/16/18.
//

#pragma once

#include <vector>

namespace Animation {
    struct Frame {
        std::vector<std::string> imagePath;
    };

    struct SpriteAnimation {
        std::vector<Animation::Frame> frames;
        SpriteAnimation();
    };
}
