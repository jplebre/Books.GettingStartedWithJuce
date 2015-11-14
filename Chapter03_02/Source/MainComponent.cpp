/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    for (int i = 0; i <10; ++i)
    {
        String buttonName;
        buttonName << "Button " << String (i);
        TextButton* button = new TextButton (buttonName);
        buttons.add (button);
        addAndMakeVisible(button);
    }
    
    setSize (500, 400);

}

MainContentComponent::~MainContentComponent()
{
}


void MainContentComponent::resized()
{
    Rectangle<int>rect (10,10, getWidth() - 20, getHeight() - 20);
    int buttonHeight = rect.getHeight() / buttons.size();
    for (int i = 0; i < buttons.size(); ++i)
    {
        buttons[i] -> setBounds (rect.getX(), i * buttonHeight + rect.getY(), rect.getWidth(), buttonHeight);
    }
}
