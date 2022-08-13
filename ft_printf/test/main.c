#include "../inc/ft_printf.h"

int main(void)
{
    t_unt   i;

    i = 1234;
    ft_printf("%20seeeeee\n", "Hello World!");
    printf("%20seeeeee\n", "Hello World!");
    // ft_printf("%20deeeeee\n", i);
    // printf("%20deeeeee\n", i);

    /*int i = ft_printf("%-0s\n%#+d\n%0.0%\n", "Hello World!", 42);
    printf("\n%d\n", i);*/
    return (0);
}