#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa một cấu trúc cho các điểm
struct Point {
    int x, y;
};

// Hàm để tìm điểm lớn nhất giữa hai điểm
Point maxPoint(const Point& p1, const Point& p2) {
    Point maxP;
    maxP.x = max(p1.x, p2.x);
    maxP.y = max(p1.y, p2.y);
    return maxP;
}

// Hàm để tìm điểm lớn nhất trong một vector các điểm bằng cách chia để trị
Point findMax(const vector<Point>& points, int left, int right) {
    // Trường hợp cơ bản: Nếu chỉ có một điểm
    if (left == right) {
        return points[left];
    }

    // Chia mảng thành hai nửa
    int mid = left + (right - left) / 2;

    // Tìm điểm lớn nhất đối với nửa trái và nửa phải mảng
    Point maxLeft = findMax(points, left, mid);
    Point maxRight = findMax(points, mid + 1, right);

    // Tìm điểm lớn nhất giữa hai điểm lớn nhất của hai nửa mảng
    return maxPoint(maxLeft, maxRight);
}

int main() {
    // Ví dụ sử dụng
    vector<Point> points = {{1, 2}, {5, 3}, {7, 8}, {4, 6}, {9, 1}};

    // Tìm điểm lớn nhất
    Point maxPoint = findMax(points, 0, points.size() - 1);

    // In ra điểm lớn nhất
    cout << "Điểm lớn nhất: (" << maxPoint.x << ", " << maxPoint.y << ")" << endl;

    return 0;
}
