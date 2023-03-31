# Makefile for building parser and lexer

# Compiler settings
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11

# Bison and Flex settings
BISON=bison
BISONFLAGS=-d
FLEX=flex

# Executables
TARGET=parser
SOURCES=parser.tab.c lex.yy.c
LIBRARIES=-lfl -lm

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ $(LIBRARIES) -o $@

parser.tab.c: parser.y
	$(BISON) $(BISONFLAGS) $^

lex.yy.c: lexer.l
	$(FLEX) $^

clean:
	rm -f $(TARGET) $(SOURCES)
