/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class MainContentComponent   : public Component
{
public:
    MainContentComponent();
    ~MainContentComponent();

    void resized();

private:
    //Better to use OwnedArray than Array
    //OwnedArray is a JUCE library array that stores pointers
    //It also takes charge of deleting them when they become unused
    OwnedArray<TextButton>buttons;
};


#endif  // MAINCOMPONENT_H_INCLUDED
