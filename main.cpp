#include <iostream>
#include <cmath>

using namespace std;

// will need to fix to read a string containing either '+' or '-'
float convert_to_decimal_odds(float american_odds)
{
    float decimal_odds;
    if (american_odds > 0)
    {
        return decimal_odds = (american_odds/100) + 1;
    }
    else {
        return decimal_odds = 1 + (100/abs(american_odds));
    }
}

float net_odds(float odds)
{
    return odds - 1;
}

float kelly_formula(float p, float b)
{
    float fraction_of_bankroll = ((p * b) - 1) / b;
    return fraction_of_bankroll;
}

int main()
{
    float odds = convert_to_decimal_odds(-130);
    cout << "American odds of -130 converts to: " << odds << endl;
    
    float b = net_odds(odds);
    cout << "net odds is " << b << endl;


    float kelly = kelly_formula(0.53, b);
    cout << "kelly formula is: " << kelly << endl;

    return 0;
}