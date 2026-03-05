#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack *a;
	t_stack a4 = {4, 0, NULL};
	t_stack a3 = {3, 0, &a4};
	t_stack	a2 = {2, 0, &a3};
	t_stack a1 = {1, 0, &a2};
	a = &a1;

	t_stack *b;
	t_stack	b4 = {6, 0, NULL};
	t_stack	b3 = {5, 0, &b4};
	t_stack	b2 = {4, 0, &b3};
	t_stack	b1 = {3, 0, &b2};
	b = &b1;

	printf("original A first node: %d\n", a->value);
	printf("original A second node: %d\n", a->next->value);
	printf("original A second node: %d\n", a->next->next->value);
	printf("original A second node: %d\n", a->next->next->next->value);

	sa(&a);
	printf("swap A 1st node: %d\n", a->value);
	printf("swap A 3nd node: %d\n", a->next->value);
	printf("%d\n", a->next->next->value);
	printf("%d\n", a->next->next->next->value);
	
	printf("original B first node: %d\n", b->value);
	printf("original B first node: %d\n", b->next->value);
	printf("original B first node: %d\n", b->next->next->value);
	printf("original B first node: %d\n", b->next->next->next->value);

	sb(&b);
	printf("swap B first node: %d\n", b->value);
	printf("swap B first node: %d\n", b->next->value);
	printf("swap B first node: %d\n", b->next->next->value);
	printf("swap B first node: %d\n", b->next->next->next->value);

	pa(&a, &b);
	printf("%d\n", a->value);
	printf("%d\n", a->next->value);
	printf("%d\n", a->next->next->value);
	printf("%d\n", a->next->next->next->value);

	pb(&b, &a);
	printf("%d\n", b->value);
	printf("%d\n", b->next->value);
	printf("%d\n", b->next->next->value);
	printf("%d\n", b->next->next->next->value);

	ra(&a);
	printf("%d\n", a->value);
	printf("%d\n", a->next->value);
	printf("%d\n", a->next->next->value);
	printf("%d\n", a->next->next->next->value);

	rb(&b);
	printf("%d\n", b->value);
	printf("%d\n", b->next->value);
	printf("%d\n", b->next->next->value);
	printf("%d\n", b->next->next->next->value);

	rra(&a);
	printf("%d\n", a->value);
	printf("%d\n", a->next->value);
	printf("%d\n", a->next->next->value);
	printf("%d\n", a->next->next->next->value);

	rrb(&b);
	printf("%d\n", b->value);
	printf("%d\n", b->next->value);
	printf("%d\n", b->next->next->value);
	printf("%d\n", b->next->next->next->value);

	rrr(&a, &b);
	printf("%d %d\n", a->value, b->value);
	printf("%d %d\n", a->next->value, b->next->value);
	printf("%d %d\n", a->next->next->value, b->next->next->value);
	printf("%d %d\n", a->next->next->next->value, b->next->next->next->value);
}
