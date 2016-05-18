#include <vector>
#include "test.h"
using namespace std;

//#define DEBUG

#ifdef DEBUG
#include <stdio.h>
int (&debug)(const char *, ...) = *printf;
#else
void debug(...) {}
#endif

/******************************************************************************/

vector<int> findMaxSubarrayLinear(vector<int> array)
{
    if (array.empty())
        return array;
    long left_sum = array[0], cross_sum = array[0];
    vector<int>::size_type left_first = 0, left_last = 1, cross_first = 0;
    for (vector<int>::size_type i = 1; i != array.size(); i++) {
        if (cross_sum < 0) {
            cross_sum = 0;
            cross_first = i;
        }
        cross_sum += array[i];
        if (cross_sum > left_sum) {
            left_sum = cross_sum;
            left_first = cross_first;
            left_last = i + 1;
        }
    }
    vector<int> res;
    for (; left_first != left_last; left_first++)
        res.push_back(array[left_first]);
    return res;
}

/******************************************************************************/

/*
 * We do not generate subarrays. An unique array is used through all iterations.
 * We use xx_first and xx_last to identify a range in the unique array from
 * array[xx_first] to array[xx_last - 1].
 * in_xx indicates the range that is considered in current iteration.
 * out_xx indicates the maximum subarray found by current iteration.
 */
long doFindMaxSubarray(vector<int> &array,
                       vector<int>::size_type in_first,
                       vector<int>::size_type in_last,
                       vector<int>::size_type *out_first,
                       vector<int>::size_type *out_last)
{
    if (in_last - in_first <= 1) {
        *out_first = in_first;
        *out_last = in_last;
        return (in_last > in_first) ? array[in_first] : 0;
    }
    vector<int>::size_type l_first, l_last, r_first, r_last,
                           cross_first, cross_last;
    vector<int>::size_type mid = in_first + (in_last - in_first) / 2;
    long l_sum = doFindMaxSubarray(array, in_first, mid, &l_first, &l_last);
    long r_sum = doFindMaxSubarray(array, mid, in_last, &r_first, &r_last);
    long cross_sum = array[mid - 1] + array[mid];
    cross_first = mid - 1;
    cross_last = mid + 1;
    long sum = cross_sum;
    for (auto i = cross_first - 1; i != in_first - 1; i--) {
        sum += array[i];
        if (sum > cross_sum) {
            cross_sum = sum;
            cross_first = i;
        }
    }
    sum = cross_sum;
    for (auto i = cross_last; i != in_last; i++) {
        sum += array[i];
        if (sum > cross_sum) {
            cross_sum = sum;
            cross_last = i + 1;
        }
    }
    debug("Range: %d -> %d\n", in_first, in_last);
    debug("L sum: %d, R sum: %d, C sum: %d\n", l_sum, r_sum, cross_sum);
    if (cross_sum >= l_sum && cross_sum >= r_sum) {
        *out_first = cross_first;
        *out_last = cross_last;
        return cross_sum;
    } else if (l_sum >= r_sum) {
        *out_first = l_first;
        *out_last = l_last;
        return l_sum;
    } else {
        *out_first = r_first;
        *out_last = r_last;
        return r_sum;
    }
}

vector<int> findMaxSubarray(vector<int> array)
{
    vector<int>::size_type first, last;
    doFindMaxSubarray(array, 0, array.size(), &first, &last);
    vector<int> res;
    for (; first != last; first++)
        res.push_back(array[first]);
    return res;
}

/******************************************************************************/

vector<vector<int>> testcases = {
    {},
    {1},
    {1,-1},
    {-1,0},
    {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7},
    {3,-1,2,4,18,2147483647,0},
    {1,-1,1,-1,1,-1},
    {2,1,-1,0,-1},
    {-5,-2,-4,-3},
};

int main()
{
    Test::test(findMaxSubarray, testcases);
    Test::test(findMaxSubarrayLinear, testcases);
    return 0;
}
