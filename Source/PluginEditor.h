/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PingpongDelayAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    PingpongDelayAudioProcessorEditor (PingpongDelayAudioProcessor&);
    ~PingpongDelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PingpongDelayAudioProcessor& processor;

	Slider delayMs;
	Slider dryMix1;
	Slider dryMix2;
	Slider wetMixB1;
	Slider wetMixB2;
	Slider wetMixC1;
	Slider wetMixC2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingpongDelayAudioProcessorEditor)
};
