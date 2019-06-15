#include "TestEntityWriter.hpp"

#include <string>

#include <src/Objects/Factory.hpp>
#include <src/Test/TestUtils.hpp>
#include "EntityWriter.hpp"

void TestEntityWriter::testFactoryWriter() {
    Position pos(0, 0);

    //TODO bad turns is not tested

    FactoryPtr factory1 = std::make_shared<Factory>(53, Owner::Player1, pos, 5, 2);
    assertEquals<std::string>("53 FACTORY 1 5 2 0 0", EntityWriter::write(factory1, Owner::Player1));

    FactoryPtr factory2 = std::make_shared<Factory>(56, Owner::Neutral, pos, 10, 3);
    assertEquals<std::string>("56 FACTORY 0 10 3 0 0", EntityWriter::write(factory2, Owner::Player2));

    FactoryPtr factory3 = std::make_shared<Factory>(59, Owner::Player2, pos, 0, 1);
    assertEquals<std::string>("59 FACTORY -1 0 1 0 0", EntityWriter::write(factory3, Owner::Player1));
}

void TestEntityWriter::testTroopWriter() {
    Position dummyPos(0, 0);
    FactoryPtr dummyFactory1 = std::make_shared<Factory>(94, Owner::Player1, dummyPos, 5, 2);
    FactoryPtr dummyFactory2 = std::make_shared<Factory>(95, Owner::Player2, dummyPos, 7, 1);
    FactoryPtr dummyFactory3 = std::make_shared<Factory>(96, Owner::Player1, dummyPos, 9, 0);

    TroopPtr troop1 = std::make_shared<Troop>(70, Owner::Player1, dummyFactory1, dummyFactory2, 6, 10);
    assertEquals<std::string>("70 TROOP 1 94 95 10 6", EntityWriter::write(troop1, Owner::Player1));

    TroopPtr troop2 = std::make_shared<Troop>(71, Owner::Player2, dummyFactory2, dummyFactory3, 9, 2);
    assertEquals<std::string>("71 TROOP -1 95 96 2 9", EntityWriter::write(troop2, Owner::Player1));
}

void TestEntityWriter::testBombWriter() {
    Position dummyPos(0, 0);
    FactoryPtr dummyFactory1 = std::make_shared<Factory>(12, Owner::Player1, dummyPos, 4, 2);
    FactoryPtr dummyFactory2 = std::make_shared<Factory>(13, Owner::Player1, dummyPos, 2, 0);
    FactoryPtr dummyFactory3 = std::make_shared<Factory>(14, Owner::Player1, dummyPos, 1, 0);

    BombPtr bomb1 = std::make_shared<Bomb>(105, Owner::Player1, dummyFactory1, dummyFactory2, 6);
    assertEquals<std::string>("105 BOMB 1 12 13 6 0", EntityWriter::write(bomb1, Owner::Player1));

    BombPtr bomb2 = std::make_shared<Bomb>(109, Owner::Player1, dummyFactory2, dummyFactory3, 3);
    assertEquals<std::string>("109 BOMB -1 13 -1 -1 0", EntityWriter::write(bomb2, Owner::Player2));
}