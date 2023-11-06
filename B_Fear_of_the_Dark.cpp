#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef pair<int, int> Point;

double calculateDistance(Point p1, Point p2) {
    double dx = p2.first - p1.first;
    double dy = p2.second - p1.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int t;
    double ans;
    cin >> t;
    cout << fixed << setprecision(10);
    
    while (t--) {
        vector<Point> points(3);
        for (int i = 0; i < 3; i++) {
            cin >> points[i].first >> points[i].second;
        }
        Point origin = make_pair(0, 0);
        double PA = calculateDistance(points[0], points[1]);
        double PB = calculateDistance(points[0], points[2]);
        double OP = calculateDistance(points[0], origin);
        double AB = calculateDistance(points[1], points[2]);
        double OA = calculateDistance(points[1], origin);
        double OB = calculateDistance(points[2], origin);

        if (OA < OB) {
            if (PA < PB)
                ans = max(PA, OA);
            else
                ans = max(OA, max(PB, AB / 2));
        } else {
            if (PA > PB)
                ans = max(PA, PB);
            else
                ans = max(OB, max(PA, AB / 2));
        }
        
        cout << ans << endl;
    }

    return 0;
}
