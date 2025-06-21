#include "ProxyVideoPlayer.hpp"
#include <iostream>

int main() {
    IVideo* video = new ProxyVideoPlayer("video.mp4");

    std::cout << ">>> First play:\n";
    video->play();

    std::cout << ">>> Second play:\n";
    video->play();

    return 0;
}