#include "main.h"

/**
* ft_putnbr - function
* @nb: the bumber
*
* Return: modification of a  number
*/

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		_putchar(nb + 48);
}
