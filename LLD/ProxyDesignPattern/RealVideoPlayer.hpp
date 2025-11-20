#include "IVideo.hpp"
#include <string>
#include <iostream>

class RealVideoPlayer: public IVideo {
    private:
      std::string filename;
    
    public:
      RealVideoPlayer(const std::string& filename): filename(filename) {
        std::cout << "[Loading video from disk: " << filename << "]\n";
      }

      void play() override{
        std::cout << "[Playing video: " << filename << "]\n";
      }
};