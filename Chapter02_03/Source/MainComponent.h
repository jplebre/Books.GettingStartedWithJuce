/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//new class, inheriting from label
//editorShown() was replaced to fit our purpose - filter illegal characters
class NumericalLabel : public Label
{
public:
    void editorShown(TextEditor* editor)
    {
        editor -> setInputRestrictions(0, "-0123456789.");
    }
};


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component,
                                public Button::Listener,
                                public Slider::Listener,
                                public Label::Listener
{
public:
    MainContentComponent();

    void labelTextChanged(Label* label);
    void buttonClicked(Button* button);
    void sliderValueChanged(Slider* slider);
    void resized();

private:
    TextButton button1;
    Slider slider1;
    NumericalLabel label1;
    
};


#endif  // MAINCOMPONENT_H_INCLUDED
