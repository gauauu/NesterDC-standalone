#ifndef __NES_MAPPER_111_H
#define __NES_MAPPER_111_H

#include "nes_mapper.h"

/////////////////////////////////////////////////////////////////////
// Mapper 30
class NES_mapper111 : public NES_mapper
{
public:
  ~NES_mapper111() {}
  
  void  Reset();
  void  MemoryWrite(uint32 addr, uint8 data);

protected:
private:
};
/////////////////////////////////////////////////////////////////////

#endif
