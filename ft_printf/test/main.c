#include "../inc/ft_printf.h"

int main(void)
{
    t_unt   i;

    i = INT_MAX;
    // ft_printf("%020seeeeee\n", "Hello World!");
    // printf("%020seeeeee\n", "Hello World!");
    ft_printf("%020deeeeee\n", i);
    printf("%020deeeeee\n", i);

    /*int i = ft_printf("%-0s\n%#+d\n%0.0%\n", "Hello World!", 42);
    printf("\n%d\n", i);*/
    return (0);
}