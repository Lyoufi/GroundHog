/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** computations
*/

#include <vector>
#include <iostream>
#include <cmath>

double compute_average(std::vector<double> v)
{
    double result = 0.0;
    double dif = 0.0;

    for (size_t i = 0 ; i < v.size() - 1 ; ++i) {
        dif = v[i + 1] - v[i];
        if (dif < 0)
            dif = 0;
        result += dif;
    }
    return (result / (v.size() - 1));
}

double compute_rate(std::vector<double> v)
{
    if (v[0] == 0)
        v[0] += 0.000001;
    return round(((v[v.size() - 1] - v[0]) / v[0]) * 100);
}

double compute_deviation(std::vector<double> v, const int period)
{
    int start = 0;
    int j = 0;
    size_t p = period;
    size_t div = period;
    double average = 0.0;
    double total = 0.0;
    std::vector<double> tmp;
    std::vector<double> tmp2;

    if (v.size() > p) {
        j = 1;
        p++;
    }
    start = j;
    for (size_t x = start; x < p ; ++x)
        average += v[x];
    average /= div;
    for (size_t x = start; x < p ; ++x)
        tmp.push_back(v[x] - average);
    start = 0;
    for (size_t x = start; x < div ; ++x) {
        tmp2.push_back(pow(tmp[x], 2));
        total += tmp2[x];
    }
    total /= div;
    return (sqrt(total));
}