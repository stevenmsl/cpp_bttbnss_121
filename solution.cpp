#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol121;
using namespace std;

/*takeaways
  - can't use brute price as its time complexity will be O(n^2)
  - use DP
*/

int Solution::maxProfit(vector<int> &prices)
{
  int n = prices.size();
  /* keep a record what's the min price up to
     the jth day
  */
  auto minPrice = vector<int>(n);
  /* keep a record what's the max profit up to
     the jth day
  */
  auto maxProfit = vector<int>(n);

  minPrice[0] = prices[0];
  /* no profit if you buy and sell on the same day */
  maxProfit[0] = 0;

  for (auto i = 1; i < n; i++)
  {
    /* carry over or update the min price */
    minPrice[i] = min(minPrice[i - 1], prices[i]);

    /* the smallest max profit has been set to 0 initially
       if you sell and buy a share at the same day the
       profit will be 0 anyway and will not change the
       max profit
      so
      max(maxProfit[i - 1], prices[i] - minPrice[i - 1])
      and
      max(maxProfit[i - 1], prices[i] - minPrice[i])
      will be the same

    */
    maxProfit[i] = max(maxProfit[i - 1], prices[i] - minPrice[i - 1]);
  }

  return maxProfit[n - 1];
}