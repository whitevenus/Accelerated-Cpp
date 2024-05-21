#include <iostream>
#include <vector>
#include <algorithm> // 用于sort函数

using std::vector;    using std::cout;
using std::cin;       using std::endl;


int main() {
    vector<int> numbers;
    int n, temp;

    // 读取整数集合
    cout << "请输入整数集合的元素数量：";
    cin >> n;
    cout << "请输入整数集合的元素，每个元素后跟一个空格或回车：" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        numbers.push_back(temp);
    }

    // 检查元素数量是否可以被4整除
    if (n % 4 != 0) {
        cout << "元素数量必须能被4整除。" << endl;
        return 1;
    }

    // 对整数集合进行排序
    sort(numbers.begin(), numbers.end());

    // 计算每个部分的元素数量
    int part_size = n / 4;

    // 打印四个部分
    cout << endl << "第一部分（最大值）：" << endl;
    for (int i = n - 1; i >= n - part_size; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "第二部分：" << endl;
    for (int i = 3 * part_size - 1; i >= 2 * part_size; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "第三部分：" << endl;
    for (int i = 2 * part_size - 1; i >= part_size; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "第四部分（最小值）：" << endl;
    for (int i = part_size - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
