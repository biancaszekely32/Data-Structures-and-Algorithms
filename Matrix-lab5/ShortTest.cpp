#include <assert.h>
#include "Matrix.h"

using namespace std;

void myTest(){
    // Test positionOf
    Matrix m1(4, 4);
    m1.modify(2, 3, 11);
    m1.modify(0, 1, 7);
    std::pair<int, int> p11 = m1.positionOf(11);
    assert(p11.first == 2);
    assert(p11.second == 3);

    std::pair<int, int> p4 = m1.positionOf(4);
    // Should not be found
    assert(p4.first == -1);
    assert(p4.second == -1);

    std::pair<int, int> p7 = m1.positionOf(7);
    assert(p7.first == 0);
    assert(p7.second == 1);
}

void testAll() {
    myTest();
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);


}