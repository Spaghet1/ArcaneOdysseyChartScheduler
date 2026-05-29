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
};
