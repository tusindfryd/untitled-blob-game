SFML Game - Semester Project Concept 
------
A point-and-click Tamagotchi-like game made in SFML with no clear objectives other than providing a happy life for a virtual pet (initially a goldfish, currently an unnamed blob, changes in that area still possible in further development).

![blob](https://github.com/tusindfryd/untitled-blob-game/blob/master/icon2.png?raw=true)

Features to implement:
+ Life points based on the time spent playing the game   
   Every set constant number of seconds (15) player gets a point.  
+ Saving the progress in a file  
   When starting up the game, the player can choose to start a New Game (which creates a new default game file) or to Load Game (which loads the data from the gamedata.txt file). The button "Save File" overwrites the gamedata.txt file with current data.  
+ Pet growing depending on the life points   
   The sprite of the pet is scaled with regards to the life points and the texture changes every milestone (like every 50 life points or so).  
+ Feeding the pet   
   The pet gets hungry every time the life points are divided by some set constant without the remainder. The texture changes and a "Feed" button appears. Feeding increases life points.  
+ Minigame   
   A catch game; the score gets added to the life points.
+ Unblocking new background textures   
   Reaching a certain number of points allows choosing new sceneries.

Additionally, more minigames could be implemented:
+ Space Invaders kind of game
+ Don't Touch the Walls maze kind of game
