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
  - you need to know the min price and max profit up to the
    day before.
    - since there will be no profit if you buy and sell on the same
      day so maxProfit[0] = 0
    - you can see if you sell the share today, will it increase
      the profit
  - can't use brute price as its time complexity will be O(n^2)
  - use DP
    - update or carry over the min price and the max profit
      for each day
    - return the max profit
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

    /* the profit has been set to 0 initially
       - if you buy and sell a share on the same day the
         profit will be 0 anyway and will not change the
         max profit
       - look at the min price up until the day before
         - calculate if we can generate a better profit
           if we see the share today
    */
    maxProfit[i] = max(maxProfit[i - 1], prices[i] - minPrice[i - 1]);
    /* carry over or update the min price */
    minPrice[i] = min(minPrice[i - 1], prices[i]);
  }

  return maxProfit[n - 1];
}