#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += (1LL << i);
  }
  cout << ans << endl;
  return 0;
}