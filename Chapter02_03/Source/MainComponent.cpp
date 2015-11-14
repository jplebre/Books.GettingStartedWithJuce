/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
: button1("Zero Slider"),
slider1(Slider::LinearHorizontal, Slider::NoTextBox)
{
    //Set listeners
    slider1.addListener(this);
    label1.addListener(this);
    button1.addListener(this);
    
    //Preferences
    slider1.setRange(0.0, 100.0);
    slider1.setValue(75.0, sendNotification); //default startup value
    label1.setEditable(true);
    
    //add buttons and make visible
    addAndMakeVisible(&button1);
    addAndMakeVisible(&slider1);
    addAndMakeVisible(&label1);
    
    
    setSize (200, 100);
}

void MainContentComponent::sliderValueChanged(Slider* slider)
{
    if (&slider1 == slider)
        label1.setText(String(slider1.getValue()), sendNotification);
}

void MainContentComponent::buttonClicked(Button* button)
{
    if (&button1 == button)
        slider1.setValue(0.0, sendNotification);
}

void MainContentComponent::labelTextChanged(Label* label)
{
    if (&label1 == label)
    {
        slider1.setValue(label1.getText().getDoubleValue(), sendNotification); //clips input before sending message
        label1.setText(String(slider1.getValue()), dontSendNotification); //updates text to reflect clipped input
    }
}

void MainContentComponent::resized()
{
    slider1.setBoundsRelative(0.05, 0.05, 0.90, 0.25);
    button1.setBoundsRelative(0.05, 0.35, 0.90, 0.25);
    label1.setBoundsRelative(0.05, 0.65, 0.90, 0.25);
}

