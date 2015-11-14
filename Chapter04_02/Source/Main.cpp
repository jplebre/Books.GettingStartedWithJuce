/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

void writeFile (File const& file);
void readFile (File const& file);

//==============================================================================
int main (int argc, char* argv[])
{
    File file (File::getSpecialLocation(File::currentExecutableFile).getParentDirectory().getChildFile("chapter04_02_test.bin"));
    
    writeFile(file);
    readFile(file);
    
    return 0;
}


void writeFile(File const& file)
{
    Logger *log = Logger::getCurrentLogger();
    FileOutputStream stream (file);
    
    if(!stream.openedOk())
    {
        log->writeToLog("failed to open stream");
        return;
    }
    
    stream.setPosition(0);
    stream.truncate();
    
    stream.writeInt(1234);
    stream.writeFloat(3.142);
    stream.writeDouble(0.00001234);
}


void readFile(File const& file)
{
    Logger *log = Logger::getCurrentLogger();
    FileInputStream stream(file);
    
    if(!stream.openedOk())
    {
        log->writeToLog("failed to open stream");
        return;
    }
    
    log->writeToLog("readInt: " + String(stream.readInt()));
    log->writeToLog("readFloat: " + String(stream.readFloat()));
    log->writeToLog("readDouble: " + String(stream.readDouble()));
}