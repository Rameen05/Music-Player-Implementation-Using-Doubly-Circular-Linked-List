//Song.h


#include <iostream>
#include <string>

 class Song {
     
     private:
     std::string songTitle;
     std::string singerName;
     
     public:
     //constructor
     Song(std::string sTitle = "" , std::string sName = ""); 
     
     ~Song(); //destructor 

     std::string getSongTitle() const;      // Returns the song title ie, getters
     std::string getSingerName() const; 
     
     
     void setSongTitle(std::string);  // Sets the song title ie, setters
      void setSingerName(std::string); 
   
    friend std::ostream& operator<<(std::ostream& os, const Song& song);
     
 };
