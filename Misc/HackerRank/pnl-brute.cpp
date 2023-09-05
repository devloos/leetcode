for (int i = 0; i < pnl.size(); ++i) {
  long sum = 0;
  for (int j = i; j < k + i && j < pnl.size(); ++j) {
    sum += pnl[j];
    mav = std::max(mav, sum);
  }
}