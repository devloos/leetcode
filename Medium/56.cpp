class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res;

    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (end < intervals[i][0]) {
        res.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      } else {
        if (end < intervals[i][1]) {
          end = intervals[i][1];
        }
      }
    }

    res.push_back({start, end});

    return res;
  }
};

// [1, 6], [2, 3], [4, 5], [6, 10]
// [1, 3], [2, 6], [8, 10], [15, 18]
// [1, 3], [2, 6], [8, 10], [15, 18]