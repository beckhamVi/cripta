#pragma once
#include <string>
#include <vector>

class Map {
public: 
	Map(int width, int height);
	
	int width() const { return width_; }
	int height() const { return height_; }
	char tileAt(int x, int y) const;
	bool isWalkable(int x, int y) const;

private:
	int width_;
	int height_;
	std::vector<std::string> tiles_;
};
