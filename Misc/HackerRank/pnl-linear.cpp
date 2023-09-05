std::map<int, int> map;
std::vector<int> p(pnl);
map[p[0]] = 0;
for (int i = 1; i < p.size(); ++i) {
  p[i] += p[i - 1];
  map[p[i]] = i;
}

for (int i = 0; i < p.size(); ++i) {
  int key = map.rbegin()->first;
  int j = map.rbegin()->second;
  if (j >= k) {
    map.erase(key);
    key -= p[j - k];
    map[key] = j;
  }

  if (key >= map.rbegin()->first) {
    break;
  }
}

long sum = 0;
for (int j = 0; j < k && j >= 0; ++j) {
  int i = map.rbegin()->second;
  sum += pnl[i - j];
  mav = std::max(mav, sum);
}