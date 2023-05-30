#include "MagicalContainer.hpp"
#include <algorithm>

using namespace std;

namespace ariel
{

    void MagicalContainer::addElement(int elem)
    {
        container.push_back(elem);
        sort(container.begin(), container.end());
    }

    void MagicalContainer::removeElement(int elem)
    {
        container.erase(remove(container.begin(), container.end(), elem), container.end());
    }

    size_t MagicalContainer::size() const
    {
        return container.size();
    }

    // AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &mcontainer, size_t indx)
        : _mcontainer(&mcontainer), index(indx)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator()
        : _mcontainer(nullptr), index(0)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : _mcontainer(other._mcontainer), index(other.index)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this != &other)
        {
            _mcontainer = other._mcontainer;
            index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return index < other.index;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return _mcontainer->container.at(index);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++() //++i
    {
        ++index;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(*_mcontainer);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return AscendingIterator(*_mcontainer, _mcontainer->size());
    }

    // SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &mcontainer, size_t end, size_t start)
        : _mcontainer(&mcontainer), _start(start), _end(end), _reverse(false)
    {
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &mcontainer)
        : _mcontainer(&mcontainer), _start(0), _end(mcontainer.size() - 1), _reverse(false)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator()
        : _mcontainer(), _start(0), _end(0), _reverse(false)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : _mcontainer(other._mcontainer), _start(other._start), _end(other._end), _reverse(other._reverse)
    {
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this != &other)
        {
            _mcontainer = other._mcontainer;
            _start = other._start;
            _end = other._end;
            _reverse = other._reverse;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return (_start == other._start && _end == other._end);
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return _start > other._start;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return _start < other._start;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if (_reverse)
            return _mcontainer->container.at(_end);
        return _mcontainer->container.at(_start);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++() //++i
    {
        if (_reverse)
        {
            if (_start <= _end)
                --_end;
        }
        else
        {
            if (_start <= _end)
                ++_start;
        }
        _reverse = !_reverse;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(*_mcontainer);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        size_t mid =_mcontainer->size()/2;
        if(_mcontainer->size()%2==1)
            return SideCrossIterator(*_mcontainer, mid, mid+1);
        return SideCrossIterator(*_mcontainer, mid-1, mid);
    }

    // PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &mcontainer, size_t indx)
        : _mcontainer(&mcontainer), index(indx)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator()
        : _mcontainer(), index(0)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : _mcontainer(other._mcontainer), index(other.index)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this != &other)
        {
            _mcontainer = other._mcontainer;
            index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return index < other.index;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return _mcontainer->container.at(index);
    }

    bool MagicalContainer::PrimeIterator::isPrime(int num)
    {
        if (num < 2)
            return false;
        if (num == 2)
            return true;
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
    {
        do
        {
            ++index;
        } while (index < _mcontainer->size() && !isPrime(*(*this)));

        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        size_t indx = 0;
        while (indx < _mcontainer->size() && !isPrime(*(*this)))
            ++indx;
        if (indx == _mcontainer->size())
            return this->end();
        return PrimeIterator(*_mcontainer, indx);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator(*_mcontainer, _mcontainer->size());
    }
}