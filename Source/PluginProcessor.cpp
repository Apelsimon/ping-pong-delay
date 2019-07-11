/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PingpongDelayAudioProcessor::PingpongDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

PingpongDelayAudioProcessor::~PingpongDelayAudioProcessor()
{
}

//==============================================================================
const String PingpongDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PingpongDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PingpongDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PingpongDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PingpongDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PingpongDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PingpongDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PingpongDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String PingpongDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void PingpongDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PingpongDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	constexpr float InitDelayMs = 200;
	constexpr float MaxDelayMs = 2000;

	delayLine.init(2, MaxDelayMs, sampleRate, samplesPerBlock);
	delayLine.setDelay(InitDelayMs);
}

void PingpongDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PingpongDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PingpongDelayAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
	const auto totNumSamples = buffer.getNumSamples();
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	const auto readDataL = buffer.getReadPointer(0);
	const auto readDataR = buffer.getReadPointer(1);
	auto writeDataL = buffer.getWritePointer(0);
	auto writeDataR = buffer.getWritePointer(1);

	for (auto sample = 0; sample < totNumSamples; ++sample)
	{
		const auto xnL = readDataL[sample];
		const auto xnR = readDataR[sample];
		const auto xnzL = delayLine.get(0);
		const auto xnzR = delayLine.get(1);
		
		const auto inL = a * xnL + b * xnzR;
		const auto inR = a * xnR + b * xnzL;
		delayLine.put(0, inL);
		delayLine.put(1, inR);

		writeDataL[sample] = xnL + c * inL;
		writeDataR[sample] = xnR + c * inR;
	}

}

//==============================================================================
bool PingpongDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PingpongDelayAudioProcessor::createEditor()
{
    return new PingpongDelayAudioProcessorEditor (*this);
}

//==============================================================================
void PingpongDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PingpongDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PingpongDelayAudioProcessor();
}
