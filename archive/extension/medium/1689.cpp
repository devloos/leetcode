class Solution {
 public:
  // 48 49
  int minPartitions(string n) {
    int count = 0;
    int size = 0;
    while (size != n.size()) {
      size = 0;
      for (int i = 0; i < n.size(); ++i) {
        if (n[i] > 48) {
          n[i] -= 1;
        }

        if (n[i] <= 48) {
          ++size;
        }
      }

      ++count;
    }

    return count;
  }
};

class Solution {
 public:
  // 48 49
  int minPartitions(string n) {
    int m = 0;
    for (const auto &el : n) {
      int digit = el - 48;
      m = max(m, digit);
    }

    return m;
  }
};
