/*****************************************
*
*	World of const
*
*	(1) the use of const is to protect careless programmer.
*	(2) letting other have confident related to calling subroutine.
*	(3) in C we can still override the const protection.
*	(3.1) So it just a seat balt purpose but user can easily by pass it.
*
*****************************************/

#include <stdio.h>

int doCalc(int a) {
	int x;

	x = a << 1;	/* a * a */
	return x;
}


int doValue(const int & value) {
	int		newvalue;

	newvalue = value * 100;
	printf("doValue: newvalue=%d value=%d value_address=%p\n", newvalue, value, &value);
	// value = newvalue;
	return newvalue ;
}




int main(int ac, char * av[]) {
	int	maxCount;
	int i;
	const int j = 23;

	maxCount = 10;

	for ( i = 0; i < maxCount; i++) {
		printf("Begin loop: i=%d\n",i);
		i = doCalc(i);
		printf("doCalc return: i=%d\n",i);
	}
	printf("LoopExit i=%d\n\n", i);

	int x;

	i = 0;
	x = 123;
	printf("Before doValue i=%d x=%d\n", i, x);

	i =  doValue(x);
	printf("After i=%d x=%d x_address=%p\n", i, x, &x);


	printf("\ntry again\n");
	i =  doValue(456);
	printf("After i=%d x=%d x_address=%p\n", i, x, &x);
	return 0;
}

