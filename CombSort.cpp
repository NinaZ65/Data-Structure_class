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

template <typename T>
vector<T> InsertSort(vector<T> v){
    T key;
    int i;
    for(int j = 1;j < v.size();j++){
        key = v.at(j);
        i = j-1;
        while(i >= 0 && v.at(i) > key){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
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

template <typename T> vector<T> QuickSort(const vector<T> &v,int k) {
  if (v.size() == 1)
    return v;
  if (v.size() == 0)
    return v;
  if(v.size() <= k)
   return InsertSort(v);
  T key = v[0];
  vector<T> left, right;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] < key)
      left.push_back(v[i]);
    else
      right.push_back(v[i]);
  }
  left = QuickSort(left,k);
  right= QuickSort(right,k);
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
  int k = 37; //change k value here!
  auto v = ReadFile<int>(fin);
  v = QuickSort(v,k);
  /*for (const auto &x : v)
    cout << x << " ";
  cout << '\n';
  */
  cout << k;
  return 0;
}