#include "SetIterator.h"
#include "Set.h"

void SetIterator::rehash()
{
    while ((curent < set.s) && set.e[curent] == MAX )
        curent++;
}

SetIterator::SetIterator(const Set& m) : set(m)
{
    curent = 0;
    rehash();
}


void SetIterator::first() {
    curent = 0;
    rehash();
}


void SetIterator::next() {
    curent++;
    rehash();
}

void SetIterator::previous(){
    curent--;
    while ((curent >= 0) && set.e[curent] == MAX)
        curent--;
}

TElem SetIterator::getCurrent()
{
    return set.e[curent];
}

bool SetIterator::valid() const {
    return (curent < set.s && curent >= 0);
}



