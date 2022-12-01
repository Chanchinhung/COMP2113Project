CardValSum.o: CardValSum.cpp CardValSum.h Cards.h
	g++ -c CardValSum.cpp
DealCard.o: DealCard.cpp DealCard.h Cards.h
	g++ -c DealCard.cpp
DisplayHand.o: DisplayHand.cpp DisplayHand.h Cards.h
	g++ -c DisplayHand.cpp
DetermineWinner.o: DetermineWinner.cpp DetermineWinner.h CardValSum.h Cards.h
	g++ -c DetermineWinner.cpp
PlayRound.o: PlayRound.cpp PlayRound.h RoundStat.h Cards.h
	g++ -c PlayRound.cpp
playroundtest.o: playroundtest.cpp CardValSum.h DealCard.h DisplayHand.h PlayRound.h Cards.h RoundStat.h
	g++ -c playroundtest.cpp
main: playroundtest.o CardValSum.o DealCard.o DisplayHand.o PlayRound.o
	g++ playroundtest.o CardValSum.o DealCard.o DisplayHand.o DetermineWinner.o PlayRound.o -o main
clean:
	rm -f main playroundtest.o CardValSum.o DealCard.o DisplayHand.o DetermineWinner.o PlayRound.o
.PHONY: clean

