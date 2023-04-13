class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
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

  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    // for comp reasons
    for (int i = 0; i < intervals.size(); ++i) {
      if (intervals[i][0] >= newInterval[0]) {
        intervals.insert(intervals.begin() + i, newInterval);
        break;
      }
    }

    if (intervals.empty() || intervals[intervals.size() - 1][0] < newInterval[0]) {
      intervals.push_back(newInterval);
    }

    return merge(intervals);
  }
};