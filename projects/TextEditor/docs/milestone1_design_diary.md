# Design Diary
Use this space to talk about your process.  For inspiration, see [my prompts](../../../docs/sample_reflection.md) 

9/10: After a motherboard failure and many setbacks, I finally got my repository merged with master. From there I debugged why VS19 couldn't find 
	pdcurses.dll. The hotfix turned out to be manually throwing the .dll file into the x64 (debug & release) outside of the "Text Editor" project folder. 
	From here I'm unlikely to achieve any meaningful progress by midnight deadline, but at least I'm back at the starting line to actually start working
	in time for milestone 2.
	
9/10.2: Played around with how the PDCurses library is shown onto the screen. Some issues with importing libraries that I'll have to resolve soon. Updated
	guides with some important PDCurses documentation.