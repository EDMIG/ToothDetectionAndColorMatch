#include "ToothProcess.h"

int main()
{
	//读取色标局部图像
	IplImage* imageCode = cvLoadImage("E:\\牙齿检测\\四期开发\\开口器\\1020_3C.jpg",1);

	//读取牙齿局部图像
	IplImage* imageToothROI = cvLoadImage( "E:\\牙齿检测\\四期开发\\开口器\\1020_3T.jpg", 1 );

	//调用牙齿检测与颜色匹配函数
	//匹配结果索引返回值(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)->色标美白标尺(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)表示检测成功；
	//为-1时表示检测失败，需重新拍照
	int matchIndex = ToothColorMatch(imageCode,imageToothROI);
	printf("匹配结果索引值 = %d\n\n",matchIndex);
	printf("备注：匹配结果索引返回值(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)->色标美白标尺(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)表示检测成功；\n为-1时表示检测失败，需重新拍照\n");

	cvShowImage("code",imageCode);
	cvShowImage("tooth",imageToothROI);

	cvWaitKey(0);
	return 0;
}
