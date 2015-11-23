/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    addAndMakeVisible(&embeddedImage);
    setSize (embeddedImage.getWidth(), embeddedImage.getHeight());
}

MainContentComponent::~MainContentComponent()
{
    
}

void MainContentComponent::resized()
{
    embeddedImage.setBounds(0,0, getWidth(), getHeight());
}
