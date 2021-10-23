PLL : UGen {
	*ar { |input, algorithm = 0, lag = 0.1, centerFreq = 440, freqGain = 440|
		^this.multiNew('audio', input, algorithm, lag, centerFreq, freqGain);
	}
}
