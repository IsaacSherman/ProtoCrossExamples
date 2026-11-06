#include <iostream>

#include "valueWithUncertainty.pc.h"

int main()
{
    const auto symmetric =
        ValueWithUncertaintyFactory::create_symmetric(10.0, 0.5);
    const auto asymmetric =
        ValueWithUncertaintyFactory::create_asymmetric(10.0, 0.75, 0.25);

    std::cout << symmetric.value()
              << " +/- " << symmetric.positive_uncertainty() << '\n';

    std::cout << asymmetric.value()
              << " +" << asymmetric.positive_uncertainty()
              << " / -" << asymmetric.negative_uncertainty() << '\n';
}
