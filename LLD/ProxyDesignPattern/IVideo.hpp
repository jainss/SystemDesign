#pragma once

class IVideo {
    public:
      virtual void play() = 0;
      virtual ~IVideo() = default;
};