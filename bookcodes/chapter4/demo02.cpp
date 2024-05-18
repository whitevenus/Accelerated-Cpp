#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cout; using std::cin;
using std::string; using std::endl;
using std::setprecision; using std::streamsize;
using std::vector; using std::domain_error;
using std::sort;
using std::istream;

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  if (size == 0) 
    throw domain_error("median of an empty vector.");
  
  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0)
    throw domain_error("student has done'no homework.");
  return grade(midterm, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw)
{
  if(in) {
    // 清除原先的内容
    hw.clear();

    // 读家庭作业成绩
    double x;
    while(in >> x) {
      hw.push_back(x);
    }

    // 清除流以使输入动作对下一个学生有效
    in.clear();
  }
  return in;
}

int main() 
{
  // 请求并读入学生姓名
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // 请求并读入期中和期末考试成绩 
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // 请求用户输入家庭作业成绩
  cout << "Enter all your homework grades, "
          "followed by end-of-file: ";
  
  vector<double> homework;

  // 读入家庭作业成绩
  read_hw(cin, homework);

  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << final_grade << setprecision(prec) << endl;
  } catch (domain_error) {
    cout << endl << "You must enter your grades. "
         << "Please try again." << endl;
    return 1;
  }
  return 0;
}
