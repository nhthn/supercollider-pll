PLL : UGen {
	*ar { |input, algorithm = 0, k = 0.999, centerFreq = 440, freqGain = 440|
		^this.multiNew('audio', input, algorithm, k, centerFreq, freqGain);
	}
}
