#include"class TList.h"
#include"gtest.h"

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int>list);
}
TEST(TList, can_create_copied_list) {
	TList<int>liist;
	ASSERT_NO_THROW(TList<int> tllist(liist));
}

TEST(TList, can_insert_first) {
	TList<int>list;
	for (int i = 0; i < 50; i++) {
	ASSERT_NO_THROW(list.insertFirst(i));
	list.setPosition(0);
	EXPECT_EQ(list.getCurrent(), i);
	}
}


TEST(TList, can_insert_current) {
	TList<int>list;
	for (int i = 0; i < 50; i++) {
		ASSERT_NO_THROW(list.insertFirst(i));
	}
	list.setPosition(15);
	ASSERT_NO_THROW(list.insertCurrent(15));
	list.setPosition(15);
	EXPECT_EQ(list.getCurrent(),15);
}
TEST(TList, can_insert_last) {
	TList<int>list;
	for (int i = 0; i < 50; i++) {
		ASSERT_NO_THROW(list.insertLast(i));
		list.setPosition(i);
		EXPECT_EQ(list.getCurrent(),i);
	}
}
TEST(TList, can_delete_list) {
	TList<int>list1, list2;
	for (int i = 0; i < 20; i++) {
		list1.insertFirst(i);
	}
	ASSERT_NO_THROW(list1.deleteList());
}
TEST(TList, can_delete_first) {
	TList<int>list;
	for (int i = 0; i < 20; i++) {
		list.insertFirst(i);
	}
	int len = list.getLength();
	for (int i = 0; i < 20; i++) {
		ASSERT_NO_THROW(list.deleteFirst());
		EXPECT_EQ(len-i-1, list.getLength());
	}
}

TEST(TList, can_delete_current) {
	TList<int>list;
	for (int i = 0; i < 5; i++) {
		list.insertFirst(i);
	}
	int len = list.getLength();
	list.setPosition(3);
	for (int i = 0; i < 5; i++) {
		if (i >= 2) { list.setPosition(0); }
		ASSERT_NO_THROW(list.deleteCurrent());
		EXPECT_EQ(len - i - 1, list.getLength());
	}
}

TEST(TList, can_go_next_if_not_the_end) {
	TList<int>list;
	for (int i = 0; i < 50; i++) {
		list.insertFirst(i);
	}
	list.setPosition(0);
	for (int i = 0; i < 50; i++) {
		ASSERT_NO_THROW(list.goNext());
	}
}
TEST(TList, cant_go_next_if_the_end) {
	TList<int>list;
	for (int i = 0; i < 50; i++) {
		list.insertFirst(i);
	}
	list.setPosition(0);
	for (int i = 0; i < 50; i++) {
		ASSERT_NO_THROW(list.goNext());
	}
	ASSERT_ANY_THROW(list.goNext());
}