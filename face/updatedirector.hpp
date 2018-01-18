//
//  updatedirector.hpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#ifndef updatedirector_hpp
#define updatedirector_hpp

#include <iostream>
#include <vector>
#include "faceposition.hpp"
#include "shapes.hpp"

#include <SFML/Graphics.hpp>

class Updater
{
public:
    int Update ( sf::Image *iFrame );
    std::vector<sf::CircleShape> c_Shapes;
private:
    Detector *m_Detector = new Detector ( );
    Shapes *m_Shapes = new Shapes ( );
    
    int iAverageHeadSizes[10];
    int iAverageHeadPosX[10];
    int iAverageHeadPosY[10];
    
    int iAverageFirstEyePosX[10];
    int iAverageFirstEyePosY[10];
    int iAverageSecondEyePosX[10];
    int iAverageSecondEyePosY[10];
    
    int iCurrentIndex = 0;
};

#endif /* updatedirector_hpp */
