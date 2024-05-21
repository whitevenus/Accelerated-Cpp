#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ios>
#include <iomanip>

using std::cout;    using std::cin;
using std::endl;    using std::vector;
using std::string;  using std::streamsize;
using std::setprecision;

int main() {
    int n, homework_count;
    vector<string> names;
    vector<double> total_scores;

    // 读取学生数量和家庭作业数量
    cout << "请输入学生数量：";
    cin >> n;
    cout << "请输入家庭作业的数量：";
    cin >> homework_count;

    // 读取学生姓名和成绩
    for (int i = 0; i < n; ++i) {
        string name;
        cout << "请输入第 " << i + 1 << " 名学生的姓名：";
        cin >> name;
        names.push_back(name);

        cout << "请输入 " << name << " 的期中和期末成绩: ";
        double midterm, final;
        cin >> midterm >> final;
        cout << "输入" << homework_count << "个家庭作业成绩：";

        vector<double> homework;
        double x;
        for (int j = 0; j < homework_count; ++j) {
            cin >> x;
            homework.push_back(x);
        }

        typedef vector<double>::size_type vec_sz;

        vec_sz size = homework.size();
        if (size == 0) {
          cout << endl << "你必须输入你的成绩，请重新尝试." << endl;
          return 1;
        }

        sort(homework.begin(), homework.end());

        vec_sz mid = size / 2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

        double total = 0.2 * midterm + 0.4 * final + 0.4 * median;
        total_scores.push_back(total);
    }

    // 打印学生姓名和总成绩
    cout << "\n学生姓名和总成绩：" << endl;
    streamsize pre = cout.precision();
    for (int i = 0; i < n; ++i) {
        cout << names[i] << ": " << setprecision(3)
        << total_scores[i] << setprecision(pre) << endl;
    }
    return 0;
}
