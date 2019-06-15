#ifndef RANDOMPLAYER_HPP
#define RANDOMPLAYER_HPP

#include "Player.hpp"

class RandomPlayer : public Player {
public:
    virtual bool setup(std::string) override final;
    virtual std::string getResponse(std::string) override final;
};

#endif // RANDOMPLAYER_HPP
