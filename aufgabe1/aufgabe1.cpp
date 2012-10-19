#include <stdio.h>
#include "merge_lists.cpp"

int main()
{
	// assign test values for merge_lists
	// initialize 3 lists and put them together
	// list1 = [10, 7, 3, 1]
	intlist list1;
	list1.push_front(1);
	list1.push_front(3);
	list1.push_front(7);
	list1.push_front(10);
	// list2 = [9, 6, 4]
	intlist list2;
	list2.push_front(4);
	list2.push_front(6);
	list2.push_front(9);
	// list3 = [8, 5, 2]
	intlist list3;
	list3.push_front(2);
	list3.push_front(5);
	list3.push_front(8);

	intlist* lists;
	lists.push_front(list1);
	lists.push_front(list2);
	lists.push_front(list3);
	printf("test\n");
	return 0;
}
