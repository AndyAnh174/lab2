#include <iostream>
#include <vector>
using namespace std;

// Hàm thực hiện tìm kiếm nhị phân
int binarySearch(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Tính chỉ số của phần tử giữa
        if (arr[mid] == x)
            return mid; // Trả về chỉ số nếu tìm thấy x
        else if (arr[mid] < x)
            left = mid + 1; // Di chuyển left sang phải của mid
        else
            right = mid - 1; // Di chuyển right sang trái của mid
    }
    return -1; // Trả về -1 nếu không tìm thấy x
}

// Hàm tìm vị trí của một phần tử trong mảng vô hạn đã được sắp xếp
int findInInfiniteArray(const vector<int>& arr, int x) {
    int left = 0, right = 1;
    while (arr[right] < x) { // Tìm phạm vi chứa x
        left = right;
        right *= 2; // Gấp đôi phạm vi tìm kiếm
    }
    return binarySearch(arr, left, right, x); // Gọi hàm binarySearch để tìm vị trí của x trong phạm vi từ left đến right
}

int main() {
    // Khởi tạo mảng vô hạn đã được sắp xếp
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, /* và cứ tiếp tục như vậy */};
    int x = 11; // Phần tử cần tìm

    // Gọi hàm findInInfiniteArray để tìm vị trí của x trong mảng và in ra kết quả
    int index = findInInfiniteArray(arr, x);
    if (index != -1)
        cout << "Tìm thấy tại chỉ số: " << index << endl;
    else
        cout << "Không tìm thấy" << endl;

    return 0;
}
