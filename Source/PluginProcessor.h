/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "Delayline.h"

//==============================================================================
/**
*/
class PingpongDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PingpongDelayAudioProcessor();
    ~PingpongDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	//==============================================================================

	void setDry1(float dry)  { dryMix1 = dry; }
	void setDry2(float dry) { dryMix2 = dry; }
	void setWetB1(float wet) { wetMixB1 = wet; }
	void setWetB2(float wet) { wetMixB2 = wet; }
	void setWetC1(float wet) { wetMixC1 = wet; }
	void setWetC2(float wet) { wetMixC2 = wet; }
	void setDelay(float ms) { delayLine.setDelay(ms); }

private:
    //==============================================================================
	float dryMix1  = 0.5;
	float dryMix2 = 0.5;
	float wetMixB1 = 0.5;
	float wetMixB2 = 0.5;
	float wetMixC1 = 0.5;
	float wetMixC2 = 0.5;

	jos::Delayline<float> delayLine;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PingpongDelayAudioProcessor)
};
