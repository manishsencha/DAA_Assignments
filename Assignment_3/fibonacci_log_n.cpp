#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void multiply(long long m[2][2], long long n[2][2])
{
    long long a, b, c, d;
    a = (m[0][0] * n[0][0] + m[0][1] * n[1][0]);
    b = (m[0][0] * n[0][1] + m[0][1] * n[1][1]);
    c = (m[1][0] * n[0][0] + m[1][1] * n[1][0]);
    d = (m[1][0] * n[0][1] + m[1][1] * n[1][1]);

    m[0][0] = a;
    m[0][1] = b;
    m[1][0] = c;
    m[1][1] = d;
}

void power(long long m[2][2], int n)
{
    if (n == 1)
        return;
    power(m, n / 2);
    multiply(m, m);
    long long k[2][2] = {{1, 1}, {1, 0}};
    if (n % 2 != 0)
        multiply(m, k);
}
long long fib(int n)
{
    long long m[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(m, n);
    return m[0][1];
}
int main()
{
    freopen("output_fibonacci_log_n.json", "w", stdout);
    cout << "{\n \"data\":[\n";
    for (int i = 0; i < 30000; ++i)
    {
        cout << "{\n";
        cout << "\"input_size\":" << i << ",\n";
        auto start = high_resolution_clock::now();
        auto res = fib(92);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\"time\":" << duration.count();
        cout << "}";
        if (i < 29999)
        {
            cout << ",";
        }
    }
    cout << "]}";
    return 0;
}
