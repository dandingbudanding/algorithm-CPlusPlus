#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Bbox
{
	int x;
	int y;
	int w;
	int h;
	float score;

}Bbox;

bool sort_score(Bbox box1, Bbox box2)
{
	return (box1.score > box2.score);

}

float iou(Bbox box1, Bbox box2)
{
	int x1 = std::max(box1.x, box2.x);
	int y1 = std::max(box1.y, box2.y);
	int x2 = std::min((box1.x + box1.w), (box2.x + box2.w));
	int y2 = std::min((box1.y + box1.h), (box2.y + box2.h));
	float over_area = (x2 - x1) * (y2 - y1);
	float iou = over_area / (box1.w * box1.h + box2.w * box2.h - over_area);
	return iou;
}

vector<Bbox> nms(std::vector<Bbox>&vec_boxs, float threshold)
{
	vector<Bbox>results;
	while (vec_boxs.size() > 0)
	{
		std::sort(vec_boxs.begin(), vec_boxs.end(), sort_score);
		results.push_back(vec_boxs[0]);
		for (int i = 0; i <vec_boxs.size() - 1; i++)
		{
			float iou_value = iou(vec_boxs[0], vec_boxs[i + 1]);
			if (iou_value >threshold)
			{
				vec_boxs.erase(vec_boxs.begin()+i + 1);
			}
		}
		vec_boxs.erase(vec_boxs.begin());

	}
}

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
typedef struct Bbox{
	int x;
	int y;
	int w;
	int h;
	float score;

}bbox;

float Iou(bbox box1,bbox box2)
{
	int x1 = MAX(box1.x, box2.x);
	int y1 = MAX(box1.y, box2.y);
	int x2=MIN(box1.x+box1.w, box2.x+box2.w);
	int y2=MIN(box1.y + box1.h, box2.y + box2.h);

	int repeat_area = (x2 - x1)*(y2 - y1);
	float iou = repeat_area / (box1.w*box1.h + box2.w*box2.h - repeat_area);
	return iou;

}

vector<bbox> NMS(vector<bbox>& box_array,float thre)
{
	
}