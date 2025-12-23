#include <iostream>

using ll = long long;

// frequency map
// std::unordered_map<long long,int> cnt;
// for (auto x: a) cnt[x]++;
//
// prefix sum
// std::vector<long long> pref(n+1,0);
// for(int i=0;i<n;i++) pref[i+1]=pref[i]+a[i];
// auto sum = [&](int l,int r){ return pref[r]-pref[l]; };
//
// binary search skeleton
// auto ok = [&](long long x)->bool{
//  // check feasibility
//  return true;
// };
// long long lo=0, hi=1e18;
// while(lo<hi){
// long long mid=(lo+hi)/2;
// if(ok(mid)) hi=mid; else lo=mid+1;
// }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (auto& x : a) std::cin >> x;

    // solve here
    // std::cout << ans << std::endl;
  }
  return 0;
}
