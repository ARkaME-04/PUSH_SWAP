#include "push_swap.h"

int    main(int argc, char **argv)
{
    t_stack    *a;
    t_stack    *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    parse_args(argc, argv, &a);
    
    // DEBUG - print stack contents
    t_stack *tmp = a;
    while (tmp)
    {
        printf("stack: %d\n", tmp->value);
        tmp = tmp->next;
    }
    
    if (is_sorted(a))
    {
        printf("already sorted!\n");  // DEBUG
        free_stack(&a);
        return (0);
    }
    printf("calling sort_simple\n");  // DEBUG
    sort_simple(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}