#include <iostream>
#include <iomanip>

double convert_to_decimal_odds(int american_odds)
{
    return (american_odds > 0) ? (1.0 + static_cast<double>(american_odds) / 100.0)
                                : (1.0 + 100.0 / -static_cast<double>(american_odds));
    float decimal_odds;

}

double kelly_fraction(double p, double decimal_odds) {
    double b = decimal_odds - 1.0;
    double q = 1.0 - p;
    double f = ((b * p - q) / b > 0) ? (b * p - q) / b : 0.0;  // Ensure non-negative fraction
    return f;
}

int main()
{
    double bankroll, user_probability;
    int american_odds;

    // input bankroll
    std::cout << "Enter initial bankroll: $";
    std::cin >> bankroll;

    // input probabilty
    std::cout << "Enter your expert (opinion) for the probabilty of win: %";
    std::cin >> user_probability;
    user_probability /= 100.0;

    // enter sportsbook odds
    std::cout << "Enter sportsbook odds: ";
    std::cin >> american_odds;

    // convert odds and calculate kelly criterion fraction
    double decimal_odds = convert_to_decimal_odds(american_odds);
    double f = kelly_fraction(user_probability, decimal_odds);
   
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n Sportsbook Odds" << american_odds << "\n";
    std::cout << "Decimal Odds: " << decimal_odds << "\n";
    std::cout << "Your Estimated Probability of Win: " << user_probability * 100 << "%\n";
    std::cout << "Kelly Criterion (fraction of bankroll to wager): " << f * 100 << "%\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Recommended Wager Amount: $" << f * bankroll << "\n";
    return 0;
}