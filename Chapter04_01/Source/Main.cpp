/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

void writeFile(File const& file);
void readFile(File const& file);

//==============================================================================
int main (int argc, char* argv[])
{
    File file (File::getSpecialLocation(File::currentExecutableFile).getParentDirectory().getChildFile("chapter04_01_test.txt"));
    
    writeFile(file);
    readFile(file);

    return 0;
}



void writeFile(File const& file)
{
    Logger *log = Logger::getCurrentLogger();
    FileOutputStream stream(file);
    
    if(!stream.openedOk())
    {
        log->writeToLog("Failed to open stream");
        return;
    }
    
    stream.setPosition(0);
    stream.truncate();
    
    String text ("The quick brown fox jumps over the lazy dog.");
    
    bool asUTF16 = false;
    bool byteOrderMark = false;
    stream.writeText(text, asUTF16, byteOrderMark);
    
}

void readFile(File const& file)
{
    Logger *log = Logger::getCurrentLogger();
    FileInputStream stream(file);
    
    if(!stream.openedOk())
    {
        log->writeToLog("Failed to open stream");
        return;
    }
    
    log -> writeToLog("fileText: " + stream.readEntireStreamAsString());
}