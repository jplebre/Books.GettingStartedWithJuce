/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent() : readFileButton("Read Image File..."),
                                                writeFileButton("Write Image File...")
{
    brightnessSlider.setRange(0.0, 10.0);
    
    addAndMakeVisible(&brightnessSlider);
    addAndMakeVisible(&writeFileButton);
    addAndMakeVisible(&readFileButton);
    addAndMakeVisible(&imageComponent);
    
    readFileButton.addListener (this);
    writeFileButton.addListener(this);
    brightnessSlider.addListener(this);
    
    setSize (500, 400);
}


void MainContentComponent::resized()
{
    int controlHeight = 20;
    int margin = 10;
    int width = getWidth() - margin*2;
    
    readFileButton.setBounds(margin, margin, width, controlHeight);
    imageComponent.setBounds(margin, readFileButton.getBottom() + margin, width, getHeight() - (controlHeight + margin) * 3 - margin*2);
    brightnessSlider.setBounds(margin, imageComponent.getBottom() + margin, width, controlHeight);
    writeFileButton.setBounds(margin, brightnessSlider.getBottom() + margin, width, controlHeight);
}


void MainContentComponent::buttonClicked(Button* button)
{
    if (&readFileButton == button)
    {
        FileChooser chooser ("Choose an image file to display...");
        
        if (chooser.browseForFileToOpen())
        {
            origImage = ImageFileFormat::loadFrom(chooser.getResult());
            
            if(origImage.isValid())
                procImage = origImage.createCopy();
                imageComponent.setImage(procImage);
        }
        else if (&writeFileButton == button)
        {
            if(procImage.isValid())
            {
                FileChooser chooser ("Write processed image to file...");
                
                if (chooser.browseForFileToSave(true))
                {
                    FileOutputStream stream (chooser.getResult());
                    PNGImageFormat pngImageFormat;
                    pngImageFormat.writeImageToStream(procImage, stream);
                }
            }
        }
    }
}

void MainContentComponent::sliderValueChanged(Slider* slider)
{
    if(&brightnessSlider == slider)
    {
        if (origImage.isValid() && procImage.isValid())
        {
            const float amount = (float)brightnessSlider.getValue();
            
            if(amount == 0.0f)
                procImage = origImage.createCopy();
            else
            {
                for(int v=0; v<origImage.getHeight(); ++v)
                {
                    for(int h=0; h<origImage.getWidth(); ++h)
                    {
                        Colour col = origImage.getPixelAt(h, v);

                        if (amount > 0.f)
                            procImage.setPixelAt(h,v,col.brighter(amount));
                        else if (amount < 0.0f)
                            procImage.setPixelAt(h, v, col.darker(-amount));
                        
                    }
                }
            }
            
            imageComponent.repaint();

        }
    }
}