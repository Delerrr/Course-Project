#pragma once
#include <string>
#include <cmath>
using namespace std;
/*
* 定义一些工具性质的结构和函数
*/
/// <summary>
/// 一个简单的二维坐标结构
/// </summary>
class Point2 {
public:
	double x;
	double y;
	Point2() {
		x = 0;
		y = 0;
	}
	Point2(double _x, double _y) : x(_x), y(_y) {}
	Point2(const Point2& other) { x = other.x; y = other.y; }
	double Dis(Point2& other) {
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}
};

/// <summary>
/// 基站
/// </summary>
struct Station {
	// 坐标
	Point2 coordinate;
	// 城区/乡镇/高速
	string stationType;
	// 信号功率强度
	double signalStrength;
	// 编号
	int index;
	Station(const Station& other) {
		coordinate = other.coordinate;
		stationType = other.stationType;
		signalStrength = other.signalStrength;
		index = other.index;
	}
	Station() {
		index = 0;
	}
};


/// <summary>
/// 判断点point是否在leftBottom和rightTop组成的区域里
/// </summary>
/// <param name="point">需要判断的点的坐标</param>
/// <param name="leftBottom">区域左下角坐标</param>
/// <param name="rightTop">区域右上角坐标</param>
bool IsInRegion(Point2 point, Point2 leftBottom, Point2 rightTop, int index);

/// <summary>
/// 判断两个矩形区域是否重叠
/// </summary>
/// <param name="leftBottom1"></param>
/// <param name="rightTop1"></param>
/// <param name="leftBottom2"></param>
/// <param name="rightTop2"></param>
/// <returns></returns>
bool IsOverlapped(Point2 leftBottom1, Point2 rightTop1, Point2 leftBottom2, Point2 rightTop2);
