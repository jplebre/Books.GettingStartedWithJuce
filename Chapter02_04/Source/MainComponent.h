#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"



class MainContentComponent   : public Component,
                                public Button::Listener
{
public:
    MainContentComponent();

    void resized();
    
    void buttonClicked(Button* button);
    
    class AltLookAndFeel : public LookAndFeel_V2
    {
    public:
        AltLookAndFeel()
        {
            setColour(Slider::thumbColourId, Colours::red);
        }
    };

private:
    Slider slider1;
    Slider slider2;
    ToggleButton toggle1;
    AltLookAndFeel altLookAndFeel;
};
#endif  // MAINCOMPONENT_H_INCLUDED
