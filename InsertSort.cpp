#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> void InsertSort(vector<T> &v) {
  T key;
  int i;
  for (int j = 1; j < v.size(); j++) {
    key = v.at(j);
    i = j - 1;
    while (i >= 0 && v.at(i) > key) {
      v[i + 1] = v[i];
      i--;
    }
    v[i + 1] = key;
  }
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
  InsertSort(v);
  for (const auto &x : v)
    cout << x << " ";
  cout << '\n';
  return 0;
}