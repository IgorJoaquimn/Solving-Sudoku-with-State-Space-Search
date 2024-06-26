#
# Copyright 2021 Alysson Ribeiro da Silva - Federal University of Minas Gerais
#
# Permission is hereby granted, free of charge, to any person obtaining a copy 
# of this software and associated documentation files (the "Software"), to deal 
# in the Software without restriction, including without limitation the rights 
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
# of the Software, and to permit persons to whom the Software is furnished to do 
# so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all 
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

# cc and flags
CC = g++ -g
CXXFLAGS = -std=c++17 -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/
INPUT = ../input
OUTPUT = ../output

# all sources, objs, and header files
MAIN = Main
TARGET = TP1
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*

test: all 
	$(BIN_FOLDER)$(TARGET) G 107006450 025340008 060001070 053000029 610009800 000602007 001093200 008000000 040078591

clean_and_execute: all
	./tests.sh -q

test_hard: clean all 
	$(BIN_FOLDER)$(TARGET) G 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400
	$(BIN_FOLDER)$(TARGET) A 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400
	$(BIN_FOLDER)$(TARGET) B 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400
	$(BIN_FOLDER)$(TARGET) I 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400
	$(BIN_FOLDER)$(TARGET) U 800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400
