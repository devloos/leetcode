class Solution {
 public:
  int strStr(string h, string n) {
    int l = 0;
    int r = 0;
    int i = 0;

    while (r < h.size()) {
      if (h[r] == n[i]) {
        ++r;
        ++i;
        if (i >= n.size()) {
          return l;
        }
      } else {
        i = 0;
        r = ++l;
      }
    }

    return -1;
  }
};
