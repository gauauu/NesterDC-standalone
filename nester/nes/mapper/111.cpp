#include "types.h"
#include "nes.h"
#include "nes_mapper.h"
#include "111.h"

/////////////////////////////////////////////////////////////////////
// Mapper 111
void NES_mapper111::Reset()
{
  // set CPU bank pointers
  //set_CPU_banks(0,1,2,3);
  set_CPU_banks(0,1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);
}

void NES_mapper111::MemoryWrite(uint32 addr, uint8 data)
{

  //real UNROM512 can often have bus conflicts.
  //we're not going to try to emulate those here.

  uint8 prg = data & 0x1f;
  uint8 chr = (data & 0x60) >> 5;

  prg &= num_8k_ROM_banks-1;
  set_CPU_banks(prg*2,(prg*2)+1,num_8k_ROM_banks-2,num_8k_ROM_banks-1);

  uint8 c = chr * 8;
  for (int i = 0; i < 8; i++) {
    set_VRAM_bank0(i, i + c);
  }
  return;
}


/*
  if (!(
      (addr >= 0x5000) && (addr <= 0x5fff) ||
      (addr >= 0x7000) && (addr <= 0x7fff)
      )) {
      return;
  }
  */
  /*
  The register is mapped to the CPU addresses $5000-$5FFF and $7000-$7FFF
  7  bit  0
---- ----
GRNC PPPP
|||| ||||
|||| ++++- Select 32 KB PRG ROM bank for CPU $8000-$FFFF
|||+------ Select 8 KB CHR RAM bank for PPU $0000-$1FFF
||+------- Select 8 KB nametable for PPU $2000-$3EFF
|+-------- Red LED - 0=On; 1=Off
+--------- Green LED - 0=On; 1=Off
   */
/*
  uint8 prg = data & 0x0f;
  uint8 chr = (data & 0x10) >> 4;
  uint8 nt = (data & 0x20) >> 5;

  set_CPU_banks(prg*4,(prg*4)+1, prg * 4 + 2, prg * 4 + 3);

  uint8 c = chr * 8;
  for (int i = 0; i < 8; i++) {
    set_VRAM_bank0(i, i + c);
  }

 */

  //TODO: bank nametables
//}
/////////////////////////////////////////////////////////////////////

