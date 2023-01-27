// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int lft = 1, rht = n;
        long int mid = (lft + rht) / 2;
        do {
            if (isBadVersion(mid) == false)
                lft = mid + 1;
            else if (isBadVersion(mid) == true)
                rht = mid;
            mid = (lft + rht) / 2;
        }while (lft != rht);
        return mid;
    }
};
