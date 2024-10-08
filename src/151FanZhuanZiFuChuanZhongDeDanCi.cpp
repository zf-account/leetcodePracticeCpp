/* 解题思路如下：
    1.移除多余空格
    2.将整个字符串反转
    3.将每个单词反转
*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void reverse(string &s, int begin, int end)
    { // 翻转，区间写法：左闭右闭 []
        while (begin < end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
    void removeExtraSpaces(string &s)
    {                           // 去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0, fast = 0; // 整体思想参考https://programmercarl.com/0027.移除元素.html
        for (fast = 0; fast < s.size(); ++fast)
        {
            if (s[fast] != ' ')
            { // 遇到非空格就处理，即删除所有空格。
                if (slow != 0)
                    s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (fast < s.size() && s[fast] != ' ')
                { // 补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow); // slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s)
    {
        removeExtraSpaces(s); // 去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; // removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i)
        {
            if (i == s.size() || s[i] == ' ')
            {                             // 到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); // 翻转，注意是左闭右闭 []的翻转。
                start = i + 1;            // 更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "the sky is blue";
    Solution sol;
    cout << sol.reverseWords(s) << endl;
    return 0;
}
