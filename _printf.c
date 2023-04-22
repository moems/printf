#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	char c;

	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			switch (*format++)
			{
				case 'c':
				{
					char arg = va_arg(args, int);
					putchar(arg);
					count++;
					break;
				}
				case 's':
				{
					char *arg = va_arg(args, char *);
					while (*arg != '\0')
					{
						putchar(*arg++);
						count++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
			}
		}
		else
		{
			putchar(c);
			count++;
		}
	}

	va_end(args);
	return (count);
}

