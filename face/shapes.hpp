//
//  shapes.hpp
//  face
//
//  Created by Zoe IAMZOE.io on 1/16/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#ifndef shapes_hpp
#define shapes_hpp

#include <SFML/Graphics/CircleShape.hpp>

class Shapes
{
public:
    sf::CircleShape circle ( int iXPos, int iYPos, int iRadios );
    sf::CircleShape blackCircle ( int iXPos, int iYPos, int iRadios );
    sf::CircleShape redCircle ( int iXPos, int iYPos, int iRadios );
};

#endif /* shapes_hpp */
