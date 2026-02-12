/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdint.h>

int main()
{
  uint32_t x,y,z;
  uint32_t px,py,pz;
  x = 0x01020304;
  y = 0x01010101;
  z = 0;
  px = (uint32_t) &x;
  py = (uint32_t) &y;
  pz = (uint32_t) &z;

  asm volatile("add t0, zero, %0" ::"r"(px));
  asm volatile("add t1, zero, %0" ::"r"(py));
  asm volatile("add t2, zero, %0" ::"r"(pz));
  // asm volatile("lw t3, 0x0(t0)");

  // asm volatile(".word 0xdeadbeef\n");
  
  // xifu load x
  asm volatile(".word 0x0042805B\n");
  asm volatile("xor zero, zero, zero");

  // xifu load y
  asm volatile(".word 0x000300DB\n");
  asm volatile("xor zero, zero, zero");

  // xifu dotp 
  asm volatile(".word 0x0010215B\n");
  asm volatile("xor zero, zero, zero");

  // xifu store
  asm volatile(".word 0x082392DB\n");
  asm volatile("xor zero, zero, zero");
  // asm volatile(".word ");


  printf("Hello %08x!\n", z);
}
