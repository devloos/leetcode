class Solution
{
public:
  bool isStrictlyPalindromic(int n)
  {
    std::string bits;
    int base = n - 2;
    while (n / base != 0)
    {
      bits.append(std::to_string(n % base));
      n /= base;
    }
    bits.append(std::to_string(n % base));

    int left = 0;
    int right = bits.size() - 1;
    while (left < right)
    {
      if (bits[left] != bits[right])
      {
        return false;
      }

      ++left;
      --right;
    }

    return true;
  }
};