#pragma once

#include <iostream>
#include <vector>

namespace ariel
{
    class MagicalContainer
    {
        std::vector<int> container;

    public:
        void addElement(int elem);
        void removeElement(int elem);
        size_t size() const;

        class AscendingIterator
        {
            const MagicalContainer *_mcontainer;
            size_t index;

        public:
            AscendingIterator(const MagicalContainer &mcontainer, size_t indx = 0);
            AscendingIterator();
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
            const MagicalContainer *_mcontainer;
            size_t _start;
            size_t _end;
            bool _reverse;
            SideCrossIterator(const MagicalContainer &mcontainer, size_t end, size_t start);

        public:
            SideCrossIterator(const MagicalContainer &mcontainer);
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
            size_t getStart(){return _start;}
            size_t getEnd(){return _end;}
            bool getReverse(){return _reverse;}
        };

        class PrimeIterator
        {
            const MagicalContainer *_mcontainer;
            size_t index;
            bool isPrime(int num);

        public:
            PrimeIterator(const MagicalContainer &mcontainer, size_t indx = 0);
            PrimeIterator();
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();
            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}
