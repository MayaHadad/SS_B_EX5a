#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer - AscendingIterator")
{
    SUBCASE("AscendingIterator - Begin/End")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();
        auto end = ascIter.end();

        CHECK(*it == 2);
        CHECK(it != end);
    }

    SUBCASE("AscendingIterator - Increment")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(it == ascIter.end());
    }

    SUBCASE("AscendingIterator - Equality")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        MagicalContainer::AscendingIterator it3;

        CHECK(it1 == it2);
        CHECK(it2 == it3);
    }

    SUBCASE("AscendingIterator - Comparison")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator ascIt(container);
        auto it1 = ascIt.begin();
        auto it2 = ascIt.begin();
        auto end = ascIt.end();

        CHECK_EQ(it1, it2);
        CHECK_FALSE(end < it1);
        ++it1;
        CHECK(it2 < it1);
        CHECK(it2 < end);
        ++it1;
        CHECK(it1 < end);
        ++it1;
        CHECK_EQ(it1, end);
    }
}

TEST_CASE("MagicalContainer - SideCrossIterator")
{

    SUBCASE("SideCrossIterator - Begin/End")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::SideCrossIterator crossIter(container);
        auto it = crossIter.begin();
        auto end = crossIter.end();

        CHECK(*it == 2);
        CHECK(it != end);
    }

    SUBCASE("SideCrossIterator - Increment")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::SideCrossIterator crossIter(container);
        auto it = crossIter.begin();

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == crossIter.end());
    }

    SUBCASE("SideCrossIterator - Equality")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        MagicalContainer::SideCrossIterator it3;

        CHECK(it1 == it2);
        CHECK(it2 != it3);
    }

    SUBCASE("SideCrossIterator - Comparison")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        MagicalContainer::SideCrossIterator it3;

        CHECK_FALSE(it1 < it3);
        CHECK_FALSE(it2 < it3);
        CHECK_FALSE(it3 > it1);
        CHECK_FALSE(it3 > it2);

        auto it = it1.begin();
        ++it;
        CHECK(it2 < it);
        CHECK(it3 < it);
    }
}

TEST_CASE("MagicalContainer - PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(13);
    container.addElement(7);
    container.addElement(4);

    SUBCASE("PrimeIterator - Begin/End")
    {

        MagicalContainer::PrimeIterator primeIter(container);
        auto it = primeIter.begin();
        auto end = primeIter.end();

        CHECK(*it == 5);
        CHECK(it != end);
    }

    SUBCASE("PrimeIterator - Increment")
    {
        MagicalContainer::PrimeIterator primeIter(container);
        auto it = primeIter.begin();

        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 13);
        ++it;
        CHECK(it == primeIter.end());
    }

    SUBCASE("PrimeIterator - Equality")
    {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        MagicalContainer::PrimeIterator it3;

        CHECK(it1 == it2);
        CHECK(it2 != it3);
    }

    SUBCASE("PrimeIterator - Comparison")
    {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        MagicalContainer::PrimeIterator it3;

        CHECK_FALSE(it1 < it3);
        CHECK_FALSE(it2 < it3);
        CHECK_FALSE(it3 > it1);
        CHECK_FALSE(it3 > it2);

        auto it = it1.begin();
        ++it;
        CHECK(it2 < it);
        CHECK(it3 < it);
    }
}

TEST_CASE("MagicalContainer - addElement/removeElement")
{

    SUBCASE("addElement - Single Element")
    {
        MagicalContainer container;
        container.addElement(6);

        CHECK(container.size() == 1);
    }

    SUBCASE("addElement - Multiple Elements")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);

        CHECK(container.size() == 3);
    }

    SUBCASE("removeElement - Existing Element")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        container.removeElement(2);

        CHECK(container.size() == 2);
    }

    SUBCASE("removeElement - Non-existing Element")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(2);
        container.addElement(7);
        CHECK_THROWS(container.removeElement(3));

        CHECK(container.size() == 3);
    }
}
