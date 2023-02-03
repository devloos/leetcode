class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    std::vector<int> res(n, 0);

    for (const auto &booking : bookings) {
      res[booking[0] - 1] += booking[2];
      if (booking[1] < n) {
        res[booking[1]] -= booking[2];
      }
    }

    for (int i = 1; i < res.size(); ++i) {
      res[i] += res[i - 1];
    }

    return res;
  }
};
