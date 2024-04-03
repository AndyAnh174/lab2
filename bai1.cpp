#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> removeDuplicates(vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> newArr;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            newArr.push_back(num);
            seen.insert(num);
        }
    }

    return newArr;
}

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();

    vector<int> result = removeDuplicates(arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    cout << duration.count() << " ms" << endl;

    return 0;
}



/* Function removeDuplicates(arr):
    // Khởi tạo một unordered_set để lưu trữ các phần tử đã xuất hiện
    seen = unordered_set<int>()
    // Khởi tạo một vector mới để lưu trữ các phần tử duy nhất
    newArr = vector<int>()
    
    // Duyệt qua mảng
    For each num in arr:
        // Nếu num chưa xuất hiện trước đó
        If num không nằm trong seen:
            // Thêm num vào vector mới và vào set seen
            Push num vào newArr
            Thêm num vào seen
    
    Return newArr
 */