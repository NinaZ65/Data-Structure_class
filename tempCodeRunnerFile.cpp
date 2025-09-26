#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 随机数引擎和分布
    random_device rd;  // 真随机种子
    mt19937 gen(rd()); // 梅森旋转算法，性能好
    uniform_int_distribution<int> dist(-1000000, 1000000); 
    // 你可以改这里的范围

    ofstream fout("data.txt"); // 保存到文件
    if (!fout.is_open()) {
        cerr << "无法创建文件！" << endl;
        return 1;
    }

    const int N = 1000000;
    for (int i = 0; i < N; i++) {
        fout << dist(gen) << '\n';
    }

    fout.close();
    cout << "已生成 " << N << " 个随机整数，保存到 random_numbers.txt" << endl;

    return 0;
}
