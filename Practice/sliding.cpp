#include <iostream>
using namespace std;
int characterReplacement(string s, int k) {
  int maxValue = 0, count = 0;
  int left = 0, right = 0;
  int mp[26] = { 0 };
  while(right < s.size()) {
    mp[s[right] - 'A']++;
    count++;
    count = max(count, mp[s[right] - 'A']);

    // where out of range:
    if((right - left + 1) - count > k) {
      mp[s[left] - 'A']--;
      count = 0;
      left++;
    }

    if((right - left + 1) - count <= k) {
      maxValue = max(count, maxValue);
    }
    right++;
  }
  return maxValue;
}
int main() {
    string s="AABABBA";
  int ssize=s.size();
  int k=1;
  string s1 = "ABAB";
  int k1 = 2;
  return 0;
  cout << characterReplacement(s, k) << endl;
  cout << characterReplacement(s1, k1) << endl;
}