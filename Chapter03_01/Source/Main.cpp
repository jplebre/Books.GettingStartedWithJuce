/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
int main (int argc, char* argv[])
{

    Logger *log = Logger::getCurrentLogger();
    log->writeToLog("JUCE String and Mutability:");
    String string1 = "Hello";
    String string2 = string1;
    
    string1<<" World!";
    
    log->writeToLog(string1);
    log->writeToLog(string2);
    
    string1 = "Now for something completely different";
    log->writeToLog(string1);
    log->writeToLog(string2);
    
    string2<<" Part2";
    log->writeToLog(string1);
    log->writeToLog(string2);
    
    //--------------------------------------------------------------------------
    
    log->writeToLog("\nJUCE String and concatonations:");
    String hello ("hello");
    String world ("World");
    String space (" ");
    String message = hello + space + world;
    log->writeToLog(message);
    
    String message2;
    message2 << hello;
    message2 << space;
    message2 << world;
    
    log->writeToLog(message2);
    
    String message3;
    message3 << hello << space << world;
    log->writeToLog(message3);
    
    //--------------------------------------------------------------------------

    log->writeToLog("\nMeasuring and displaying time:");
    Time now = Time::getCurrentTime();                //miliseconds from Jan 1st 1970
    int64 nowMs = Time::currentTimeMillis();          //miliseconds from Jan 1st 1970
    uint64 counterMs = Time::getMillisecondCounter(); //miliseconds from system startup
    log->writeToLog("time now is: " + now.toString(true, true));
    
    //--------------------------------------------------------------------------

    log->writeToLog("\nFormatting Time strings");
    Time time = Time::getCurrentTime();
    RelativeTime oneHourOffset = RelativeTime::hours(1);
    Time timeInOneHour (time+oneHourOffset);
    
    String timeStr;
    
    bool threeLetterMonthName = true;
    
    timeStr << time.getDayOfMonth() << " ";
    timeStr << time.getMonthName(threeLetterMonthName) << " ";
    timeStr << time.getYear() << " ";
    timeStr << time.getHours() << ":";
    timeStr << time.getMinutes() << ":";
    timeStr << time.getSeconds();
    
    log -> writeToLog("The Time is: "+ timeStr);
    log -> writeToLog("The Time in Spain is: " + timeInOneHour.toString(true, true, true, true));
    
    //--------------------------------------------------------------------------
    //Notice that this is susceptible to the user changing system time
    //For more accuracy use getCurrentTimeCounter()
    
    log->writeToLog("\nComparing time:");
    Time rightNow = Time::getCurrentTime();
    Time trigger = Time(rightNow+RelativeTime(5.0));
    
    log->writeToLog("The time is now: "+ rightNow.toString(true, true));
    
    while(Time::getCurrentTime() < trigger)
    {
        Thread::sleep(10);
        log->writeToLog("waiting....");
    }
    log->writeToLog("Time has reached: " + trigger.toString(true, true));
    
    //--------------------------------------------------------------------------

    double start = Time::getMillisecondCounterHiRes();
    
    log->writeToLog("The time is now: "+ String(start) + "ms");
    
    float value = 0.0f;
    const int N = 1000;
    
    for (int i = 0; i < N; ++i)
        value += 0.1f;
    
    double duration = Time::getMillisecondCounterHiRes() - start;
    
    log->writeToLog("Time taken to perform " +String(N)+" aditions was: " + String(duration)+"ms");
    
    //--------------------------------------------------------------------------
    

    log->writeToLog("\nCreating, writing and reading to/from a file:");
    
    String text ("The quick brown fox jumps over the lazy dog!");
    File file ("./chapter03_01_test.txt");
    file.replaceWithText(text);
    String fileText = file.loadFileAsString();
    
    log->writeToLog(fileText);
    
    //--------------------------------------------------------------------------
    // Using Special Location, like currentExecutableFile and userDesktopDirectory
    
    log->writeToLog("\nCreating, writing and reading to/from a file with special directories:");
    
    String text2 ("The quick brown fox jumps over the lazy dog!");
    
    File exe (File::getSpecialLocation(File::currentExecutableFile));
    File exeDir (exe.getParentDirectory());
    
    File file2 (exeDir.getChildFile("chapter03_01_test02.txt"));
    
    /* this could also be done in a single call:
    File file (File::getSpecialLocation(File::currentExecutableFile).getParentDirectory().getChildFile("name.txt");
    */
    
    file2.replaceWithText(text2);
    String fileText2 = file2.loadFileAsString();
    
    log->writeToLog(fileText2);
    
    
    //--------------------------------------------------------------------------
    
    log->writeToLog("\nObtaining information from files:");
    
    bool file2Exists = file2.exists();
    
    if (!file2Exists){
        log->writeToLog("file " + file2.getFileName() + " does not exist!");
        return -1;
    }
    
    Time creationTime = file2.getCreationTime();
    Time modificationTime = file2.getLastModificationTime();
    int64 fileSize = file2.getSize();
    
    log->writeToLog("file " + file2.getFileName() + " info:");
    log->writeToLog("created: " + creationTime.toString(true,true));
    log->writeToLog("modified: " + modificationTime.toString(true, true));
    log->writeToLog("size: " + String(fileSize) + " bytes.");
    log->writeToLog("directory: " + file2.getFullPathName());
    
    //--------------------------------------------------------------------------
    
    log->writeToLog("\nDirectory structures:");
    
    File root (File::getSpecialLocation(File::userDesktopDirectory)
               .getChildFile("Chapter03_01_DirectoryTest"));
    File dir1 (root.getChildFile("1"));
    File dir2 (root.getChildFile("2"));
    File dir1a (dir1.getChildFile("a"));
    File dir2b (dir2.getChildFile("b"));
    
    Result result = Result::ok();
    
    result = dir1a.createDirectory();
    
    if(!result.wasOk()){
        log->writeToLog("creating directory dir 1/a failed");
        return -1;
    }
    
    result = dir2b.createDirectory();
    
    if(!result.wasOk()){
        log->writeToLog("creating directory dir 2/b failed");
        return -1;
    }
    
    File rel = dir1a.getChildFile("../../2/b");
    
    log->writeToLog("root: " + root.getFullPathName());
    log->writeToLog("dir1: " + dir1.getRelativePathFrom(root));
    log->writeToLog("dir2: " + dir2.getRelativePathFrom(root));
    log->writeToLog("dir1a: " + dir1a.getRelativePathFrom(root));
    log->writeToLog("dir2b: " + dir2b.getRelativePathFrom(root));
    log->writeToLog("relative path: " + rel.getRelativePathFrom(root));
    
    
    return 0;
}
