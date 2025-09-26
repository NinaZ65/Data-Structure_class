#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> Merge(const vector<T> &v1, const vector<T> &v2) {
  vector<T> mer;
  int a = 0, b = 0;
  while (a < v1.size() && b < v2.size()) {
    if (v1[a] < v2[b]) {
      mer.push_back(v1[a++]);
    } else {
      mer.push_back(v2[b++]);
    }
  }
  while (a < v1.size())
    mer.push_back(v1[a++]);
  while (b < v2.size())
    mer.push_back(v2[b++]);
  return mer;
}

template <typename T> vector<T> MergeSort(vector<T> &v) {
  if (v.size() == 1)
    return v;
  int mid = v.size() / 2;
  vector<T> left(v.begin(), v.begin() + mid);
  vector<T> right(v.begin() + mid, v.end());
  return Merge(MergeSort(left), MergeSort(right));
}

template <typename T> auto ReadFile(istream &fin) {
  vector<T> v;
  T x;
  while (fin >> x) {
    v.push_back(x);
  }
  return v;
}

int main() {
  ifstream fin("data.txt");
  if (!fin) {
    cerr << "文件打不开！" << endl;
    return 1;
  }
  auto v = ReadFile<int>(fin);
  v = MergeSort(v);
  for (const auto &x : v)
    cout << x << " ";
  cout << '\n';
  return 0;
}