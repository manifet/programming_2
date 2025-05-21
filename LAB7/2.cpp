#include <iostream>
#include <vector>
#include <algorithm>

struct Box {
    int weight;
    int capacity;
};

bool compareBoxes(const Box& a, const Box& b) {
    return a.capacity > b.capacity;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Box> boxes(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> boxes[i].weight >> boxes[i].capacity;
    }

    std::sort(boxes.begin(), boxes.end(), compareBoxes);

    int maxBoxes = 0;
    int currentWeight = 0;

    for (const auto& box : boxes) {
        if (currentWeight <= box.capacity) {
            currentWeight += box.weight;
            maxBoxes++;
        }
    }

    std::cout << maxBoxes << std::endl;

    return 0;
}


// 5
// 3 10
// 2 5
// 1 8
// 4 12
// 2 7

// 4

