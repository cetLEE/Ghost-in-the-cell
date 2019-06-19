#include "TestPosition.hpp"

#include "Position.hpp"
#include "Test/TestUtils.hpp"

void TestPosition::TestDistance() {
    {
        Position p1(0, 0);
        Position p2(3, 4);
        AssertEquals<unsigned int>(5, p1.Distance(p2));
    }
    {
        Position p1(0, 0);
        Position p2(3, 5);
        AssertEquals<unsigned int>(6, p1.Distance(p2));
    }
    {
        Position p1(0, 0);
        Position p2(3, 6);
        AssertEquals<unsigned int>(7, p1.Distance(p2));
    }
    {
        Position p1(0, 0);
        Position p2(3, 7);
        AssertEquals<unsigned int>(8, p1.Distance(p2));
    }
    {
        Position p1(0, 0);
        Position p2(4, 7);
        AssertEquals<unsigned int>(9, p1.Distance(p2));
    }
}
