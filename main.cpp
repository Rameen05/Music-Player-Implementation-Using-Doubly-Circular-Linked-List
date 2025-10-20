//main.cpp

#include "MusicPlayer.h"
#include <iostream>


int main() {
    std::cout << "~~~ Music Player ~~~" << std::endl;

    // Create a MusicPlayer instance
    MusicPlayer player("Doubly Circular Playlist");

    // Add 3 songs
    player.addSong(Song("All too Well", "Taylor Swift"));
    player.addSong(Song("Back to friends ", "Sombr"));
    player.addSong(Song("Atlantis", "Seafret"));

    std::cout << "\n~~~ Initial Playback ~~~ \n";
    player.play();         // play current
    player.next();         // move to next
    player.next();         // move to next
    player.next();         // move to next (wraps around)
    player.previous();     // move back

    std::cout << "\n~~~ Playlist Review ~~~\n";
    player.print(true);    // forward
    player.print(false);   // reverse

    std::cout << "\n~~~ Modifying Playlist ~~~\n";
    player.removeSong();   // remove current song
    player.play();         // play new current
    player.next();
    player.next();
    player.next();

    std::cout << "\n~~~ Final Playlist Review ~~~\n";
    player.print(true);    // forward
    player.print(false);   // reverse

    std::cout << "\nActive DNodes: " << DNode::activeNodes << std::endl;
    std::cout << "~~~ End of Playlist ~~~" << std::endl;

    return 0;
}


