#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm fixed point trong mảng đã cho
int find_fixed_point(vector<int>& arr) {
    int left = 0; // Chỉ số bắt đầu của mảng
    int right = arr.size() - 1; // Chỉ số kết thúc của mảng

    // Duyệt mảng với phương pháp tìm kiếm nhị phân
    while (left <= right) {
        int mid = left + (right - left) / 2; // Tính chỉ số giữa

        if (arr[mid] == mid) { // Nếu arr[mid] == mid, ta đã tìm thấy fixed point
            return mid; // Trả về chỉ số mid
        } else if (arr[mid] < mid) { // Nếu arr[mid] < mid, fixed point nằm bên phải mid
            left = mid + 1; // Di chuyển left đến mid + 1
        } else { // Nếu arr[mid] > mid, fixed point nằm bên trái mid
            right = mid - 1; // Di chuyển right đến mid - 1
        }
    }

    return -1; // Không tìm thấy fixed point, trả về -1
}

int main() {
    vector<int> arr = {-10, -5, 0, 3, 7, 9, 12, 15}; // Ví dụ mảng đã sắp xếp
    int result = find_fixed_point(arr); // Gọi hàm tìm fixed point

    // In kết quả tìm được
    if (result != -1) {
        cout << "Chỉ số i là: " << result << endl; // In ra chỉ số i nếu tìm thấy
    } else {
        cout << "Không có fixed point trong mảng đã cho." << endl; // Thông báo không tìm thấy fixed point nếu trả về -1
    }

    return 0;
}