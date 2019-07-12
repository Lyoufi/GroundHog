/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_H_
#define GROUNDHOG_H_

#include <vector>
#include <string>

namespace Gdhg
{

    class Groundhog
    {
        private:
            const int _period;
            std::vector<double> _temps;
            int _iterations;
            bool _nov;
            bool _pos;
            int _switches;
            enum InputValidity {
                STOP,
                OK,
                KO
            };
            bool checkFloat(const std::string &input);
            enum InputValidity checkInput(const std::string &input);
            void operations();
        public:
            Groundhog(const int period);
            ~Groundhog();

            void addVal(const int nb);
            bool run();
    };

}

#endif /* !GROUNDHOG_H_ */
