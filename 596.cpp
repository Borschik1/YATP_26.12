#include <iostream>
#include <string>
#include <map>
using namespace std;


struct Tower {
	string name;
	int x;
	int y;
	int radius;
};


int main() {
	int n;
	cin >> n;
	Tower* arr = new Tower[n];
	map <string, int> answer;
	for (int i = 0; i < n; ++i) {
		Tower now;
		string name;
		int x, y, radius;
		cin >> name;
		cin >> x >> y >> radius;
		now.name = name;
		now.x = x;
		now.y = y;
		now.radius = radius;
		arr[i] = now;
		answer[name] = 0;
	}
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < n; ++i) {
		if ((x - arr[i].x) * (x - arr[i].x) + (y - arr[i].y) * (y - arr[i].y) <= arr[i].radius * arr[i].radius) {
			answer[arr[i].name]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (answer[arr[i].name] != -1) {
			cout << arr[i].name << " " << answer[arr[i].name] << endl;
			answer[arr[i].name] = -1;
		}
	}
	return 0;
}
