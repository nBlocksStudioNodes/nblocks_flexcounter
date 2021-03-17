#include "FlexCounter.h"

nBlock_FlexCounter::nBlock_flexCounter(uint32_t maxvalue, uint32_t minvalue, uint32_t step, uint32_t mode){
	_count = minvalue;
	_direction = 1
}

void nBlock_FlexCounter::triggerInput(uint32_t inputNumber, uint32_t value){
	if(mode == 0) {
		_count = count + step;
		if(_count >= maxvalue) _count = minvalue;
	}
	
	if(mode == 1) {
		_count = count - step;
		if(_count =< minvalue) _count = maxvalue;
	}

	if(mode == 2) {
		if(_direction == 1) {
			_count = count + step;
			if(_count >= maxvalue) {
				_count = maxvalue;
				_direction = 0;
			}				
		}
		if(_direction == 0) {
			_count = count - step;
			if(_count =< minvalue) {
				_count = minvalue;
				_direction = 1;
			}
		}

	}
	newValueFLAG = 1;
}	

void nBlock_FlexCounter::endFrame(void) {
	if(newValueFLAG){
		newValueFLAG = 0;
		output[0] = _count;
		available[0] = 1;
	}	
}
