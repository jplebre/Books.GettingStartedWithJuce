/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (200, 200);
}


void MainContentComponent::paint (Graphics& g)
{
    Random& r (Random::getSystemRandom());
    g.fillAll(Colours::cornflowerblue);
    
    const float lineThickness = r.nextFloat() * 5.f  + 1.f;
    
    //declaring a path
    Path path;
    path.startNewSubPath(r.nextFloat() * getWidth(), r.nextFloat() * getHeight());
    
    for(int i = 0; i < 20; ++i)
    {        
        //draw paths:
        path.lineTo(r.nextFloat() * getWidth(), r.nextFloat() * getHeight());
        
        g.setColour(Colour (r.nextFloat(), r.nextFloat(), r.nextFloat(), r.nextFloat()));

        //Draw random lines
        /*
        const float startX = r.nextFloat()* getWidth();
        const float startY = r.nextFloat()* getHeight();
        const float endX = r.nextFloat()* getWidth();
        const float endY = r.nextFloat()* getHeight();
        
        g.drawLine(startX, startY, endX, endY, lineThickness);
        */
        
        //Draw random rectangles
        /*
        const int width = r.nextInt (getWidth() /4);
        const int height = r.nextInt (getHeight() / 4);
        const int left = r.nextInt(getWidth() - width);
        const int top = r.nextInt(getHeight() - height);
        
        g.fillRect(left, top, width, height);
         */
    }
    
    //more path stuff:
    g.setColour(Colour (r.nextFloat(), r.nextFloat(), r.nextFloat(), r.nextFloat()));
    g.strokePath(path, PathStrokeType(lineThickness));
    
}

