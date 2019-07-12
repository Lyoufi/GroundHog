/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "Groundhog.hpp"

static void usage(const std::string name)
{
    std::string result = "";

    result += "SYNOPSIS\n";
    result += "    " + name;
    result += " period\n\n";
    result += "DESCRIPTION\n";
    result += "    period        ";
    result += "the number of days defining a period";
    std::cout << result << std::endl;
}

static bool is_number(const std::string nb)
{
    for (size_t i = 0 ; i < nb.size() ; ++i) {
        if (nb[i] < '0' || nb[i] > '9')
            return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        usage(av[0]);
        return (84);
    } else if (strcmp(av[1], "-h") == 0) {
        usage(av[0]);
        return (0);
    } else if (!is_number(av[1])) {
        std::cerr << "Invalid arguments" << std::endl;
        return (84);
    }
    Gdhg::Groundhog g(atoi(av[1]));
    if (g.run())
        return (0);
    return (84);
}
