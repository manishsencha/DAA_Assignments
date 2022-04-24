#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// merge_sort_one() : Dividing array in 2 equal parts
void merge_one(vector<int> &arr, int left, int mid, int right)
{
    vector<int> left_array(mid - left + 1);
    vector<int> right_array(right - mid);
    for (int i = 0; i < left_array.size(); ++i)
    {
        left_array[i] = arr[i + left];
    }
    for (int i = 0; i < right_array.size(); ++i)
    {
        right_array[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < left_array.size() && j < right_array.size())
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_array.size())
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array.size())
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}
void merge_sort_one(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort_one(arr, left, mid);
    merge_sort_one(arr, mid + 1, right);
    merge_one(arr, left, mid, right);
}

// merge_sort_two(): dividing the array in 2 parts : arr.size()/3 and 2*arr.size()/3
void merge_two(vector<int> &arr, int left, int mid, int right)
{
    vector<int> left_array(mid - left + 1);
    vector<int> right_array(right - mid);
    for (int i = 0; i < left_array.size(); ++i)
    {
        left_array[i] = arr[i + left];
    }
    for (int i = 0; i < right_array.size(); ++i)
    {
        right_array[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < left_array.size() && j < right_array.size())
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_array.size())
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array.size())
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}
void merge_sort_two(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 3;
    merge_sort_two(arr, left, mid);
    merge_sort_two(arr, mid + 1, right);
    merge_two(arr, left, mid, right);
}

// merge_sort_three(): dividing the array in 3 equal parts
void merge_three(vector<int> &arr, int left, int mid_one,
                 int mid_two, int right, vector<int> &res_array)
{
    int i = left, j = mid_one, k = mid_two, l = left;

    while ((i < mid_one) && (j < mid_two) && (k < right))
    {
        if (arr[i] < arr[j])
        {
            if (arr[i] < arr[k])
            {
                res_array[l++] = arr[i++];
            }
            else
            {
                res_array[l++] = arr[k++];
            }
        }
        else
        {
            if (arr[j] < arr[k])
            {
                res_array[l++] = arr[j++];
            }
            else
            {
                res_array[l++] = arr[k++];
            }
        }
    }

    while ((i < mid_one) && (j < mid_two))
    {
        if (arr[i] < arr[j])
        {
            res_array[l++] = arr[i++];
        }
        else
        {
            res_array[l++] = arr[j++];
        }
    }

    while ((j < mid_two) && (k < right))
    {
        if (arr[j] < arr[k])
        {
            res_array[l++] = arr[j++];
        }
        else
        {
            res_array[l++] = arr[k++];
        }
    }

    while ((i < mid_one) && (k < right))
    {
        if (arr[i] < arr[k])
        {
            res_array[l++] = arr[i++];
        }
        else
        {
            res_array[l++] = arr[k++];
        }
    }

    while (i < mid_one)
        res_array[l++] = arr[i++];

    while (j < mid_two)
        res_array[l++] = arr[j++];

    while (k < right)
        res_array[l++] = arr[k++];
}

void merge_sort_three(vector<int> &arr, int left, int right, vector<int> &res_array)
{
    if (right - left < 2)
        return;

    int mid_one = left + ((right - left) / 3);
    int mid_two = left + 2 * ((right - left) / 3) + 1;

    merge_sort_three(arr, left, mid_one, res_array);
    merge_sort_three(arr, mid_one, mid_two, res_array);
    merge_sort_three(arr, mid_two, right, res_array);

    merge_three(arr, left, mid_one, mid_two, right, res_array);
}

// merge_sort_four(): dividing the array in 2 parts : arr.size()/4 and 3*arr.size()/4
void merge_four(vector<int> &arr, int left, int mid, int right)
{
    vector<int> left_array(mid - left + 1);
    vector<int> right_array(right - mid);
    for (int i = 0; i < left_array.size(); ++i)
    {
        left_array[i] = arr[i + left];
    }
    for (int i = 0; i < right_array.size(); ++i)
    {
        right_array[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < left_array.size() && j < right_array.size())
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_array.size())
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array.size())
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}
void merge_sort_four(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 4;
    merge_sort_four(arr, left, mid);
    merge_sort_four(arr, mid + 1, right);
    merge_four(arr, left, mid, right);
}

// merge_sort_five(): dividing the array in 2 parts : arr.size()/5 and 4*arr.size()/5
void merge_five(vector<int> &arr, int left, int mid, int right)
{
    vector<int> left_array(mid - left + 1);
    vector<int> right_array(right - mid);
    for (int i = 0; i < left_array.size(); ++i)
    {
        left_array[i] = arr[i + left];
    }
    for (int i = 0; i < right_array.size(); ++i)
    {
        right_array[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < left_array.size() && j < right_array.size())
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_array.size())
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_array.size())
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}
void merge_sort_five(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 5;
    merge_sort_five(arr, left, mid);
    merge_sort_five(arr, mid + 1, right);
    merge_five(arr, left, mid, right);
}

int main()
{
    freopen("output.json", "w", stdout);
    cout << '{' << endl;
    for (int x = 1; x <= 5; ++x)
    {
        cout << "\"data_" << x << "\": [" << endl;
        for (int t = 1000; t <= 10000; t+= 1000)
        {
            cout << "{" << endl;
            cout << "\"input_size\": " << endl;
            int size = t;
            cout << size << ',' << endl;
            vector<int> v(size);
            for (int i = 0; i < size; ++i)
            {
                v[i] = rand() % 10000;
            }

            vector<int> res = v;

            auto start = high_resolution_clock::now();
            if (x == 1)
            {
                merge_sort_one(v, 0, v.size() - 1);
            }
            else if (x == 2)
            {
                merge_sort_two(v, 0, v.size() - 1);
            }
            else if (x == 3)
            {
                merge_sort_three(v, 0, v.size() - 1, res);
            }
            else if (x == 4)
            {
                merge_sort_four(v, 0, v.size() - 1);
            }
            else if (x == 5)
            {
                merge_sort_five(v, 0, v.size() - 1);
            }
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            auto time = duration.count();

            cout << "\"time\":" << time << endl
                 << "}";

            if (t != 10000)
                cout << ",";
        }
        cout << "]";
        if (x != 5)
            cout << ",";
    }
    cout << '}' << endl;
    return 0;
}