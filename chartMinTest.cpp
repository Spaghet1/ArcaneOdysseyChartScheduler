#include "Chart.hpp"
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
	vector<ChartSpot> charts;
	PointVector currPos(0.0, 0.0);
	mt19937 rng(random_device{}());
	uniform_real_distribution<double> uniform(-100.0, 100.0);
	for (int i = 0; i < 10; i++) {
		charts.emplace_back(COMMON, PointVector(uniform(rng), uniform(rng)));
	}
	ChartComparator cmp = {currPos};
	auto min_it = min_element(charts.begin(), charts.end(), cmp);
	while (min_it != charts.end()) {
		cout << (*min_it).location << " length: " << (*min_it).location.length() << endl;
		charts.erase(min_it);
		min_it = min_element(charts.begin(), charts.end(), cmp);
	}
}
