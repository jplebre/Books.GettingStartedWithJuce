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

#include "MediaPlayer.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MediaPlayer::MediaPlayer ()
{
    addAndMakeVisible (stopButton = new TextButton ("stop"));
    stopButton->setButtonText (TRANS("Stop"));
    stopButton->addListener (this);
    stopButton->setColour (TextButton::buttonColourId, Colours::red);

    addAndMakeVisible (settingsButton = new TextButton ("settings"));
    settingsButton->setButtonText (TRANS("Audio Settings..."));
    settingsButton->addListener (this);

    addAndMakeVisible (openButton = new TextButton ("open"));
    openButton->setButtonText (TRANS("Open File..."));
    openButton->addListener (this);

    addAndMakeVisible (playButton = new TextButton ("play"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);
    playButton->setColour (TextButton::buttonColourId, Colours::green);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    playButton->setEnabled(false);
    stopButton->setEnabled(false);

    formatManager.registerBasicFormats();

    sourcePlayer.setSource(&transportSource);
    deviceManager.addAudioCallback(&sourcePlayer);
    deviceManager.initialise(0, 2, nullptr, true);


    //setting up listeners
    deviceManager.addChangeListener(this);
    transportSource.addChangeListener(this);
    state = Stopped;

    //[/Constructor]
}

MediaPlayer::~MediaPlayer()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    stopButton = nullptr;
    settingsButton = nullptr;
    openButton = nullptr;
    playButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MediaPlayer::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MediaPlayer::resized()
{
    stopButton->setBounds (8, 72, getWidth() - 16, 24);
    settingsButton->setBounds (8, 104, getWidth() - 16, 24);
    openButton->setBounds (8, 8, getWidth() - 16, 24);
    playButton->setBounds (8, 40, getWidth() - 16, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MediaPlayer::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == stopButton)
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
        if (Paused == state)
        {
            changeState(Stopped);
        }
        else
            changeState(Stopping);


        //[/UserButtonCode_stopButton]
    }
    else if (buttonThatWasClicked == settingsButton)
    {
        //[UserButtonCode_settingsButton] -- add your button handler code here..
        bool showMidiInputOptions = false;
        bool showMidiOutputSelector = false;
        bool showChannelsAsStereoPairs = true;
        bool hideAdvancedOptions = false;

        AudioDeviceSelectorComponent settings(deviceManager, 0, 0, 1, 2, showMidiInputOptions, showMidiOutputSelector, showChannelsAsStereoPairs, hideAdvancedOptions);

        settings.setSize(500, 400);

        DialogWindow::showModalDialog(String ("Audio Settings"), &settings, TopLevelWindow::getTopLevelWindow(0), Colours::white, true);

        //[/UserButtonCode_settingsButton]
    }
    else if (buttonThatWasClicked == openButton)
    {
        //[UserButtonCode_openButton] -- add your button handler code here..
        FileChooser chooser("Select a Wave file to Play: ", File::nonexistent, "*.wav");

        if(chooser.browseForFileToOpen())
        {
            File file (chooser.getResult());
            readerSource = new AudioFormatReaderSource(formatManager.createReaderFor(file), true);
            transportSource.setSource(readerSource);
            playButton->setEnabled(true);
        }

        //[/UserButtonCode_openButton]
    }
    else if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        if ((Stopped == state) || (Paused == state))
        {
            changeState(Starting);
        }
        else if (Playing == state)
        {
            changeState(Pausing);
        }

        //[/UserButtonCode_playButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MediaPlayer::changeListenerCallback(ChangeBroadcaster* src)
{
    if(&deviceManager == src)
    {
        AudioDeviceManager::AudioDeviceSetup setup;
        deviceManager.getAudioDeviceSetup(setup);

        if(setup.outputChannels.isZero())
            sourcePlayer.setSource(nullptr);
        else
            sourcePlayer.setSource(&transportSource);
    }
    else if(&transportSource == src)
    {
        if (transportSource.isPlaying())
            changeState(Playing);
        else
        {
            if ((Stopping == state) || (Playing== state))
                changeState(Stopped);
            else if (Pausing == state)
                changeState(Paused);
        }
    }
}


void MediaPlayer::changeState(TransportState newState)
{
    if(state != newState)
    {
        state = newState;
        switch (state)
        {
            case Stopped:
                playButton->setButtonText("Play");
                stopButton->setButtonText("Stop");
                stopButton->setEnabled(false);
                transportSource.setPosition(0.0);
                break;
            case Starting:
                transportSource.start();
                break;
            case Playing:
                playButton->setButtonText("Pause");
                stopButton->setButtonText("Stop");
                stopButton->setEnabled(true);
                break;
            case Pausing:
                transportSource.stop();
                break;
            case Paused:
                playButton->setButtonText("Resume");
                stopButton->setButtonText("Return to Zero");
                break;
            case Stopping:
                transportSource.stop();
                break;
        }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MediaPlayer" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="stop" id="749eab8bcad77321" memberName="stopButton" virtualName=""
              explicitFocusOrder="0" pos="8 72 16M 24" bgColOff="ffff0000"
              buttonText="Stop" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="settings" id="3294846abd4028e9" memberName="settingsButton"
              virtualName="" explicitFocusOrder="0" pos="8 104 16M 24" buttonText="Audio Settings..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="open" id="54661b0574df2cc5" memberName="openButton" virtualName=""
              explicitFocusOrder="0" pos="8 8 16M 24" buttonText="Open File..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="play" id="ca9210a7334aa470" memberName="playButton" virtualName=""
              explicitFocusOrder="0" pos="8 40 16M 24" bgColOff="ff008000"
              buttonText="Play" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
