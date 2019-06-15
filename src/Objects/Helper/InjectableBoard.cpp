#include "InjectableBoard.hpp"

void InjectableBoard::injectFactory(FactoryPtr factory) {
    factories.push_back(factory);
}

void InjectableBoard::injectTroop(TroopPtr troop) {
    troops.push_back(troop);
    // TODO optionally check whether origin/target is valid
}