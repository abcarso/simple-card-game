COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp Player.h
	$(COMPILER) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp Player.h -o $(PROGRAM)

clean:
	rm *.out