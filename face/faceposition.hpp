//
//  faceposition.hpp
//  face
//
//  Created by Zoe IAMZOE.io on 1/17/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#ifndef faceposition_hpp
#define faceposition_hpp

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Detector
{
public:
    Detector ( );
    int Update ( );
    int detectAndDraw ( cv::Mat& img, cv::CascadeClassifier& cascade, cv::CascadeClassifier& nestedCascade, cv::CascadeClassifier& nestedSmileCascade, double scale );
    
    double dEyeOneWidth;
    double dEyeOneHeight;
    double dEyeTwoWidth;
    double dEyeTwoHeight;
    double dHeadWidth;
    double dHeadHeight;
    double dSmileWidth;
    double dSmileHeight;
    
    std::pair<int, int> pHeadPossition;
    std::pair<int, int> pSmilePossition;
    std::pair<int, int> pEyeOnePosition;
    std::pair<int, int> pEyeTwoPosition;
private:
    cv::VideoCapture vCapture;
    cv::Mat mFrame;
    cv::Mat mImage;
    cv::CascadeClassifier cCascade;
    cv::CascadeClassifier cNestedCascade;
    cv::CascadeClassifier cNestedCascadeSmile;

    std::string sEyeXML = "/Users/zoe/Developer/CPP/face/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
    std::string sFaceXML = "/Users/zoe/Developer/CPP/face/haarcascades/haarcascade_frontalcatface.xml";
    std::string sSmileXML = "/Users/zoe/Developer/CPP/face/haarcascades/haarcascade_smile.xml";
    std::string cascadeName;
    std::string nestedCascadeName;
    
    double const OFFSET = 0.5;
};

#endif /* faceposition_hpp */
