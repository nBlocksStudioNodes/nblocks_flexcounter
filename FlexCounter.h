#ifndef __NB_FLEXCOUNTER
#define __NB_FLEXCOUNTER

#include "nworkbench.h"

class nBlock_FlexCounter: public nBlockSimpleNode<0> {

public:
    flexCounter(uint32_t maxvalue, uint32_t minvalue, uint32_t step, uint32_t mode);
    void triggerInput(nBlocks_Message message);
	void endFrame();
};
	   
private:
	uint32_t _count;
	uint8_t  _direction;
    uint32_t newValueFLAG;	
};

#endif