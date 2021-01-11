#include "includes/ft_printf.h"

int main(void)
{
    long i;
    
    i = 500;
    printf("Retour: %d\n", ft_printf("Affiche: %d %s %u %p %c %i\n", 1, "Salut", -155667, &i, 'c', 100));
    printf("Retour: %d\n", printf("Affiche: %d %s %u %p %c %i\n", 1, "Salut", -155667, &i, 'c', 100));
    
    return (0);
}