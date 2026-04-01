*This project has been created as part of the 42 curriculum by mamy-and.*

## LIBFT
## *Description*

The libft is a project of the 42 school whose objective is to recreate a personal library in the C language. This library brings together a set of common functions from libc, as well as additional utility functions, in order to better understand the internal workings of the C language.

## *Project objectives*
- *Understand and reimplement standard libc functions.*
- *Learn about memory management (malloc, free).*
- *Create a reusable codebase for future projects.*
- *Adhere to the 42 school's coding standards.*
## *Homeland I*
## *Implemented functions*

- `ft_memset`: Initializes a memory area with a given value.
- `ft_bzero`: Resets a memory area to zero.
- `ft_memcpy`: Copies a memory area to another without managing overlap.
- `ft_memmove`: Copies a memory area with managing overlap.
- `ft_memchr`: Searches for a specific byte within a memory area.
- `ft_memcmp`: Compares two memory areas.
----
- `ft_strlen`: Calculates the length of a string.
- `ft_strlcpy`: Copies a string, ensuring termination.
- `ft_strlcat`: Concatenates two strings with a maximum size.
- `ft_strchr`: Searches for the first occurrence of a character.
- `ft_strrchr`: Searches for the last occurrence of a character.
- `ft_strncmp`: Compares two strings based on a defined number of characters.
- `ft_strnstr`: Locates a substring within a string.
- `ft_strdup`: Duplicates a string.
---
- `ft_atoi`: Converts a string to an integer.
- `ft_isalpha`: Tests if a character is alphabetic.
- `ft_isdigit`: Tests if a character is numeric.
- `ft_isalnum`: Tests if a character is alphanumeric.
- `ft_isascii`: Tests if a character belongs to the ASCII table.
- `ft_isprint`: Tests if a character is printable.
- `ft_toupper`: Converts a character to uppercase.
- `ft_tolower`: Converts a character to lowercase.

---
## *Homeland II*
## *Additional functions*
- `ft_substr`    :   extrait une sous-chaîne depuis une chaîne donnée.
- `ft_strjoin`   :   concatène deux chaînes dans une nouvelle allocation.
- `ft_strtrim`   :   supprime les caractères spécifiés en début et fin de chaîne.
- `ft_split`     :   découpe une chaîne selon un séparateur.
- `ft_itoa`      :   convertit un entier en chaîne de caractères.
- `ft_strmapi`   :   applique une fonction à chaque caractère d’une chaîne.
- `ft_striteri`  :   applique une fonction à chaque caractère avec son index.
- `ft_putchar_fd`:  écrit un caractère sur un descripteur de fichier.
- `ft_putstr_fd` :  écrit une chaîne sur un descripteur de fichier.
- `ft_putendl_fd`:  écrit une chaîne suivie d’un retour à la ligne.
- `ft_putnbr_fd` :  écrit un nombre sur un descripteur de fichier.

---
## *Homeland III*
## *Linked Lists*
- `ft_lstnew`: Creates a new list item.
- `ft_lstadd_front`: Adds an item to the beginning of the list.
- `ft_lstadd_back`: Adds an item to the end of the list.
- `ft_lstsize`: Returns the number of items.
- `ft_lstlast`: Returns the last item.
- `ft_lstdelone`: Removes an item from the list.
- `ft_lstclear`: Clears and frees the entire list.
- `ft_lstiter`: Applies a function to each item.
- `ft_lstmap`: Creates a new list from a function.
---

## *Instructions*
*The library is compiled using the provided **Makefile**.*
*The **libft** project can be retrieved and compiled by following the steps below.*
### *Cloning the repository*

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-60c47591-d4be-4c73-b73c-fc00505453fd-7236995-mamy-and Libft.a
```
- *Positions itself within the project directory:*
```bash
cd Libft.a
```
- *Compile from library:*
```bash
make
```
- Delete object files (.o):
```bash
make clean
```
- Delete the object files as well as the compiled library (.a and .o):
```bash
make fclean
```
- Clean and then recompile the library:
```bash
make re
```
Using the library
- Once compiled, the library can be used in an external project (replace your_file.c with your file), `-L` tells the compiler to look for libraries in the current directory (.a) and `-lft` corresponds to libft.a.
```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lft
```

## *Resources*

Here are some useful resources to better understand the project and the C language:

---

### *Official documentation and references*
- *Standard C documentation:* [https://en.cppreference.com/w/c](https://en.cppreference.com/w/c)
- *GNU C Library (glibc):* [https://www.gnu.org/software/libc/manual/](https://www.gnu.org/software/libc/manual/)
- *Man pages Unix/Linux (`man` command)*

---

### *Tutoriels et guides*
- *Tutorial on memory management in C:* [https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)  
- *Guide to strings in C:* [https://www.tutorialspoint.com/cprogramming/c_strings.htm](https://www.tutorialspoint.com/cprogramming/c_strings.htm)  
- *Explication des pointeurs et allocations mémoire :* [https://www.learn-c.org/en/Pointers](https://www.learn-c.org/en/Pointers)

---
### *🤖 Using AI*

This project was carried out using traditional educational resources (official documentation, course materials, student discussions), as well as artificial intelligence used as a tool to aid understanding, algorithmic thinking, and the clarification of concepts. AI was not used to directly generate the final code, but rather as a learning aid and for occasional assistance.
### *Projects and Community 42* 
- *Forum and discussions 42:* [https://intra.42.fr](https://intra.42.fr)
---

### *Useful tools*
- *Makefile:* Compilation automation
- *Valgrind:* Memory leak detection (https://valgrind.org/)
- *GDB:* Debugging of the C program

---