#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Phần a. Brute Force
int BruteForceCount(const vector<int>& a) {
    int count = 0;
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                count++;
            }
        }
    }
    return count;
}

// Phần b. Divide and Conquer
int MergeAndCount(vector<int>& aL, vector<int>& aR) {
    int count = 0;
    int i = 0, j = 0;
    while (i < aL.size() && j < aR.size()) {
        if (aL[i] > aR[j]) {
            count += aL.size() - i;
            j++;
        } else {
            i++;
        }
    }
    return count;
}

// Hàm chia mảng và đếm nghịch thế
pair<int, vector<int>> DivideAndCount(vector<int>& a) {
    // Nếu mảng chỉ có 1 phần tử, trả về 0 và mảng đó
    if (a.size() == 1) {
        return {0, a};
    }
    // Chia mảng làm hai phần
    int mid = a.size() / 2;
    vector<int> aL(a.begin(), a.begin() + mid);
    vector<int> aR(a.begin() + mid, a.end());
    
    // Gọi đệ quy cho hai mảng con
    auto start = high_resolution_clock::now();
    auto [nL, sorted_aL] = DivideAndCount(aL);
    auto [nR, sorted_aR] = DivideAndCount(aR);
    // Đếm số nghịch thế khi hợp nhất hai mảng
    int nLR = MergeAndCount(sorted_aL, sorted_aR);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Thời gian thực hiện DivideAndCount: " << duration.count() << " micro giây" << endl;

    // Hợp nhất hai mảng và trả về kết quả
    vector<int> merged(a.size());
    merge(sorted_aL.begin(), sorted_aL.end(), sorted_aR.begin(), sorted_aR.end(), merged.begin());
    return {nL + nR + nLR, merged};
}

int main() {
    vector<int> a = {1, 5, 4, 8, 10, 2, 6, 9, 12, 11, 3, 7};

    // Phần a. Sử dụng phương pháp Brute Force
    auto start_a = high_resolution_clock::now();
    int bruteForceResult = BruteForceCount(a);
    auto stop_a = high_resolution_clock::now();
    auto duration_a = duration_cast<microseconds>(stop_a - start_a);
    cout << "Kết quả sử dụng Brute Force: " << bruteForceResult << endl;
    cout << "Thời gian thực hiện BruteForceCount: " << duration_a.count() << " micro giây" << endl;

    // Phần b. Sử dụng phương pháp DivideAndCount
    auto start_b = high_resolution_clock::now();
    auto [divideAndConquerResult, _] = DivideAndCount(a);
    auto stop_b = high_resolution_clock::now();
    auto duration_b = duration_cast<microseconds>(stop_b - start_b);
    cout << "Kết quả sử dụng DivideAndCount: " << divideAndConquerResult << endl;
    cout << "Thời gian thực hiện DivideAndCount: " << duration_b.count() << " ms" << endl;

    return 0;
}
