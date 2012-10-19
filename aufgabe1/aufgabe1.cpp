/*
Exercise 1
Author: Markus Deutschl
Date: 19.10.2012
*/
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

	intlist lists[3];
	lists[0] = list1;
	lists[1] = list2;
	lists[2] = list3;
	
	// test the sorting and print results
	printf("Lists to sort:\n");
	for(unsigned int i=0; i<3; i++){
		printf("List %d:", i);
		for (intlist::const_iterator it = lists[i].begin(), end = lists[i].end(); it != end; ++it){
			printf(" %d", *it);
		}
		printf("\n");
	}
	printf("\n");
	intlist result = merge_lists(lists, 3);

	printf("Sorted result:");
	for (intlist::const_iterator it = result.begin(), end = result.end(); it != end; ++it){
		printf(" %d", *it);
	}
	printf("\n");
	return 0;
}
