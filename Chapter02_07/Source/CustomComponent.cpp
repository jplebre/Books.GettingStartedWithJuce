/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "CustomComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CustomComponent::CustomComponent ()
{
    addAndMakeVisible (volume1 = new Slider ("volume1"));
    volume1->setRange (0, 100, 0);
    volume1->setSliderStyle (Slider::LinearHorizontal);
    volume1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    volume1->addListener (this);

    addAndMakeVisible (volume2 = new Slider ("volume2"));
    volume2->setRange (0, 100, 0);
    volume2->setSliderStyle (Slider::LinearHorizontal);
    volume2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    volume2->addListener (this);

    addAndMakeVisible (volume3 = new Slider ("volume3"));
    volume3->setRange (0, 100, 0);
    volume3->setSliderStyle (Slider::LinearHorizontal);
    volume3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    volume3->addListener (this);

    addAndMakeVisible (resetButton = new TextButton ("resetButton"));
    resetButton->setButtonText (TRANS("Reset Sliders"));
    resetButton->addListener (this);

    addAndMakeVisible (toggleStyle = new ToggleButton ("toggleStyle"));
    toggleStyle->setButtonText (TRANS("Change Slider Style"));
    toggleStyle->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 200);


    //[Constructor] You can add your own custom stuff here..
    styleToggle = false;
    volume1->setValue(75.0, sendNotification);
    volume2->setValue(75.0, sendNotification);
    volume3->setValue(75.0, sendNotification);

    volume1->setColour(Slider::thumbColourId, Colours::red);
    volume2->setColour(Slider::thumbColourId, Colours::red);
    volume3->setColour(Slider::thumbColourId, Colours::red);

    //[/Constructor]
}

CustomComponent::~CustomComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    volume1 = nullptr;
    volume2 = nullptr;
    volume3 = nullptr;
    resetButton = nullptr;
    toggleStyle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CustomComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CustomComponent::resized()
{
    volume1->setBounds (32, 24, 312, 24);
    volume2->setBounds (32, 56, 312, 24);
    volume3->setBounds (32, 88, 312, 24);
    resetButton->setBounds (32, 128, 150, 24);
    toggleStyle->setBounds (200, 128, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CustomComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volume1)
    {
        //[UserSliderCode_volume1] -- add your slider handling code here..
        //[/UserSliderCode_volume1]
    }
    else if (sliderThatWasMoved == volume2)
    {
        //[UserSliderCode_volume2] -- add your slider handling code here..
        //[/UserSliderCode_volume2]
    }
    else if (sliderThatWasMoved == volume3)
    {
        //[UserSliderCode_volume3] -- add your slider handling code here..
        //[/UserSliderCode_volume3]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void CustomComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == resetButton)
    {
        //[UserButtonCode_resetButton] -- add your button handler code here..
        volume1->setValue(75.0, sendNotification);
        volume2->setValue(75.0, sendNotification);
        volume3->setValue(75.0, sendNotification);
        //[/UserButtonCode_resetButton]
    }
    else if (buttonThatWasClicked == toggleStyle)
    {
        //[UserButtonCode_toggleStyle] -- add your button handler code here..

        if(styleToggle == false)
        {
            volume1->setSliderStyle(Slider::SliderStyle::LinearBar);
            volume2->setSliderStyle(Slider::SliderStyle::LinearBar);
            volume3->setSliderStyle(Slider::SliderStyle::LinearBar);
            styleToggle = true;
        }
        else
        {
            volume1->setSliderStyle (Slider::LinearHorizontal);
            volume2->setSliderStyle (Slider::LinearHorizontal);
            volume3->setSliderStyle (Slider::LinearHorizontal);
            styleToggle = false;
        }
        
        //[/UserButtonCode_toggleStyle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CustomComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="volume1" id="822ec7abba49d3cd" memberName="volume1" virtualName=""
          explicitFocusOrder="0" pos="32 24 312 24" min="0" max="100" int="0"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="volume2" id="3b3b738bffed4f8d" memberName="volume2" virtualName=""
          explicitFocusOrder="0" pos="32 56 312 24" min="0" max="100" int="0"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="volume3" id="3c7b85151437dff4" memberName="volume3" virtualName=""
          explicitFocusOrder="0" pos="32 88 312 24" min="0" max="100" int="0"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="resetButton" id="7e8ce116432bd124" memberName="resetButton"
              virtualName="" explicitFocusOrder="0" pos="32 128 150 24" buttonText="Reset Sliders"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="toggleStyle" id="ad8adff0397311fb" memberName="toggleStyle"
                virtualName="" explicitFocusOrder="0" pos="200 128 150 24" buttonText="Change Slider Style"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
