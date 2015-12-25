#include <iostream>
#include <vector>

struct Color {
	int red;
	int green;
	int blue;
};

class PpmImage
{
	int width, height, colorMax;
	std::vector<std::vector<Color>> data;

public:
	PpmImage(int w, int h, int colorMax)
		: data(h)
	{
		this->width = w;
		this->height = h;
		this->colorMax = colorMax;

		for (int j = 0; j < this->height; j++) {
			for (int i = 0; i < this->width; i++) {
				data[j].push_back({ 0, 0, 0 });
			}
		}
	}

	void setPixel(int x, int y, Color c) { data[y][x] = c; }

	Color getPixel(int x, int y) { return data[y][x]; }

	void drawRect(int x, int y, int w, int h, Color c)
	{
		for (int j = y; j < y + h; j++) {
			for (int i = x; i < x + h; i++) {
				std::cout << "i=" << i << " j=" << j << std::endl;
				setPixel(i, j, c);
			}
		}
	}

	void print()
	{
		std::cout << "P3" << std::endl
                  << width << " " << height << std::endl
                  << colorMax << std::endl;
		for (std::vector<Color> subVec : data) {
			for (Color e : subVec) {
				std::cout << e.red << " " << e.green << " " << e.blue << "\t\t";
			}
			std::cout << std::endl;
		}
	}
};

int main(void)
{
	int width, height;
	std::cin >> width >> height;

	PpmImage i{ width, height, 255 };

	std::string cmd;
	do {
		std::cin >> cmd;

		int r, g, b;
		if (cmd.compare("point") == 0) {
			int y, x;
			std::cin >> r >> g >> b >> y >> x;
			i.setPixel(x, y, { r, g, b });
		} else if (cmd.compare("line") == 0) {
		} else if (cmd.compare("rect") == 0) {
			int startx, starty, rectWidth, rectHeight;
			std::cin >> r >> g >> b >> starty >> startx >> rectHeight >> rectWidth;
			i.drawRect(startx, starty, rectWidth, rectHeight, { r, g, b });
		}
	} while (std::cin.good());

	i.print();

	return 0;
}
