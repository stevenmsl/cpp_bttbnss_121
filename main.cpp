#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol121;

/*
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
]
*/

tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{7, 1, 5, 3, 6, 4};
  return make_tuple(input, 5);
}

/*
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

tuple<vector<int>, int>
testFixture2()
{
  auto input = vector<int>{7, 6, 4, 3, 1};
  return make_tuple(input, 0);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.maxProfit(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.maxProfit(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}