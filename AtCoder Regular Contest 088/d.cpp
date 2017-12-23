/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it:
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
Surely, just as we were that day... like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy...
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light;
Even if you never change... even if you happen to change... you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people;
At that time, I hope we can bring along our irreplaceable families and meet here again...

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light...
We run through the passing seasons, seeing each of our many tomorrows;
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N], n;
char s[N];

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

void add(int i, int v) {
  for (; i < N; i |= i + 1) bit[i] += v;
}

bool can(int d) {
  memset(bit, 0, sizeof(bit));
  for (int i = 1; i + d - 1 <= n; i++) {
    int now = (s[i] - '0' + find(i)) % 2;
    if (now) {
      add(i, 1);
    }
  }
  int ada = 0;
  for (int i = 1; i <= n; i++) {
    int now = (s[i] - '0' + find(i)) % 2;
    if (now) {
      break;
    } else {
      ada++;
    }
  }
  return ada >= d;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
