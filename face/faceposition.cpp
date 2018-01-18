//
//  faceposition.cpp
//  face
//
//  Created by Zoe IAMZOE.io on 1/17/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include "faceposition.hpp"

Detector::Detector ( )
{
    cNestedCascade.load( sEyeXML );
    cNestedCascadeSmile.load( sSmileXML );
    cCascade.load( sFaceXML );

    vCapture.open(0); //0 = webcam
    
    if ( vCapture.isOpened ( ) )
        return;
    
    throw std::runtime_error ( "Could not connecto to camera!" );
}

int Detector::Update ( )
{
    vCapture >> mFrame;
    if ( mFrame.empty( ) )
        return 0;
    
    cv::Mat mFrameTMP = mFrame.clone ( );
    
    if ( detectAndDraw(mFrameTMP, cCascade, cNestedCascade, cNestedCascadeSmile, 1.0) != 1 )
        return 0;
    return 1;
}

int Detector::detectAndDraw( cv::Mat& img, cv::CascadeClassifier& cascade, cv::CascadeClassifier& nestedCascade, cv::CascadeClassifier& nestedSmileCascade, double scale )
{
    std::vector<cv::Rect> vrFaces;
    std::vector<cv::Rect> vrEyes;
    std::vector<cv::Rect> vrSmiles;
    cv::Mat gray;
    cv::Mat smallImg;
    
    cvtColor( img, gray, cv::COLOR_BGR2GRAY ); // Convert to Gray Scale
    double fx = 1 / scale;
    
    // Resize the Grayscale Image
    resize( gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR );
    equalizeHist( smallImg, smallImg );
    
    // Detect faces of different sizes using cascade classifier
    cascade.detectMultiScale( smallImg, vrFaces, 1.1, 3, 0, cv::Size( 20, 20 ) );
    
    if (vrFaces.size() < 1)
        return 0;
    
    cv::Rect rFace = vrFaces[0];
    nestedSmileCascade.detectMultiScale( smallImg( rFace ), vrSmiles, 3.0, 2, 0, cv::Size( 30, 30 ) );
    nestedCascade.detectMultiScale( smallImg( rFace ), vrEyes, 3.0, 2, 0, cv::Size( 30, 30 ) );
    
    if ( vrEyes.size() > 1 )
    {
        dEyeOneWidth = vrEyes[0].width/2;
        dEyeOneHeight = vrEyes[0].height;
        pEyeOnePosition.first = (rFace.x/2) + vrEyes[0].x + (vrEyes[0].width * OFFSET);
        pEyeOnePosition.second = rFace.y + vrEyes[0].y + (vrEyes[0].height * OFFSET);
        
        dEyeTwoWidth = vrEyes[1].width/2;
        dEyeTwoHeight = vrEyes[1].height;
        pEyeTwoPosition.first = 1.5 * (rFace.x/2) + vrEyes[1].x + (vrEyes[1].width * OFFSET);
        pEyeTwoPosition.second = rFace.y + vrEyes[1].y + (vrEyes[1].height * OFFSET);
    }
    
    if (vrSmiles.size() > 0)
    {
        cv::Rect rSmile = vrSmiles[0];

        dSmileWidth = rSmile.width * 2;
        dSmileHeight = rSmile.height;
        pSmilePossition.first = rFace.x - (rSmile.width / 2);
        pSmilePossition.second = 2 * (rFace.y + rSmile.y + (rSmile.height * OFFSET));
    }
    else
    {
        dSmileHeight = 0;
        dSmileWidth = 0;
    }
    
    dHeadWidth = rFace.width * 2;
    dHeadHeight = rFace.height;
    pHeadPossition.first = rFace.x / 2;
    pHeadPossition.second = rFace.y;
    
    return 1;
}
