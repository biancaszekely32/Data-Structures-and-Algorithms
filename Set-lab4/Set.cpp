#include "Set.h"
#include "SetITerator.h"
#include <iostream>

int Set::d(TElem e) const {
    return abs(e) % s;
}

Set::Set() {
    s = 10;
    e = new TElem[s];
    next = new int[s];
    for (int i = 0; i < s; i++) {
        e[i] = MAX;
        next[i] = -1;
    }
    firstEmpty = 0;
    nr = 0;
}

void Set::rehash() {
    //BC:theta(n)
    //WC:theta(n)
    //AC:theta(n)
    TElem* old = new TElem[nr];
    for (int i = 0; i < nr; ++i) {
        old[i] = MAX;
    }
    int curent = 0;
    for (int i = 0; i < s; ++i) {
        if (e[i] != MAX) {
            old[curent++] = e[i];
        }
    }

    s *= 2;
    TElem* neww = new TElem[s];
    int* nextNew = new int[s];
    for (int i = 0; i < s; ++i) {
        neww[i] = MAX;
        nextNew[i] = -1;
    }
    delete[] e;
    delete[] next;
    e = neww;
    next = nextNew;

    firstEmpty = 0;
    int oldnr = nr;
    nr = 0;
    for (int i = 0; i < oldnr; ++i) {
        add(old[i]);
    }
    delete[] old;
}


bool Set::add(TElem elem) {
    //BC:theta(1)
    //WC:theta(n)
    //AC:O(n)
    if ((nr / s) * 100 > 70)
        rehash();
    int i = d(elem);
    if (e[i] == MAX)
    {
        e[i] = elem;
        if (i == firstEmpty) {
            firstEmpty++;
            while ((firstEmpty < s) && e[firstEmpty] != MAX)
                firstEmpty++;
        }
        nr++;
        return true;
    }

    int j = -1;
    while (i != -1)
    {
        if (e[i] == elem)
            return false;
        j = i;
        i = next[i];
    }


    e[firstEmpty] = elem;
    next[j] = firstEmpty;
    firstEmpty++;
    while ((firstEmpty < s) && e[firstEmpty] != MAX)
        firstEmpty++;
    nr++;
    return true;
}


bool Set::remove(TElem elem) {
    //BC:theta(1)
    //WC:theta(n)
    //AC:O(n)
    int i = d(elem);
    int j = -1;
    int index = 0;

    while (i != -1 && e[i] != elem) {
        j = i;
        i = next[i];
    }

    if (i == -1) {
        return false;
    }
    else {
        bool ok = false;
        do {
            int curent = next[i];
            int pred = i;

            while (curent != -1 && d(e[curent]) != i) {
                pred = curent;
                curent = next[curent];
            }

            if (curent == -1) {
                ok = true;
            }
            else {
                e[i] = e[curent];
                i = curent;
                j = pred;
            }
        } while (ok == false);

        if (j != -1) {
            next[j] = next[i];
        }
        e[i] = MAX;
        next[i] = -1;
        if (i < firstEmpty) {
            firstEmpty = i;
        }
    }
    --nr;
    return true;
}

bool Set::search(TElem elem) const {
    //BC:theta(1)
    //WC:theta(n)
    //AC:O(n)
    int i = d(elem);
    if (e[i] == elem)
    {
        return true;
    }

    int j = -1;
    while (i != -1)
    {
        if (e[i] == elem)
            return true;
        j = i;
        i = next[i];
    }

    return false;
}


int Set::size() const {
    //Theta(1)
    return nr;
}


bool Set::isEmpty() const {
    //Theta(1)
    return nr == 0;
}


Set::~Set() {
    delete[] e;
    delete[] next;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


