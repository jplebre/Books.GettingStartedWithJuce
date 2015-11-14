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
class MainContentComponent   : public Component,
                                public Slider::Listener,
                                public Label::Listener
{
public:
    MainContentComponent();

    void resized();
    
    void sliderValueChanged(Slider* slider);
    void labelTextChanged(Label* label);

private:
    OwnedArray<Slider> sliders;
    OwnedArray<Label> labels;

};


#endif  // MAINCOMPONENT_H_INCLUDED
