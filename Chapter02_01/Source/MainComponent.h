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
    MainContentComponent()
    : button1("Click!!"),
    label1("label1", "info")
    {
        slider1.setRange(0.0, 100.0);
        addAndMakeVisible(&slider1);
        addAndMakeVisible(&label1);
        addAndMakeVisible(&button1);
        setSize(250, 100);
    }
    
    void resized()
    {
        //setting placement of a component with setBounds(pos w, pos h, size w, size h);
        //button1.setBounds(getWidth()/2 - 25, getHeight()/2 - 10, 50, 20);
        
        slider1.setBoundsRelative(0.05, 0.35, 0.90, 0.25);
        button1.setBoundsRelative(0.05, 0.05, 0.90, 0.25);
        label1.setBoundsRelative(0.05, 0.65, 0.90, 0.25);
    }
    
private:
    TextButton button1;
    Slider slider1;
    Label label1;
};


#endif  // MAINCOMPONENT_H_INCLUDED
