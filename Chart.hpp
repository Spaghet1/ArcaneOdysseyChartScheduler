#include "PointVector.hpp"

enum CompassDirection {
	N,
	NNW,
	NW,
	WNW,
	W,
	WSW,
	SW,
	SSW,
	S,
	SSE,
	SE,
	ESE,
	E,
	ENE,
	NE,
	NNE
};

enum Height {
	SEA_LEVEL,
	SMALL_CLIFF,
	HIGH_CLIFF
};

enum Terrain {
	GROUND,
	SAND,
	SNOW
};

// probably have to change this later to make handling lost and mythical charts easier
enum Rarity {
	COMMON,
	UNCOMMON,
	RARE,
	MYSTIC,
	LEGENDARY
};

class ChartSpot {
public:
	Rarity rarity;
	PointVector location;
	CompassDirection dir;
	Height height;
	Terrain terrain;

	// testing constructor
	ChartSpot(Rarity rarity, PointVector location) : rarity(rarity), location(location), dir(N), height(SEA_LEVEL), terrain(GROUND) {};
};

struct ChartComparator {
	PointVector currPos;
	bool operator()(const ChartSpot& a, const ChartSpot& b) {
		double dist_a = (a.location - currPos).length();
		double dist_b = (b.location - currPos).length();
		if (dist_a == dist_b) return a.rarity < b.rarity;
		else return dist_a < dist_b;
	}
};
