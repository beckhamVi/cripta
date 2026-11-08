#include "map.h"

Map::Map(int width, int height) : width_(width), height_(height), tiles_(height, std::string(width, '.')) {
	//border of wall
	for (int x = 0; x < width_; ++x) {
		tiles_[0][x] = '#';
		tiles_[height_ - 1][x] = '#';
	}
	
	for (int y = 0; y < height_; ++y) {
		tiles_[y][0] = '#';
		tiles_[y][width_ - 1] = '#';

	}

	//test wall
	for (int x = 8; x < 20; ++x) tiles_[6][x] = '#';
	for (int y = 0; y < 9; ++y) tiles_[y][30] = '#';
}

char Map::tileAt(int x, int y) const {
	if (x < 0 || y < 0 || x >= width_ || y >= height_) return '#';
	return tiles_[y][x];
}

bool Map::isWalkable(int x, int y) const {
	return tileAt(x, y) != '#';
}

