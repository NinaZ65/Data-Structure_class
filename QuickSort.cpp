#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

template <typename T> auto ReadFile(istream &fin) {
  vector<T> v;
  T x;
  while (fin >> x) {
    v.push_back(x);
  }
  return v;
}

template <typename T> vector<T> Sort(vector<T> &v){
    T key = v.at(0);
    for(int i = 1; i < v.size(); i++){
        if(key > v.at(i)){
            rotate(v.begin(), v.begin() + i, v.begin() + i + 1);
        }
    }
    return v;
}

template <typename T> vector<T> QuickSort(const vector<T> &v) {
  if (v.size() == 1)
    return v;
  if (v.size() == 0)
    return v;
  T key = v[0];
  vector<T> left, right;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] < key)
      left.push_back(v[i]);
    else
      right.push_back(v[i]);
  }
  left = QuickSort(left);
  right= QuickSort(right);
    left.push_back(key);
  left.insert(left.end(), right.begin(), right.end());
  return left;
}

int main() {
  ifstream fin("data.txt");
  if (!fin) {
    cerr << "文件打不开！" << endl;
    return 1;
  }
  auto v = ReadFile<int>(fin);
  v = QuickSort(v);
  for (const auto &x : v)
    cout << x << " ";
  cout << '\n';
  return 0;
}