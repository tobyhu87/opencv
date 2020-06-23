// DetectFaceTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char* argv[], char* envp[])
{
    if (argc != 3)
    {
        std::cout << "Please specify the original image and output image path.\n";
        return 1;
    }

    std::string sourceImage = argv[1];
    std::string outputImage = argv[2];

    Mat image = imread(sourceImage);

    std::cout << "Image used:" + sourceImage + "\n";

    Mat faces = Mat(image.rows, image.cols, CV_8UC4);
    cvtColor(image, faces, COLOR_BGR2BGRA);
    // imshow("Image Loaded", groupFaces);

    CascadeClassifier face_cascade;

    face_cascade.load("haarcascade_frontalface_alt.xml");

    std::vector<cv::Rect> facesColl;
    cv::Mat frame_gray;

    cvtColor(faces, frame_gray, COLOR_BGR2GRAY);
    cv::equalizeHist(frame_gray, frame_gray);

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, facesColl, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(1, 1));
    for (unsigned int i = 0; i < facesColl.size(); i++)
    {
        auto face = facesColl[i];
        // yellow 0, 255, 255
        // purple
        cv::rectangle(faces, face, cv::Scalar(255, 255, 0), 5);
    }

    if (facesColl.size() > 0)
    {
        std::cout << "Detected faces in: " + outputImage + "\n";
        imwrite(outputImage, faces);
    }
    else
    {
        std::cout << "No face detected.\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
