/*
Description:
This is a random number generator.
The rand_numbers function generates random numbers using the rand() function.
The linear_congruential_generator function generates random numbers using the linear congruential generator.
The linear congruential generator generates random numbers between 0 and m-1.
The linear congruential generator generates a sequence of random numbers that are not truly random,
it repeats after a certain number of iterations (16).
Author: Pierre Baron
Date: 17/01/2025
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

void rand_numbers(int amount);
void linear_congruential_generator(int amount, int a, int m, int x0);
int main()
{
    rand_numbers(1000);
    linear_congruential_generator(1000, 21, 64, 9);

    return 0;
}
void rand_numbers(int amount)
{
    float x{0.0f};
    srand(time(NULL));
    std::ofstream myfile;
    myfile.open("random_with_rand().txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < amount; i++)
        {
            x = (rand() % 100) / 100.0f;
            myfile << x << std::endl;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}
void linear_congruential_generator(int amount, int a, int m, int x0)
{
    std::ofstream myfile;
    myfile.open("random_with_LCG.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < amount; i++)
        {
            x0 = (a * x0) % m;
            myfile << x0 << std::endl;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}