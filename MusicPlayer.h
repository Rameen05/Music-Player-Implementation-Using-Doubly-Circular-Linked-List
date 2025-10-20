//MusicPlayer.h


#include "CircleDLinkedList.h"
#include <string> 

class MusicPlayer {
    private:
    
    std::string type;
    CircleDLinkedList playlist;
    
    public:
    
    MusicPlayer(std::string);
    virtual ~MusicPlayer();
    
    void play();
    void next(); 
    void previous();
    void addSong(const Song&);
    void removeSong();
    int size() const;
    bool empty() const;
    Song getCurrentSong() const;
    void print(bool); 

  
};
