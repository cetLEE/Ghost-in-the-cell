#include "InitStringBuilder.hpp"

InitStringBuilder::InitStringBuilder(unsigned int factorySize,
        unsigned int linkSize) : factorySize(factorySize), linkSize(linkSize) {
}

void InitStringBuilder::addLink(const LinkPtr& link) {
    linkStream << link->getOne() << " " << link->getTwo() << " " << link->getDistance() << "\n";
}

std::string InitStringBuilder::build() const {
    return std::to_string(factorySize) + "\n" + std::to_string(linkSize) + "\n" + linkStream.str();
}