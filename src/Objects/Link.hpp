#ifndef LINK_HPP_INCLUDED
#define LINK_HPP_INCLUDED

#include "Factory.hpp"

#include <memory>

class Link;
typedef std::shared_ptr<Link> LinkPtr;
typedef std::shared_ptr<const Link> LinkConstPtr;

class Link {
private:
    unsigned int distance;
    FactoryPtr f1;
    FactoryPtr f2;

public:
    Link(unsigned int, FactoryPtr, FactoryPtr);

    bool either(FactoryPtr f) const;
    unsigned int getDistance() const;
    FactoryPtr other(FactoryPtr) const;

    FactoryPtr getOne() const;
    FactoryPtr getTwo() const;
};

#endif // LINK_HPP_INCLUDED
