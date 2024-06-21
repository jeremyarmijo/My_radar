/*
** EPITECH PROJECT, 2023
** radar
** File description:
** crash plane
*/
#include "my.h"

void put_h(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS]  path_to_script\n");
    my_putstr("  path_to_script    ");
    my_putstr("The path to the script file.\n\n");
    my_putstr("OPTIONS\n  -h\t\t\t print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n  'L' key enable/disable");
    my_putstr("hitboxes and areas.\n");
    my_putstr("  'S' key enable/disable sprites.\n");
}

void print_er(void)
{
    my_putstr("./my_radar: bad arguments: 0 given but 84 is required");
    my_putstr(" retry with -h\n");
}
