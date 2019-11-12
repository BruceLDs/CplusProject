#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int W, H;
	cin >> W >> H;
	int x = 0;
	int y = 0;
	int count = 0;
	while (x < W){
		y = 0;
		while (y < H){
			if (x + 1 < W && y + 1 < H)
				count += 4;
			else if (x + 1 > W && y + 1 < H)
				count += 2;
			else if (x + 1 < W && y + 1 > H)
				count += 2;
			y += 4;
		}
		x += 4;
	}
	if (x - 2 < W && y - 2 < H)
		count++;
	else if (x - 1 < W && y - 1 < H)
		count += 4;
	cout << count;
	return 0;
}