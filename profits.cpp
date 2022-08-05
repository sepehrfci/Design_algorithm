#include <iostream>
using namespace std;
int main()
{
    int n = 9, number_of_checked_ranges = 0;
    int profits[] = {-2, 1, 3, 4, -5, 4, 2, -1, -6};
    int output[2];
    int max_profits = 0;
    int last_positive_number = -1;
    for (int i = n - 1; i >= 0; i--)
        if (profits[i] > 0)
        {
            last_positive_number = i;
            break;
        }

    for (int i = 0; i <= last_positive_number; i++)
    {
        if (profits[i] < 0)
            continue;
        int next_index = i;
        for (int j = i; j <= last_positive_number; j++)
        {
            if (profits[j] < 0 && profits[j + 1] > 0 && next_index == i && j != last_positive_number)
                next_index = j;

            if ((profits[j + 1] > 0 && j != last_positive_number) ||
                (i == j && i < max_profits) ||
                (profits[j] < 0 && profits[j + 1] < 0 && j != last_positive_number))
                continue;

            number_of_checked_ranges++;
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                cout << profits[k] << " ";
                sum += profits[k];
            }
            
            if (sum > max_profits)
            {
                max_profits = sum;
                output[0] = i;
                output[1] = j;
            }
            cout << endl;
        }
        i = next_index;
    }
    cout << "\n\n\n"
         << "[ "<< output[0] << " , " << output[1] << " ] Sum : " << max_profits << endl <<
         "The number of ranges that the program checked : " << number_of_checked_ranges << endl;
    return 0;
}
