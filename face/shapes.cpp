//
//  shapes.cpp
//  face
//
//  Created by Zoe IAMZOE.io on 1/16/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include "shapes.hpp"

sf::CircleShape Shapes::circle ( int iXPos, int iYPos, int iRadios )
{
    sf::CircleShape csTmpCircle;
    
    csTmpCircle.setRadius( iRadios );
    csTmpCircle.setOutlineThickness( 0 );
    csTmpCircle.setFillColor( sf::Color::Yellow );
    csTmpCircle.setPosition( iXPos, iYPos );
    
    return csTmpCircle;
}

sf::CircleShape Shapes::blackCircle ( int iXPos, int iYPos, int iRadios )
{
    sf::CircleShape csTmpCircle;
    
    csTmpCircle.setRadius( iRadios );
    csTmpCircle.setOutlineThickness( 0 );
    csTmpCircle.setFillColor( sf::Color::Blue );
    csTmpCircle.setPosition( iXPos, iYPos );
    
    return csTmpCircle;
}

sf::CircleShape Shapes::redCircle ( int iXPos, int iYPos, int iRadios )
{
    sf::CircleShape csTmpCircle;
    
    csTmpCircle.setRadius( iRadios );
    csTmpCircle.setOutlineThickness( 0 );
    csTmpCircle.setFillColor( sf::Color::Red );
    csTmpCircle.setPosition( iXPos, iYPos );
    
    return csTmpCircle;
}
