/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    for (int i=0; i<10; ++i)
    {
        String indexString (i);
        String sliderName ("Slider " + indexString);
        Slider* slider = new Slider(sliderName);
        slider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
        slider->addListener(this);
        sliders.add(slider);
        addAndMakeVisible(slider);
        
        String labelName("label " + indexString);
        Label* label = new Label(labelName, String (slider->getValue()));
        label->setEditable(true);
        label->addListener(this);
        labels.add(label);
        addAndMakeVisible(label);
    }
    
    setSize (500, 400);
}


void MainContentComponent::resized()
{
    Rectangle<int>slidersRect(10,10,getWidth()/2-20, getHeight()-20);
    Rectangle<int>labelsRect(slidersRect.getRight(), 10, getWidth()/2-20, getHeight()-20);
    int cellHeight = slidersRect.getHeight()/sliders.size();
    
    for (int i=0; i<sliders.size(); ++i)
    {
        sliders[i] -> setBounds(slidersRect.getX(), i*cellHeight+slidersRect.getY(), slidersRect.getWidth(), cellHeight);
        labels[i] -> setBounds(labelsRect.getX(), i*cellHeight+labelsRect.getY(), labelsRect.getWidth(), cellHeight);
    }
}

void MainContentComponent::sliderValueChanged(Slider* slider)
{
    int index = sliders.indexOf(slider);
    labels[index] ->setText(String(slider->getValue()), sendNotification);
}

void MainContentComponent::labelTextChanged(Label* label)
{
    int index = labels.indexOf(label);
    sliders[index] ->setValue(label ->getText().getDoubleValue());
}
