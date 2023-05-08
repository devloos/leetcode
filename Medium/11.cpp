class Solution {
 public:
  int maxArea(vector<int> &height) {
    int mav = 0;
    int left = 0;
    int right = height.size() - 1;
    for (int i = 0; i < height.size(); ++i) {
      int dis = right - left;
      int smaller = (height[left] > height[right]) ? right-- : left++;
      mav = max(mav, height[smaller] * dis);
    }
    return mav;
  }
};
