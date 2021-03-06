#ifndef INJECTABLEBOARD_HPP
#define INJECTABLEBOARD_HPP

#include <memory>

#include "Objects/Board.hpp"

class InjectableBoard;
typedef std::shared_ptr<InjectableBoard> InjectableBoardPtr;

class InjectableBoard : public Board {
public:
    void InjectFactory(FactoryPtr factory);
    void InjectLink(LinkConstPtr link);
    void InjectTroop(TroopPtr troop);
    void InjectBomb(BombPtr bomb);

    std::list<TroopPtr> GetTroops() const;
    std::list<BombPtr> GetBombs() const;
};


#endif // INJECTABLEBOARD_HPP
