#include"Header.h"
int main() {
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