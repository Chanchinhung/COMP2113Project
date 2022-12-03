FLAGS = -pedantic-errors -std=c++11

Card.o: Card.cpp Card.h
	g++ $(FLAGS) -c $<
DealCard.o: DealCard.cpp DealCard.h Card.h
	g++ $(FLAGS) -c $<
DetermineWinner.o: DetermineWinner.cpp DetermineWinner.h DisplayHand.h Card.h
	g++ $(FLAGS) -c $<
DisplayHand.o: DisplayHand.cpp DisplayHand.h Card.h
	g++ $(FLAGS) -c $<
PlayRound.o: PlayRound.cpp DealCard.h DisplayHand.h PlayRound.h Card.h RoundStat.h DetermineWinner.h
	g++ $(FLAGS) -c $<
#playroundtest.o: playroundtest.cpp PlayRound.h Card.h RoundStat.h
#	g++ $(FLAGS) -c $<
#playroundtest: playroundtest.o DetermineWinner.o DisplayHand.o DealCard.o Card.o DetermineWinner.o PlayRound.o
#	g++ $(FLAGS) $^ -o playroundtest
GameMenu.o: GameMenu.cpp GameMenu.h RoundStat.h SaveLoadGame.h PlayRound.h
	g++ $(FLAGS) -c $<
main.o: main.cpp GameMenu.h RoundStat.h
	g++ $(FLAGS) -c $<
SaveLoadGame.o: SaveLoadGame.cpp RoundStat.h
	g++ $(FLAGS) -c $<
main: GameMenu.o main.o SaveLoadGame.o DetermineWinner.o DisplayHand.o DealCard.o Card.o DetermineWinner.o PlayRound.o
	g++ $(FLAGS) $^ -o main

clean:
	rm -f *.o
.PHONY: clean

