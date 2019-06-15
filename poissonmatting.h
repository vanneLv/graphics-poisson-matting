#ifndef POISSONMATTING_H
#define POISSONMATTING_H

#include <QImage>
#include "opencv2/opencv.hpp"

class PoissonMatting
{
public:
    PoissonMatting();
    void matting(cv::InputArray _trimap, cv::OutputArray _foreground, cv::OutputArray _alpha);
    void matting(cv::InputArray _trimap, cv::OutputArray _alpha);
    void openFore(QString filename);
    void openBack(QString filename);
    cv::Mat &getImageMat();
    cv::Mat &getImageCutMat();
    void setImageCutMat(cv::InputArray _cutmat);
    cv::Mat &getbackMat();

protected:
    cv::Mat img;
    cv::Mat imgCut;
    cv::Mat background;
    static std::vector<cv::Point> findBoundaryPixels(const cv::Mat_<uchar> &trimap, int a, int b);
    void globalMatting(cv::Mat _image, cv::Mat _trimap, cv::Mat &_foreground, cv::Mat &_alpha);
    void localMatting(cv::Mat _image, cv::Mat _trimap, cv::Mat &_alpha);
    void checkImgTrimap(cv::InputArray _trimap);
};

#endif // POISSONMATTING_H
