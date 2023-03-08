#include "ShortTest.h"
#include <assert.h>
#include "Map.h"
#include "MapIterator.h"

bool cond(TKey c)
{
	if (c < 6)
		return true;
	else
		return false;
}

void myTest()
{
	Map m;
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5, 5) == NULL_TVALUE);//0
	assert(m.add(1, 111) == NULL_TVALUE);//1
	assert(m.add(10, 110) == NULL_TVALUE);//2
	assert(m.add(7, 7) == NULL_TVALUE);//3
	assert(m.add(1, 1) == 111);
	assert(m.add(10, 10) == 110);
	assert(m.add(-3, -3) == NULL_TVALUE);//4
	assert(m.size() == 5);
	assert(m.search(10) == 10);
	assert(m.search(16) == NULL_TVALUE);
	assert(m.remove(1) == 1);//4 elem
	assert(m.remove(6) == NULL_TVALUE);
	assert(m.size() == 4);

	m.filter(cond);
	assert(m.size() == 2);
}

void testAll() { //call each function to see if it is implemented
	Map m;
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5,5)==NULL_TVALUE);//0
	assert(m.add(1,111)==NULL_TVALUE);//1
	assert(m.add(10,110)==NULL_TVALUE);//2
	assert(m.add(7,7)==NULL_TVALUE);//3
	assert(m.add(1,1)==111);
	assert(m.add(10,10)==110);
	assert(m.add(-3,-3)==NULL_TVALUE);//4
	assert(m.size() == 5);
	assert(m.search(10) == 10);
	assert(m.search(16) == NULL_TVALUE);
	assert(m.remove(1) == 1);//4 elem
	assert(m.remove(6) == NULL_TVALUE);
	assert(m.size() == 4); 


	TElem e;
	MapIterator id = m.iterator();
	id.first();
	int s1 = 0, s2 = 0;
	while (id.valid()) {
		e = id.getCurrent();
		s1 += e.first;
		s2 += e.second;
		id.next();
	}
	assert(s1 == 19);
	assert(s2 == 19);

}


