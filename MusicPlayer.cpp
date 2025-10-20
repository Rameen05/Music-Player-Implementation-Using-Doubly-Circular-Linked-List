//MusicPlayer.cpp

#include "MusicPlayer.h"
#include <iostream>


    MusicPlayer::MusicPlayer(std::string t) : type(t) {}


    MusicPlayer::~MusicPlayer() {}

    // Play the current song
    void MusicPlayer::play() {
    if (playlist.empty()) {
        std::cout << "No songs to play.\n";
        return;
    }
    std::cout << "Playing: " << playlist.getCurrentSong() << std::endl;
    }

    // Move to next song and play
    void MusicPlayer::next() {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    playlist.advance();
    play();
    }

    // Move to previous song and play
    void MusicPlayer::previous() {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    playlist.retreat();
    play();
    }

    // Add song to the playlist
    void MusicPlayer::addSong(const Song& s) {
    playlist.add(s);
    std::cout << "Added: " << s << std::endl;
    }

    // Remove current song
    void MusicPlayer::removeSong() {
    if (playlist.empty()) {
        std::cout << "No songs to remove.\n";
        return;
    }
    Song removed = playlist.getCurrentSong();
    playlist.remove();
    std::cout << "Removed: " << removed << std::endl;
    }

    // Get number of songs
    int MusicPlayer::size() const {
    return playlist.size();
    }

    // Check if empty
    bool MusicPlayer::empty() const {
    return playlist.empty();
    }

    // Get current song
    Song MusicPlayer::getCurrentSong() const {
    return playlist.getCurrentSong();
    }

    // Recursive print function
    void MusicPlayer::print(bool forward) {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    std::cout << (forward ? "Playlist (Forward): " : "Playlist (Reverse): ");
    playlist.print(forward);
    }
