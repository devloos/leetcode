std::vector<std::vector<long>> p(pnl.size(), std::vector<long>(k, 0));
long mav = LONG_MIN;
for (int i = 0; i < p.size(); ++i) {
  p[i][0] = pnl[i];
  mav = std::max(mav, p[i][0]);
  for (int j = 1; j < k; ++j) {
    if (i + j >= pnl.size()) break;
    p[i][j] = pnl[i + j];
    p[i][j] = (p[i][j] + p[i][j - 1]) % (long)(1e9 + 7);
    mav = std::max(mav, p[i][j]);
  }
}