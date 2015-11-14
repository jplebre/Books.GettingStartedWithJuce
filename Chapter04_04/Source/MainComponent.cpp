/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    addAndMakeVisible(&player);
    setSize (player.getWidth(), player.getHeight());
}


void MainContentComponent::resized()
{
    player.setBounds(0, 0, getWidth(), getHeight());
}
