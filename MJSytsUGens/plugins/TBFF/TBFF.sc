TBFF : UGen {
	*ar { |input, freq = 440.0, rq = 1.0, mul = 1.0, add = 0.0|
		^this.multiNew('audio', input, freq, rq).madd(mul, add);
	}
	checkInputs {
		^this.checkValidInputs;
	}
}
