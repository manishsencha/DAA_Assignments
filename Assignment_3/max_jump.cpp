#include <bits/stdc++.h>
using namespace std;

// function to find max jump in an array
int max_jump(vector<int> &v)
{
    int max_j = v[1] - v[0];

    int min_val = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - min_val > max_j)
            max_j = v[i] - min_val;

        if (v[i] < min_val)
            min_val = v[i];
    }

    return max_j;
}

int main()
{
    freopen("output_max_jump.json", "w", stdout);
    cout << "{\"data\":[\n";
    for (int t = 1000; t <= 10000; t += 1000)
    {

        vector<int> v(t);
        for (int i = 0; i < t; ++i)
        {
            v[i] = rand() % 50;
        }
        cout << "{\"input_size\":" << t << ",\n";
        auto start = std::chrono::high_resolution_clock::now();
        auto res = max_jump(v);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << "\"time\":" << duration.count() << "\n";
        cout << "}";
        if (t < 9999)
        {
            cout << ",\n";
        }
    }
    cout << "]}";
    return 0;
}