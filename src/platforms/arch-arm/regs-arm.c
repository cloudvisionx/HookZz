/**
 *    Copyright 2017 jmpews
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "regs-arm.h"

void zz_arm_register_describe(arm_reg reg, ZzArmRegInfo *ri) {
    if (reg >= ARM_REG_R0 && reg <= ARM_REG_R12) {
        ri->width = 32;
        ri->meta = ZZ_ARM_R0 + (reg - ARM_REG_R0);
    } else if (reg == ARM_REG_R13 || reg == ARM_REG_SP) {
        ri->width = 32;
        ri->meta = ZZ_ARM_R13;
    } else if (reg == ARM_REG_R14 || reg == ARM_REG_LR) {
        ri->width = 32;
        ri->meta = ZZ_ARM_R14;
    } else if (reg == ARM_REG_PC) {
        ri->width = 32;
        ri->meta = ZZ_ARM_R15;
    } else {
        Serror("zz_arm64_register_describe error.");
#if defined(DEBUG_MODE)
        debug_break();
#endif
        ri->index = 0;
    }
    ri->index = ri->meta - ZZ_ARM_R0;
}
