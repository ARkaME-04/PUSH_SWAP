#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack *a;
	t_stack	a2 = {2, 0, NULL};
	t_stack a1 = {1, 0, &a2};
	a = &a1;

	t_stack *b;
	t_stack	b2 = {4, 0, NULL};
	t_stack	b1 = {3, 0, &b2};
	b = &b1;

	printf("original A first node: %d\n", a->value);
	printf("original A second node: %d\n", a->next->value);

	sa(&a);
	printf("swap A 1st node: %d\n", a->value);
	printf("swap A 3nd node: %d\n", a->next->value);
	
	printf("original B first node: %d\n", b->value);
	printf("original B first node: %d\n", b->next->value);

	sb(&b);
	printf("swap B first node: %d\n", b->value);
	printf("swap B first node: %d\n", b->next->value);
}
