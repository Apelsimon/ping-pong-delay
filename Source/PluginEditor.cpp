/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PingpongDelayAudioProcessorEditor::PingpongDelayAudioProcessorEditor (PingpongDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	addAndMakeVisible(delayMs);
	delayMs.setRange(0, 2000, 1);
	delayMs.setValue(200);
	delayMs.setTextValueSuffix(" ms");
	delayMs.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	delayMs.onValueChange = [this]() { processor.setDelay(delayMs.getValue()); };

	addAndMakeVisible(dryMix1);
	dryMix1.setRange(0, 1, 0.05);
	dryMix1.setValue(0.5);
	dryMix1.setTextValueSuffix(" dry mix1");
	dryMix1.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	dryMix1.onValueChange = [this]() { processor.setDry1(dryMix1.getValue()); };

	addAndMakeVisible(dryMix2);
	dryMix2.setRange(0, 1, 0.05);
	dryMix2.setValue(0.5);
	dryMix2.setTextValueSuffix(" dry mix2");
	dryMix2.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	dryMix2.onValueChange = [this]() { processor.setDry2(dryMix2.getValue()); };

	addAndMakeVisible(wetMixB1);
	wetMixB1.setRange(0, 1, 0.05);
	wetMixB1.setValue(0.5);
	wetMixB1.setTextValueSuffix(" wet mix B1");
	wetMixB1.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	wetMixB1.onValueChange = [this]() { processor.setWetB1(wetMixB1.getValue()); };

	addAndMakeVisible(wetMixB2);
	wetMixB2.setRange(0, 1, 0.05);
	wetMixB2.setValue(0.5);
	wetMixB2.setTextValueSuffix(" wet mix B2");
	wetMixB2.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	wetMixB2.onValueChange = [this]() { processor.setWetB2(wetMixB2.getValue()); };

	addAndMakeVisible(wetMixC1);
	wetMixC1.setRange(0, 1, 0.05);
	wetMixC1.setValue(0.5);
	wetMixC1.setTextValueSuffix(" wet mix C1");
	wetMixC1.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	wetMixC1.onValueChange = [this]() { processor.setWetC1(wetMixC1.getValue()); };

	addAndMakeVisible(wetMixC2);
	wetMixC2.setRange(0, 1, 0.05);
	wetMixC2.setValue(0.5);
	wetMixC2.setTextValueSuffix(" wet mix C2");
	wetMixC2.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	wetMixC2.onValueChange = [this]() { processor.setWetC2(wetMixC2.getValue()); };
}

PingpongDelayAudioProcessorEditor::~PingpongDelayAudioProcessorEditor()
{
}

//==============================================================================
void PingpongDelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void PingpongDelayAudioProcessorEditor::resized()
{
	auto locBounds = getLocalBounds();
	const auto componentWidth = locBounds.getWidth() / 7.0;

	delayMs.setBounds(locBounds.removeFromLeft(componentWidth));
	dryMix1.setBounds(locBounds.removeFromLeft(componentWidth));
	dryMix2.setBounds(locBounds.removeFromLeft(componentWidth));
	wetMixB1.setBounds(locBounds.removeFromLeft(componentWidth));
	wetMixB2.setBounds(locBounds.removeFromLeft(componentWidth));
	wetMixC1.setBounds(locBounds.removeFromLeft(componentWidth));
	wetMixC2.setBounds(locBounds.removeFromLeft(componentWidth));
}
