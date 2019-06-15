#include "Engine.hpp"

#include <list>
#include <string>
#include <iostream>

Engine::Engine(PlayerPtr player1, PlayerPtr player2) :
        player1(player1),
        player2(player2) {
}

BoardPtr Engine::getBoard() const {
    return board;
}

void Engine::setTable(BoardPtr b) {
    board = b;
}

bool Engine::takeTurn() {
    if (board == nullptr) {
        throw "Board is not initialized.";
    }
    std::cout << "Turn counter: " << turns++ << std::endl;
    if (turns >= MAX_TURNS)
        return true;

    // collect the player's moves
    std::string player1Input = board->getInputForOwner(Player1);
    std::cout << player1Input << std::endl;
    std::string player1Output = player1->getResponse(player1Input);
    std::cout << player1Output << std::endl;

    std::string player2Input = board->getInputForOwner(Player2);
    std::cout << player2Input << std::endl;
    std::string player2Output = player2->getResponse(player2Input);
    std::cout << player2Output << std::endl;

    // execute player's moves
    board->digestOwnerOutput(player1Output, Player1);
    board->digestOwnerOutput(player2Output, Player2);

    // move existing troops and bombs
    board->moveEntities();

    // produce new cyborgs in all factories
    board->produceNewCyborgs();

    // solve battles
    board->solveBattles();

    // make bombs explode
    board->explodeBombs();

    // check end conditions
    return board->checkWinningCondition();
}
