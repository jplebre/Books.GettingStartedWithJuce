/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component
{
public:
    MainContentComponent();
    void paint (Graphics&);
    
    void mouseEnter(const MouseEvent& event);
    void mouseMove(const MouseEvent& event);
    void mouseDown(const MouseEvent& event);
    void mouseDrag(const MouseEvent& event);
    void mouseUp(const MouseEvent& event);
    void mouseExit(const MouseEvent& event);
    
    void handleMouse(const MouseEvent& event);
    
private:
    String text;
    int x, y;

};


#endif  // MAINCOMPONENT_H_INCLUDED
