# Music_Application
A program that facilitates the logic of a music application.


List of source files:   
Album.cc: Entity object, contains information about the album   
Album.h   

Array.h: An abstract container for data with overloaded operators.   

Controller.cc: Control object, controls the interaction of Songify with the View and it contains a playlist of the most currently searched for Songs.   
Controller.h    

Criteria.cc: Entity object, used to match user searches to matching Song objects. There are an additional three derived classes arranged in a diamond hierarchy, A_Criteria, C_Criteria, and AorC_Criteria.   
Criteria.h   
 
defs.h: File which contains preprocessor constants   
 
main.cc: instantiates a Controller object and calls the launch() function   

Makefile: Compiles a single executeable "a4" using the command "make". It also contains a "clean" command which removes the "a4" executeable and any object files. This "clean" command is ran using the default "make clean".   

MediaFactory.cc: Boundary object, used to create Songs, Albums, and Criteria objects. It separates application logic from the creation of Songs, Albums or Criteria types.   
MediaFactory.h   
 
Song.cc: Entity object, contains song information   
Song.h   
 
Songify.cc: Container/Control object, contains a collection of Albums. Users can add/remove Albums or Songs, browse Albums and search Songs to create playlists based on Criteria they specify.      
Songify.h   
 
View.cc: Boundary object, provides a menu, takes input, displays output.   
View.h   


Directory structure:   
media.txt and songinfo.txt are in the folder "media"   

Instructions for compiling code:    
Compile using Makefile command "make", which makes the executeable "a4".   

Instructions for running compiled program:   
Run the executeable using "./a4".     

Other Notes:   
None   
