Untitled Blob Game
======
SFML Game - Semester Project
------
A point-and-click Tamagotchi-like game made in SFML with no clear objectives other than providing a happy life for a virtual pet (initially a goldfish, currently an unnamed blob, changes in that area still possible in further development).

![blob](https://raw.githubusercontent.com/tusindfryd/untitled-blob-game/master/assets/images/icon.png?raw=true)


Features:
+ Life points based on the time spent playing the game   
   Every set constant number of seconds (10) player gets a point.  
   Opening the game frequently adds points.
+ Saving the progress in a file  
   When starting up the game, the player can choose to start a New Game (which creates a new default game file) or to Load Game (which loads the data from the gamedata.txt file). The button "Save File" overwrites the gamedata.txt file with current data. The saved data includes the number of points, chosen game background, and the time of the last saving. 
+ Feeding the pet   
   Feeding the pet gives points.
+ Minigame   
   A maze game - getting to the apple without touching the walls gives points.
+ Unblocking new background textures   
   Reaching a certain number of points (200, 400, or 600) allows choosing new sceneries.