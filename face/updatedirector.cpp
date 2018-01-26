//
//  updatedirector.cpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include "updatedirector.hpp"

void logXYP ( int x, int y, int p )
{
    std::cout << "X: " << x << " Y: " << y << " S: " << p << "\n";
}

int iGetAverage ( int arr[10] )
{
    int iTotal = 0;
    for ( int i = 0; i < 10; i++ )
        iTotal += arr[i];
    
    return iTotal/10;
}

int Updater::Update( sf::Image *iFrame )
{
    try
    {
        if ( m_Detector->Update ( ) != 1 )
            return 0;
        
        iAverageHeadSizes[iCurrentIndex] = m_Detector->dHeadHeight;
        iAverageHeadPosX[iCurrentIndex] = m_Detector->pHeadPossition.first;
        iAverageHeadPosY[iCurrentIndex] = m_Detector->pHeadPossition.second;
        
        iAverageSecondEyePosX[iCurrentIndex] = m_Detector->pEyeOnePosition.first;
        iAverageSecondEyePosY[iCurrentIndex] = m_Detector->pEyeOnePosition.second;
        
        iAverageFirstEyePosX[iCurrentIndex] = m_Detector->pEyeTwoPosition.first;
        iAverageFirstEyePosY[iCurrentIndex] = m_Detector->pEyeTwoPosition.second;
        
        c_Shapes.clear ( );
        c_Shapes.push_back( m_Shapes->circle ( iGetAverage(iAverageHeadPosX), iGetAverage(iAverageHeadPosY), iGetAverage( iAverageHeadSizes ) ) );
        c_Shapes.push_back( m_Shapes->blackCircle ( iGetAverage(iAverageFirstEyePosX), iGetAverage(iAverageFirstEyePosY), m_Detector->dEyeOneHeight ) );
        c_Shapes.push_back( m_Shapes->blackCircle ( iGetAverage(iAverageSecondEyePosX), iGetAverage(iAverageSecondEyePosY), m_Detector->dEyeTwoHeight ) );
        c_Shapes.push_back( m_Shapes->redCircle ( m_Detector->pSmilePossition.first, m_Detector->pSmilePossition.second, m_Detector->dSmileHeight ) );
        
        /* Un Comment Logs If Needed */
//        logXYP ( m_Detector->pSmilePossition.first, m_Detector->pSmilePossition.second, m_Detector->dSmileHeight );
//        logXYP ( m_Detector->pEyeOnePosition.first, m_Detector->pEyeOnePosition.second, m_Detector->dEyeOneHeight );
//        logXYP ( m_Detector->pEyeTwoPosition.first, m_Detector->pEyeTwoPosition.second, m_Detector->dEyeTwoHeight );

        if (iCurrentIndex > 8)
            iCurrentIndex = 0;
        else
            iCurrentIndex++;
        
        return 1;
    }
    catch (...)
    {
        return 0;
    }
}
