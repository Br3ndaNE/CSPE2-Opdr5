#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := TicTacToeViewText.cpp TicTacToeViewSFML.cpp TicTacToeModel.cpp TicTacToeControl.cpp MoveCommand.cpp

# header files in this project
HEADERS := MoveCommand.hpp Command.hpp TicTacToeControl.hpp TicTacToeModel.hpp TicTacToeViewText.hpp TicTacToeView.hpp TicTacToeViewSFML.hpp 

# other places to look for files for this project
SEARCH  := 

DEFINES := -D SFML_VERSION

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../

include $(RELATIVE)Makefile.native
