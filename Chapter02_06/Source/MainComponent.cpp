/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
: x(0), y(0)
{
    setSize (500, 400);
}


void MainContentComponent::paint (Graphics& g)
{
    //background
    g.fillAll (Colours::cornflowerblue);
    
    //text
    g.setColour(Colours::yellowgreen);
    g.setFont(Font (24));
    g.drawText(text,0,0,getWidth(),getHeight(),Justification::centred, false);
    
    //mousepointer
    g.setColour(Colours::yellow);
    const float radius = 10.f;
    g.fillEllipse(x-radius, y-radius, radius*2.f, radius*2.f);
}

void MainContentComponent::mouseEnter(const MouseEvent& event)
{
    text = "mouse enter";
    handleMouse(event);
}

void MainContentComponent::mouseMove(const MouseEvent& event)
{
    text = "mouse move";
    handleMouse(event);
}

void MainContentComponent::mouseDown(const MouseEvent& event)
{
    text = "mouse down";
    handleMouse(event);
}

void MainContentComponent::mouseDrag(const MouseEvent& event)
{
    text = "mouse drag";
    handleMouse(event);
}

void MainContentComponent::mouseUp(const MouseEvent& event)
{
    text = "mouse up";
    handleMouse(event);
}

void MainContentComponent::mouseExit(const MouseEvent& event)
{
    text = "mouse exit";
    handleMouse(event);
}

void MainContentComponent::handleMouse(const MouseEvent& event)
{
    x = event.x;
    y = event.y;
    repaint();
}