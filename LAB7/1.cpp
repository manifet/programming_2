#include <iostream>
#include <vector>
#include <algorithm>

struct Lecture {
    int start;
    int end;
};

bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.end < b.end;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Lecture> lectures(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> lectures[i].start >> lectures[i].end;
    }

    std::sort(lectures.begin(), lectures.end(), compareLectures);

    int count = 0;
    int lastEndTime = 0;

    for (const auto& lecture : lectures) {
        if (lecture.start >= lastEndTime) {
            ++count;
            lastEndTime = lecture.end;
        }
    }

    std::cout << count << std::endl;
    return 0;
}


// 3
// 1 4
// 2 3
// 3 5

// 2
