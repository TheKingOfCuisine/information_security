#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // Загрузка изображения
    Mat image = imread("1016.png", IMREAD_COLOR);

    // Извлечение скрытого сообщения
    string text;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            // Извлечение младшего бита из каждого канала RGB
            char c = 0;
            c |= (pixel[0] & 1) << 2;
            c |= (pixel[1] & 1) << 1;
            c |= (pixel[2] & 1);
            text.push_back(c);
        }
    }

    // Вывод скрытого сообщения
    cout << "Итог: " << text << endl;
	/*"\"0i$ 2-4u4<vL>\"2\"V0t]4v42vb4g4g4a47<t<* /f 
	discount department stores started by Sol Price, who later founded Price Club.
	His first location in San Diego, California was in a converted airport hangar. 
	It was originally a discount department store open to g"*/
    return 0;
}
