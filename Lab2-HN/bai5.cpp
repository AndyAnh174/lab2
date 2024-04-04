#include <iostream> 
#include <vector>   

using namespace std;

// Hàm kiểm tra xem mảng có đủ các số nguyên từ 0 đến n hay không
bool isComplete(const vector<int>& arr, int n) {
    int sum = 0;
    for (int num : arr) {
        sum += num; // Tính tổng của tất cả các phần tử trong mảng
    }
    int expected_sum = n * (n + 1) / 2; // Tính tổng mong đợi nếu mảng đầy đủ các số từ 0 đến n
    return sum == expected_sum; // So sánh tổng thực và tổng mong đợi, trả về true nếu bằng nhau, ngược lại trả về false
}

// Hàm chia để trị để tìm số bị thiếu
int findMissing(const vector<int>& arr, int start, int end) {
    if (start > end) return -1; // Nếu chỉ số bắt đầu lớn hơn chỉ số kết thúc, tức là không còn phần tử nào để xem xét

    int mid = (start + end) / 2; // Tìm chỉ số giữa của mảng

    // Kiểm tra nếu phần bên trái không đủ số nguyên từ 0 đến mid
    if (!isComplete(arr, mid)) {
        // Tiếp tục tìm số bị thiếu trong phần bên trái của mảng
        return findMissing(arr, start, mid - 1);
    } else {
        // Nếu phần bên trái đủ số nguyên từ 0 đến mid, số bị thiếu nằm trong phần bên phải
        // Tiếp tục tìm số bị thiếu trong phần bên phải của mảng
        return findMissing(arr, mid + 1, end);
    }
}

int main() {
    int n;
    cout << "Nhap kich thuoc mang (n = 2^k - 1): ";
    cin >> n;

    vector<int> arr(n); // Khai báo một vector để lưu trữ các phần tử của mảng

    cout << "Nhap cac phan tu cua mang (tru mot phan tu): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Nhập các phần tử của mảng từ người dùng
    }

    // Tìm số bị thiếu trong mảng
    int missing_number = findMissing(arr, 0, n - 1);

    cout << "So bi thieu trong mang la: " << missing_number << endl; // In ra màn hình số bị thiếu trong mảng

    return 0;
}
