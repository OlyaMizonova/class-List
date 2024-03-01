#include"class TList.h"
#include"class_THeadList.h"
#define GTESTs
#ifndef GTESTs
int main() {
	/*THeadList<int> hl;
	hl.insertFirst(1);*/
	TList<int> list;
	for (int i = 0; i < 10; i++) {
		list.insertFirst(i);
	}
	TList<int> tlist(list);
	for (int i = 0; i < 10; i++) {
		list.setPosition(9-i);
		list.deleteCurrent();
		tlist.setPosition(9 - i);
		tlist.deleteCurrent();
	}
	return 0;
}

#else
#include "gtest.h"
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#endif // !GTESTs
/* 
аналитические преобразования с полиномами
P(x,y,z)=
max degree = 9
10*10*10 = max nuber of terms
|kf1 999; ...; kf999 0|
in list just if koeff!=0
will store it sorted
what if (p-p) - is null polinom?
in the beginning will be added a special field kf=0 degree -1
*/