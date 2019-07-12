/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** Groundhog
*/

#include "Groundhog.hpp"
#include "computations.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Gdhg::Groundhog::Groundhog(const int period)
    : _period(period), _iterations(0), _nov(true), _pos(true), _switches(0)
{
}

Gdhg::Groundhog::~Groundhog()
{
}

void Gdhg::Groundhog::addVal(const int nb)
{
    this->_temps.push_back(nb);
}

bool Gdhg::Groundhog::checkFloat(const std::string &input)
{
    int dotCount = 0;

    for (size_t i = 0 ; i < input.size() ; ++i) {
        if ((input[i] < '0' || input[i] > '9') &&
            input[i] != '.' && input[i] != '-' && input[i] != '+') {
                return (false);
        } else if ((input[i] == '-' || input[i] == '+') && i != 0) {
            return (false);
        } else {
            continue;
        }
    }
    for (size_t j = 0 ; j < input.size() ; ++j) {
        if (input[j] == '.')
            dotCount++;
        if (dotCount > 1)
            return (false);
    }
    return true;
}

enum Gdhg::Groundhog::InputValidity Gdhg::Groundhog::checkInput(const std::string &input)
{
    if (input == "STOP")
        return (STOP);
    else if (!checkFloat(input))
        return (KO);
    else
        return (OK);
}

void Gdhg::Groundhog::operations()
{
    std::string def = "g=nan      r=nan%      s=nan";
    double average = 0.0;
    double dev = 0.0;
    double rate = 0;

    if (this->_iterations < this->_period - 1) {
        std::cout << def << std::endl;
    } else if (this->_iterations == this->_period - 1) {
        dev = compute_deviation(this->_temps, this->_period);
        std::cout << "g=nan" << "      r=" << "nan%      s="
            << std::setprecision(2) << std::fixed << dev << std::endl;
    } else {
        average = compute_average(this->_temps);
        rate = compute_rate(this->_temps);
        dev = compute_deviation(this->_temps, this->_period);

        std::cout << "g=" << std::setprecision(2) << std::fixed << average
            << "      r=" << rate << "%      s="
            << std::setprecision(2) << std::fixed << dev;
        if (!this->_nov) {
            if ((rate < 0 && this->_pos) ||
                (rate > 0 && !this->_pos)) {
                this->_pos = rate >= 0;
                std::cout << "      a switch occurs";
                this->_switches++;
            }
        }
        std::cout << std::endl;
        this->_nov = false;
        this->_temps.erase(this->_temps.begin());
    }
    this->_iterations++;
}

bool Gdhg::Groundhog::run()
{
    std::string userInput = "";
    enum InputValidity check;
    double value = 0.0;
    std::string def = "g=nan      r=nan%      s=nan";

    while (true) {
        if (!std::getline(std::cin, userInput))
            return false;
        check = checkInput(userInput);
        if (check == KO) {
            std::cerr << "Unusable data detected" << std::endl;
            continue;
        } else if (check == STOP) {
            break;
        } else {
            value = std::stold(userInput);
            this->_temps.push_back(value);
        }
        operations();
    }
    if (this->_iterations < this->_period)
        return false;
    std::cout << "Global tendency switched " << this->_switches << " times"
        << std::endl;
    return true;
}