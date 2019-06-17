#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L, C, N;
    cin >> L >> C >> N;
    cin.ignore();
    vector<int> group;
    for (int i = 0; i < N; i++)
    {
        int Pi;
        cin >> Pi;
        cin.ignore();
        group.push_back(Pi);
    }

    int sum = 0;
    for (int j = 0; j != C; ++j)
    {
        int one_round = 0;
        vector<int>::size_type index = 0;
        //   vector<int> new_group = group;

        while (index != group.size())
        {
            one_round += group[index];
            if (one_round > L)
            {
                one_round = one_round - group[index];
                rotate(group.begin(), group.begin() + index, group.end());
                break;
                ++index;
            }
        }

        sum += one_round;
    }
    cout << sum << endl;
}