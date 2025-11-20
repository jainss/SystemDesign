#include "IVideo.hpp"
#include "RealVideoPlayer.hpp"
#include <string>
#include <memory>

class ProxyVideoPlayer: public IVideo {
   private:
     std::string filename;
     std::unique_ptr<RealVideoPlayer> realVideoPlayer;

   public:
     ProxyVideoPlayer(const std::string& filename): filename(filename) {}

     void play() override{
        if(!realVideoPlayer){
           realVideoPlayer = std::make_unique<RealVideoPlayer>(filename);
        }
        realVideoPlayer->play();
     }
};