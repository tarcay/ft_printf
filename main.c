#include <stdio.h>
#include "includes/ft_printf.h"

//******************************
// Print lst for printf
//******************************

void print(t_flags *lst)
{
    t_flags *lst_tmp;

    lst_tmp = lst;
    while (lst_tmp)
    {
        printf("#--------------#\n");
        printf("Type : %c\n", lst_tmp->type);
        printf("Zero : %d\n", lst_tmp->zero);
        printf("Dot : %d\n", lst_tmp->dot);
        printf("Star : %d\n", lst_tmp->star);
        printf("Minius : %d\n", lst_tmp->minius);
        printf("Size : %d\n", lst_tmp->size_flag);
        printf("Width : %d\n", lst_tmp->width);
        printf("#--------------#\n");
        lst_tmp = lst_tmp->next;
    }
}

//******************************
// Main for printf
//******************************

int main(void)
{
    // char *str = "%.*s";
    // t_flags	*format_lst;

	// ft_create_lst_format(&format_lst, str);
    // print(format_lst);
	// ft_lst_free(&format_lst);

    printf(" [%d]\n", printf("%.*s", -3, "OK"));
    printf(" [%d]\n", ft_printf("%.*s", -3, "OK"));
    
    return (0);
}