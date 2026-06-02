#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cntT = 0, cntF = 0;
        int leftT = -1, leftF = -1;
        int right = 0;
        int resT = 0, resF = 0;
        for (; right < answerKey.size(); ++right) {
            char c = answerKey[right];
            if (c == 'T' && cntT >= k) {
                while (leftT < right) {
                    ++leftT;
                    if (answerKey[leftT] == 'T') {
                        cntT -= 1;
                        break;
                    }
                }
            }
            if (c == 'F' && cntF >= k) {
                while (leftF < right) {
                    ++leftF;
                    if (answerKey[leftF] == 'F') {
                        cntF -= 1;
                        break;
                    }
                }
            }

            if (c == 'T') {
                cntT += 1;
            }
            if (c == 'F') {
                cntF += 1;
            }

            resT = max(resT, right - leftT);
            resF = max(resF, right - leftF);
        }

        return max(resT, resF);
    }
};