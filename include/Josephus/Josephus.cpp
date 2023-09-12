#include<iostream>
#include "Josephus.h"



int main()
{
    int N, M;

    std::cout << "Enter the number of people (N): ";
    std::cin >> N;

    std::cout << "Enter the number of passes (M): ";
    std::cin >> M;

    HotPotato<int> potato;
    potato.createPotato(N);
    potato.eliminatePeople(M);

    int winningPosition = potato.getWinningPosition();

    std::cout << "The winning position is: " << winningPosition << std::endl;

    return 0;
}