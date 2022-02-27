#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
class Point
{
private:
    int x, y;

public:
    Point() {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
float dist(Point first, Point second)
{
    return sqrt((first.getX() - second.getX()) * (first.getX() - second.getX()) + (first.getY() - second.getY()) * (first.getY() - second.getY()));
}
float closestPair(vector<Point> &p)
{
    float min = INT_MIN;
    int size = p.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            float d = dist(p[i], p[j]);
            if (d < min)
            {
                min = d;
            }
        }
    }
    return min;
}

int main()
{
    freopen("output_min_point_distance.json", "w", stdout);
    cout << "{\n \"data\":[";
    for (int t = 2; t < 1000; t++)
    {
        cout << "{\n \"input_size\":" << t << ",\n";
        vector<Point> p(t);
        for (int i = 0; i < t; i++)
        {
            int x = rand() % 201 + (-100);
            int y = rand() % 201 + (-100);
            Point *point = new Point(x, y);
            p[i] = *point;
        }
        auto start = high_resolution_clock::now();
        auto res = closestPair(p);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\"output\":" << res << ",\n";
        cout << "\"time\":" << duration.count();
        cout << "\n}";
        if (t < 999)
        {
            cout << ',';
        }
    }
    cout << "]}";
    return 0;
}